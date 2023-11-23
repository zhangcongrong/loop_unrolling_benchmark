//
// Created by matrix on 2023/11/23.
//

#include <benchmark/benchmark.h>
//#include <benchmark

// Function to sum numbers from 1 to n with loop unrolling
static void SumWithUnrolling(benchmark::State& state) {
    int n = state.range(0);
    int res = 0;
    for (auto _ : state) {
        for (int i = 0; i < n; i += 4) {
            res += i + (i + 1) + (i + 2) + (i + 3);
        }
    }
    benchmark::DoNotOptimize(res);
}

// Function to sum numbers from 1 to n with loop unrolling
static void SumWithoutUnrolling(benchmark::State& state) {
    int n = state.range(0);
    int res = 0;
    for (auto _ : state) {
        for (int i = 0; i < n; ++i) {
            res += i;
        }
    }
    benchmark::DoNotOptimize(res);
}

// Register the benchmarks
BENCHMARK(SumWithUnrolling)->Arg(10000); // Change argument to desired value
BENCHMARK(SumWithoutUnrolling)->Arg(10000); // Change argument to desired value

BENCHMARK_MAIN();