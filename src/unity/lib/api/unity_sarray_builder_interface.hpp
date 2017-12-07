/* Copyright © 2017 Apple Inc. All rights reserved.
 *
 * Use of this source code is governed by a BSD-3-clause license that can
 * be found in the LICENSE.txt file or at https://opensource.org/licenses/BSD-3-Clause
 */
#ifndef TURI_UNITY_SARRAY_BUILDER_INTERFACE_HPP
#define TURI_UNITY_SARRAY_BUILDER_INTERFACE_HPP
#include <vector>
#include <flexible_type/flexible_type.hpp>
#include <cppipc/magic_macros.hpp>

namespace turi {

class unity_sarray_base;

GENERATE_INTERFACE_AND_PROXY(unity_sarray_builder_base, unity_sarray_builder_proxy,
      (void, init, (size_t)(size_t)(flex_type_enum))
      (void, append, (const flexible_type&)(size_t))
      (void, append_multiple, (const std::vector<flexible_type>&)(size_t))
      (flex_type_enum, get_type, )
      (std::vector<flexible_type>, read_history, (size_t)(size_t))
      (std::shared_ptr<unity_sarray_base>, close, )
    )

} // namespace turi

#endif //TURI_UNITY_SARRAY_BUILDER_INTERFACE_HPP
#include <unity/lib/api/unity_sarray_interface.hpp>
