#include "Combinatorics.h"
#include <climits>

unsigned long long factorial(int n) {
    if (n < 0 || n > 20) return ULLONG_MAX;
    unsigned long long result = 1;
    for (int i = 2; i <= n; ++i) result *= static_cast<unsigned long long>(i);
    return result;
}

unsigned long long permutations(int n) {
    return factorial(n);
}

unsigned long long combinations(int n, int k) {
    if (n < 0 || n > 20 || k < 0 || k > n) return ULLONG_MAX;
    if (k > n - k) k = n - k;
    unsigned long long result = 1;
    for (int i = 1; i <= k; ++i) {
        result = result * static_cast<unsigned long long>(n - k + i)
                 / static_cast<unsigned long long>(i);
    }
    return result;
}

unsigned long long arrangements(int n, int k) {
    if (n < 0 || n > 20 || k < 0 || k > n) return ULLONG_MAX;
    unsigned long long result = 1;
    for (int i = 0; i < k; ++i) result *= static_cast<unsigned long long>(n - i);
    return result;
}
