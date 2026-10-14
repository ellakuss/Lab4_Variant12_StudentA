#include <iostream>
#include <climits>
#include "Combinatorics.h"

int main() {
    std::cout << "Student A, variant 12: STATIC library\n";
    std::cout << "factorial(5) = " << factorial(5) << " (expected 120)\n";
    std::cout << "permutations(5) = " << permutations(5) << " (expected 120)\n";
    std::cout << "combinations(5,2) = " << combinations(5,2) << " (expected 10)\n";
    std::cout << "arrangements(5,2) = " << arrangements(5,2) << " (expected 20)\n";
    std::cout << "factorial(0) = " << factorial(0) << " (expected 1)\n";
    std::cout << "combinations(4,0) = " << combinations(4,0) << " (expected 1)\n";
    std::cout << "invalid factorial(-1) = "
              << (factorial(-1) == ULLONG_MAX ? "ERROR (as expected)" : "UNEXPECTED") << '\n';
}
