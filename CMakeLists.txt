cmake_minimum_required(VERSION 3.26)
project(loop_unrolling_benchmark)

set(CMAKE_CXX_STANDARD 17)

include_directories(/usr/local/include)

# Find Google Benchmark package
find_package(benchmark REQUIRED)


# Add executable for the benchmark
add_executable(loop_unrolling_benchmark1 benchmarks/loop_unrolling_benchmark.cpp)


# Link Google Benchmark to the executable
target_link_libraries(loop_unrolling_benchmark1 benchmark::benchmark)


add_executable(loop_unrolling_benchmark src/main.cpp
        src/loops.h
        src/loops.cpp)
