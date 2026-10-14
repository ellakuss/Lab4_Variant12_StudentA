#include <iostream>
#include <windows.h>

using OneArgFn = unsigned long long (*)(int);
using TwoArgFn = unsigned long long (*)(int, int);

int main() {
    HMODULE dll = LoadLibraryW(L"Combinatorics.dll");
    if (!dll) { std::cerr << "Cannot load Combinatorics.dll\n"; return 1; }
    auto factorialFn = reinterpret_cast<OneArgFn>(GetProcAddress(dll, "factorial"));
    auto permutationsFn = reinterpret_cast<OneArgFn>(GetProcAddress(dll, "permutations"));
    auto combinationsFn = reinterpret_cast<TwoArgFn>(GetProcAddress(dll, "combinations"));
    auto arrangementsFn = reinterpret_cast<TwoArgFn>(GetProcAddress(dll, "arrangements"));
    if (!factorialFn || !permutationsFn || !combinationsFn || !arrangementsFn) {
        std::cerr << "Cannot find exported functions\n";
        FreeLibrary(dll);
        return 2;
    }
    std::cout << "Student A: EXPLICIT DLL linking\n";
    std::cout << "factorial(5) = " << factorialFn(5) << '\n';
    std::cout << "permutations(5) = " << permutationsFn(5) << '\n';
    std::cout << "combinations(5,2) = " << combinationsFn(5,2) << '\n';
    std::cout << "arrangements(5,2) = " << arrangementsFn(5,2) << '\n';
    FreeLibrary(dll);
    return 0;
}
