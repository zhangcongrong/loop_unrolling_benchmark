//
// Created by matrix on 2023/11/23.
//

#include "loops.h"

namespace loops {

    int SumWithLoopUnrolling(int n) {
        int res = 0;
        for (int i = 0; i < n; i += 4) {
            res += i + (i + 1) + (i + 2) + (i + 3);
        }
        return res;
    }

    int SumWithoutLoopUnrolling(int n) {
        int res = 0;
        for (int i = 0; i < n; ++i) {
            res += i;
        }
        return res;
    }

}  // namespace loops
