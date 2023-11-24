# Loop Unrolling Benchmark


## Description
This is a simple example that uses Google Benchmark to measure the performance between with loop unrolling and without loop unrolling.

## Requirements
* Install CMake
* Install Google Benchmark ([Refer to installation instructions](https://github.com/google/benchmark#installation))

## Steps to Run:
```
# Clone respository
$ git clone git@github.com:zhangcongrong/loop_unrolling_benchmark.git
$ cd loop_unrolling_benchmark
# Create a build directory
$ mkdir build && cd build
# Generate Makefiles using CMake
$ cmake ..
# Build the project
$ cmake --build .
# Run the benchmark executable
$ ./loop_unrolling_benchmark
```
