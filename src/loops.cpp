//
// Created by matrix on 2023/11/23.
//

#include <cstdint>

#include "loops.h"

namespace loops {

    int64_t SumWithLoopUnrolling(int64_t n) {
        int64_t res = 0;
        for (int i = 0; i < n; i += 4) {
            res += i + (i + 1) + (i + 2) + (i + 3);
        }
        return res;
    }

    int64_t SumWithoutLoopUnrolling(int64_t n) {
        int64_t res = 0;
        for (int i = 0; i < n; ++i) {
            res += i;
        }
        return res;
    }

}  // namespace loops
