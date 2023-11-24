//
// Created by matrix on 2023/11/23.
//

#ifndef LOOP_UNROLLING_BENCHMARK_LOOPS_H
#define LOOP_UNROLLING_BENCHMARK_LOOPS_H

namespace loops {

    // Function to sum numbers from 1 to n with loop unrolling
    int64_t SumWithLoopUnrolling(int64_t n);

    // Function to sum numbers from 1 to n without loop unrolling
    int64_t SumWithoutLoopUnrolling(int64_t n);

}  // namespace loops

#endif //LOOP_UNROLLING_BENCHMARK_LOOPS_H
