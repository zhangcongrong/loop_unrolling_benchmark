//
// Created by matrix on 2023/11/23.
//

#include <benchmark/benchmark.h>

#include "../src/loops.h"

// Sum numbers from 1 to n with loop unrolling
static void SumWithUnrolling(benchmark::State &state) {
    int64_t n = state.range(0);
    int64_t res = 0;
    for (auto _: state) {
        res = loops::SumWithLoopUnrolling(n);
    }
    benchmark::DoNotOptimize(res);
}

// Sum numbers from 1 to n with loop unrolling
static void SumWithoutUnrolling(benchmark::State &state) {
    int64_t n = state.range(0);
    int64_t res = 0;
    for (auto _: state) {
        res = loops::SumWithoutLoopUnrolling(n);
    }
    benchmark::DoNotOptimize(res);
}

// Register the benchmarks
BENCHMARK(SumWithUnrolling)->Arg(10000); // Change argument to desired value
BENCHMARK(SumWithoutUnrolling)->Arg(10000); // Change argument to desired value

BENCHMARK_MAIN();