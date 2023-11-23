#include <iostream>

#include "loops.h"



int main() {
    int n = 10000; // Change n to desired value

    int sum =  loops::SumWithLoopUnrolling(n);
    std::cout << "Sum without loop unrolling: " << sum << std::endl;

    sum =  loops::SumWithoutLoopUnrolling(n);
    std::cout << "Sum without loop unrolling: " << sum << std::endl;

    return 0;
}
