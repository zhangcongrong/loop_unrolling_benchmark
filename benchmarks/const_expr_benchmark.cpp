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
        int64_t result = CubeConstexpr(state.range(0));
        benchmark::DoNotOptimize(result);
    }
}


static void CubeWithoutConstexpr(benchmark::State &state) {
    for (auto _: state) {
        int64_t result = Cube(state.range(0));
        benchmark::DoNotOptimize(result);
    }
}

BENCHMARK(CubeWithConstexpr)->Arg(1005);
BENCHMARK(CubeWithoutConstexpr)->Arg(1005);
