#pragma once

#ifdef COMBI_EXPORTS
#define COMBI_API extern "C" __declspec(dllexport)
#elif defined(COMBI_IMPORTS)
#define COMBI_API extern "C" __declspec(dllimport)
#else
#define COMBI_API extern "C"
#endif

// Return ULLONG_MAX on invalid input. Allowed n: 0..20; k: 0..n.
COMBI_API unsigned long long factorial(int n);
COMBI_API unsigned long long permutations(int n);
COMBI_API unsigned long long combinations(int n, int k);
COMBI_API unsigned long long arrangements(int n, int k);
