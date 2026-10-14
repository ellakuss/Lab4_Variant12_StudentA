#include <iostream>
#include <climits>
#include "Combinatorics.h"

int main() {
    std::cout << "Student A: IMPLICIT DLL linking\n";
    std::cout << "factorial(5) = " << factorial(5) << '\n';
    std::cout << "permutations(5) = " << permutations(5) << '\n';
    std::cout << "combinations(5,2) = " << combinations(5,2) << '\n';
    std::cout << "arrangements(5,2) = " << arrangements(5,2) << '\n';
    std::cout << "factorial(21): " << (factorial(21) == ULLONG_MAX ? "ERROR" : "UNEXPECTED") << '\n';
}
