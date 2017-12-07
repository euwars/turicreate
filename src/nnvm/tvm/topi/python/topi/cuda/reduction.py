# pylint: disable=invalid-name,unused-variable,too-many-locals,len-as-condition
"""Schedule for reduce operators"""
from __future__ import absolute_import as _abs
import tvm
from .. import tag

def _schedule_reduce(op, sch, is_idx_reduce=False):
    if is_idx_reduce:
        data_out = op.input_tensors[0]
    else:
        data_in = op.input_tensors[0]
        data_out = op.output(0)
    assert len(sch[data_out].op.reduce_axis) > 0, "reduce_axis must be bigger than zero!"

    if len(sch[data_out].op.axis) > 0:
        all_reduce = False
        num_thread = 32
        block_x = tvm.thread_axis("blockIdx.x")
        thread_x = tvm.thread_axis((0, num_thread), "threadIdx.x")
        thread_y = tvm.thread_axis((0, num_thread), "threadIdx.y")
    else:
        all_reduce = True
        num_thread = 512
        thread_x = tvm.thread_axis((0, num_thread), "threadIdx.x")

    # Fuse and refactor the reduce axis
    fused_reduce = sch[data_out].fuse(*[sch[data_out].op.reduce_axis[i]
                                        for i in range(len(sch[data_out].op.reduce_axis))])
    ko, ki = sch[data_out].split(fused_reduce, factor=num_thread)
    if is_idx_reduce:
        data_out_rf, _ = sch.rfactor(data_out, ki)
    else:
        data_out_rf = sch.rfactor(data_out, ki)
    tx = sch[data_out].op.reduce_axis[0]
    sch[data_out].bind(tx, thread_x)
    sch[data_out_rf].compute_at(sch[data_out], tx)
    if is_idx_reduce:
        real_output = op.output(0)
        temp_idx_input = data_out.op.output(0)
        temp_val_input = data_out.op.output(1)
    else:
        real_output = data_out
    if not all_reduce:
        # Fuse and split the axis
        fused_outer = sch[real_output].fuse(*[sch[real_output].op.axis[i]
                                              for i in range(len(sch[real_output].op.axis))])
        bx, outer_in = sch[real_output].split(fused_outer, factor=num_thread)

        # Bind the axes to threads and blocks
        sch[real_output].bind(outer_in, thread_y)
        sch[real_output].bind(bx, block_x)
        if is_idx_reduce:
            sch[temp_idx_input].compute_at(sch[real_output], outer_in)
            sch[temp_val_input].compute_at(sch[real_output], outer_in)
    else:
        if is_idx_reduce:
            sch[temp_idx_input].compute_at(sch[real_output],
                                           sch[real_output].op.axis[0])
            sch[temp_val_input].compute_at(sch[real_output],
                                           sch[real_output].op.axis[0])
    sch[real_output].set_store_predicate(thread_x.equal(0))
    return sch


def schedule_reduce(outs):
    """Schedule for inject->reduce->bcast ops.

    Parameters
    ----------
    outs: Array of Tensor
          The computation graph description of reduce in the format
          of an array of tensors.

    Returns
    -------
    sch: Schedule
        The computation schedule for the op.
    """
    outs = [outs] if isinstance(outs, tvm.tensor.Tensor) else outs
    sch = tvm.create_schedule([x.op for x in outs])

    def traverse_before_reduce(operator):
        if isinstance(operator, tvm.tensor.PlaceholderOp):
            return
        elif tag.is_injective(operator.tag):
            sch[operator].compute_inline()
            for tensor in operator.input_tensors:
                traverse_before_reduce(tensor.op)
        else:
            raise RuntimeError("Unsupported operator: %s" % operator.tag)

    def traverse_after_reduce(operator):
        if tag.is_broadcast(operator.tag):
            raise RuntimeError("Not yet support ewise after reduce")
        elif operator.tag == 'comm_reduce':
            _schedule_reduce(operator, sch, is_idx_reduce=False)
            for tensor in operator.input_tensors:
                traverse_before_reduce(tensor.op)
        elif operator.tag == 'comm_reduce_idx':
            _schedule_reduce(operator, sch, is_idx_reduce=True)
            for tensor in operator.input_tensors[0].op.input_tensors:
                traverse_before_reduce(tensor.op)
        else:
            raise RuntimeError("Unsupported operator: %s" % operator.tag)

    traverse_after_reduce(outs[0].op)
    return sch
