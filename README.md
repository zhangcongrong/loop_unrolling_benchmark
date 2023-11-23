# Loop Unrolling Benchmark

This is a description of your project.
git submodule add git@github.com:google/benchmark.git third_party/benchmark
git submodule init
git submodule update

git submodule update --init --recursive

Steps to Run:
Create a build directory: mkdir build && cd build
Generate Makefiles using CMake: cmake ..
Build the project: cmake --build .
Run the benchmark executable: ./loop_unrolling_benchmark

commit : test the benefit of loop unrolling with google benchmark


https://github.com/google/benchmark#installation