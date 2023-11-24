//
// Created by matrix on 2023/11/24.
//
#include <benchmark/benchmark.h>
#include <unordered_map>
#include <vector>


struct alignas(64) AlignedData {
    int x;
    double y;
};

constexpr int DATA_SIZE = 10000;

int gArrayData[DATA_SIZE];

AlignedData gAlignedData[DATA_SIZE];

std::unordered_map<int, int> gMapData;


// Access array, aiming to maintain locality and sequential access as much as possible.
static void LocalityInAccessingArray(benchmark::State &state) {
    for (auto _: state) {
        for (int i = 0; i < DATA_SIZE; ++i) {
            gArrayData[i] = i;
        }
        benchmark::DoNotOptimize(gArrayData);
    }
}

// Preloading data that might be accessed to reduce cache misses
static void PreloadingDataFromArray(benchmark::State &state) {
    for (auto _: state) {
        for (int i = 0; i < DATA_SIZE - 1; ++i) {
            gArrayData[i] += 3;
            int temp = gArrayData[i + 1];  // preloading
        }
        benchmark::DoNotOptimize(gArrayData);
    }
}

// Access data according to the cache line size (1024)
static void CacheOptimizedData(benchmark::State &state) {
    for (auto _: state) {
        for (int i = 0; i < DATA_SIZE; i += 16) {
            // Access 16 elements at a time, utilizing cache block size.
            gAlignedData[i].x = i;
            gAlignedData[i].y = i * 2.1;
        }
        benchmark::DoNotOptimize(gArrayData);
    }
}

// Use better data structures to reduce conflicting data access
static void ReduceCacheAccessConflicts(benchmark::State &state) {
    for (auto _: state) {
        for (int i = 0; i < DATA_SIZE; ++i) {
            gMapData.insert({i, i * 2});
        }
        benchmark::DoNotOptimize(gArrayData);
    }
}

BENCHMARK(LocalityInAccessingArray);
BENCHMARK(PreloadingDataFromArray);
BENCHMARK(CacheOptimizedData);
BENCHMARK(ReduceCacheAccessConflicts);
