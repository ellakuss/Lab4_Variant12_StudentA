# Контракт бібліотеки Combinatorics (Студент А, варіант 12)

Версія API: 1.0. Платформа: Windows x64, MSVC, C++20. DLL: Combinatorics.dll.
Бібліотека експортує 4 функції з `extern "C"` і повертає `unsigned long long`.
Допустимі аргументи: `0 <= n <= 20`; де є k: `0 <= k <= n`.
При будь-якому некоректному аргументі повертається `ULLONG_MAX` (18446744073709551615ULL), який не є коректним результатом на визначеному діапазоні.
Бібліотека не виділяє динамічної пам'яті, не змінює аргументів, не потребує ініціалізації та не використовує глобального стану.

- `unsigned long long factorial(int n)` — n!, при n=0 повертає 1.
- `unsigned long long permutations(int n)` — кількість перестановок n різних елементів, P(n)=n!.
- `unsigned long long combinations(int n, int k)` — кількість сполучень без повторень, C(n,k)=n!/(k!(n-k)!).
- `unsigned long long arrangements(int n, int k)` — кількість розміщень без повторень, A(n,k)=n!/(n-k)!.

Приклади: factorial(5)=120, permutations(5)=120, combinations(5,2)=10, arrangements(5,2)=20.
Граничні випадки: factorial(0)=1, combinations(5,0)=1, arrangements(5,0)=1, combinations(5,5)=1; factorial(-1), combinations(3,4), factorial(21) повертають ULLONG_MAX.

Для неявного зв'язування потрібні `include/Combinatorics.h`, `lib/Combinatorics.lib` на етапі збирання та `bin/Combinatorics.dll` біля exe під час запуску.
Для явного зв'язування потрібна лише DLL; використовуйте `LoadLibraryW`, `GetProcAddress` із точними іменами `factorial`, `permutations`, `combinations`, `arrangements`, потім `FreeLibrary`.
Збірки DLL та застосунку повинні мати сумісну архітектуру (x64).
