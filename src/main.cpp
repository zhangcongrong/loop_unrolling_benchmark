#include <iostream>

#include "loops.h"


int main() {
    int64_t n = 10000; // Change n to a desired value

    int64_t sum =  loops::SumWithLoopUnrolling(n);
    std::cout << "Sum with loop unrolling: " << sum << std::endl;

    sum =  loops::SumWithoutLoopUnrolling(n);
    std::cout << "Sum without loop unrolling: " << sum << std::endl;

    return 0;
}
