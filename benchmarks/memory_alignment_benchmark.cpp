//
// Created by matrix on 2023/11/24.
//
#include <benchmark/benchmark.h>
#include <vector>
#include <iostream>

struct alignas(64) IntDoubleAlignedData {
    int x;
    double y;
};

struct IntDoubleUnalignedData {
    int x;
    double y;
};

struct alignas(16) IntCharAlignedData {
    int x;
    char y;
};  // sizeof(IntDoubleAlignedData) = 16

struct IntCharUnalignedData {
    int x;
    char y;
};  // sizeof(IntCharUnalignedData) = 8

static void MemoryAlignedOfIntDoubleData(benchmark::State& state) {
    for (auto _ : state) {
        std::vector<IntDoubleAlignedData> data(state.range(0));
        for (auto& d : data) {
            d.x = 13;
            d.y = 0.001;
        }
        benchmark::DoNotOptimize(data);
    }
}

static void MemoryUnalignedOfIntDoubleData(benchmark::State& state) {
    for (auto _ : state) {
        std::vector<IntDoubleUnalignedData> data(state.range(0));
        for (auto& d : data) {
            d.x = 13;
            d.y = 0.001;
        }
        benchmark::DoNotOptimize(data);
    }
}

static void MemoryAlignedOfIntCharData(benchmark::State& state) {
    for (auto _ : state) {
        std::vector<IntCharAlignedData> data(state.range(0));
        for (auto& d : data) {
            d.x = 13;
            d.y = 'c';
        }
        benchmark::DoNotOptimize(data);
    }
}

static void MemoryUnalignedOfIntCharData(benchmark::State& state) {
    for (auto _ : state) {
        std::vector<IntCharUnalignedData> data(state.range(0));
        for (auto& d : data) {
            d.x = 13;
            d.y = 'c';
        }
        benchmark::DoNotOptimize(data);
    }
}

BENCHMARK(MemoryAlignedOfIntDoubleData)->Arg(1000);
BENCHMARK(MemoryUnalignedOfIntDoubleData)->Arg(1000);

BENCHMARK(MemoryAlignedOfIntCharData)->Arg(1000);
BENCHMARK(MemoryUnalignedOfIntCharData)->Arg(1000);