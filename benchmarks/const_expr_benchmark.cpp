//
// Created by matrix on 2023/11/24.
//
#include <benchmark/benchmark.h>

constexpr int64_t CubeConstexpr(int64_t x) {
    return x * x * x;
}

int64_t Cube(int64_t x) {
    return x * x * x;
}

static void CubeWithConstexpr(benchmark::State &state) {
    for (auto _: state) {
        int64_t n = state.range(0);
        int64_t result = 0;
        for (int i = 0; i < n; ++i) {
            result += CubeConstexpr(3);
        }
        benchmark::DoNotOptimize(result);
    }
}


static void CubeWithoutConstexpr(benchmark::State &state) {
    for (auto _: state) {
        int64_t n = state.range(0);
        int64_t result = 0;
        for (int i = 0; i < n; ++i) {
            result += Cube(3);
        }
        benchmark::DoNotOptimize(result);
    }
}

BENCHMARK(CubeWithConstexpr)->Arg(10000);
BENCHMARK(CubeWithoutConstexpr)->Arg(10000);
