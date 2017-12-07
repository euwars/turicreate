/* Copyright © 2017 Apple Inc. All rights reserved.
 *
 * Use of this source code is governed by a BSD-3-clause license that can
 * be found in the LICENSE.txt file or at https://opensource.org/licenses/BSD-3-Clause
 */
#ifndef __SVM_ENUMS_H
#define __SVM_ENUMS_H
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-function"
enum MLKernelkernel: int {
    MLKernelkernel_linearKernel = 1,
    MLKernelkernel_rbfKernel = 2,
    MLKernelkernel_polyKernel = 3,
    MLKernelkernel_sigmoidKernel = 4,
    MLKernelkernel_NOT_SET = 0,
};

static const char * MLKernelkernel_Name(MLKernelkernel x) {
    switch (x) {
        case MLKernelkernel_linearKernel:
            return "MLKernelkernel_linearKernel";
        case MLKernelkernel_rbfKernel:
            return "MLKernelkernel_rbfKernel";
        case MLKernelkernel_polyKernel:
            return "MLKernelkernel_polyKernel";
        case MLKernelkernel_sigmoidKernel:
            return "MLKernelkernel_sigmoidKernel";
        case MLKernelkernel_NOT_SET:
            return "INVALID";
    }
}

enum MLSupportVectorRegressorsupportVectors: int {
    MLSupportVectorRegressorsupportVectors_sparseSupportVectors = 2,
    MLSupportVectorRegressorsupportVectors_denseSupportVectors = 3,
    MLSupportVectorRegressorsupportVectors_NOT_SET = 0,
};

static const char * MLSupportVectorRegressorsupportVectors_Name(MLSupportVectorRegressorsupportVectors x) {
    switch (x) {
        case MLSupportVectorRegressorsupportVectors_sparseSupportVectors:
            return "MLSupportVectorRegressorsupportVectors_sparseSupportVectors";
        case MLSupportVectorRegressorsupportVectors_denseSupportVectors:
            return "MLSupportVectorRegressorsupportVectors_denseSupportVectors";
        case MLSupportVectorRegressorsupportVectors_NOT_SET:
            return "INVALID";
    }
}

enum MLSupportVectorClassifiersupportVectors: int {
    MLSupportVectorClassifiersupportVectors_sparseSupportVectors = 3,
    MLSupportVectorClassifiersupportVectors_denseSupportVectors = 4,
    MLSupportVectorClassifiersupportVectors_NOT_SET = 0,
};

static const char * MLSupportVectorClassifiersupportVectors_Name(MLSupportVectorClassifiersupportVectors x) {
    switch (x) {
        case MLSupportVectorClassifiersupportVectors_sparseSupportVectors:
            return "MLSupportVectorClassifiersupportVectors_sparseSupportVectors";
        case MLSupportVectorClassifiersupportVectors_denseSupportVectors:
            return "MLSupportVectorClassifiersupportVectors_denseSupportVectors";
        case MLSupportVectorClassifiersupportVectors_NOT_SET:
            return "INVALID";
    }
}

enum MLSupportVectorClassifierClassLabels: int {
    MLSupportVectorClassifierClassLabels_stringClassLabels = 100,
    MLSupportVectorClassifierClassLabels_int64ClassLabels = 101,
    MLSupportVectorClassifierClassLabels_NOT_SET = 0,
};

static const char * MLSupportVectorClassifierClassLabels_Name(MLSupportVectorClassifierClassLabels x) {
    switch (x) {
        case MLSupportVectorClassifierClassLabels_stringClassLabels:
            return "MLSupportVectorClassifierClassLabels_stringClassLabels";
        case MLSupportVectorClassifierClassLabels_int64ClassLabels:
            return "MLSupportVectorClassifierClassLabels_int64ClassLabels";
        case MLSupportVectorClassifierClassLabels_NOT_SET:
            return "INVALID";
    }
}

#pragma clang diagnostic pop
#endif
