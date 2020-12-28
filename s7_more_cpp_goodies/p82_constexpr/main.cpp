#include <iostream>

// constant expression function
// evaluated at compile time
constexpr int GetNumber() {
    return 42;
}

// x and y both need to be literals in order for this to compile
constexpr int Add(int x, int y) {
    return x + y;
}

constexpr int Max(int x, int y) {
    return x > y ? x : y;
}

int main() {
    // behaves as a constexpr function
    // evaluated at compile time
    // without constexpr this would be evaluated at run-time
    constexpr int i = GetNumber();
    int arr[i];

    // behaves as a constexpr function
    const int j  = GetNumber();
    int arr1[j];

    // behaves as a normal function
    // evaluated at run-time
    int x = GetNumber();

    // behaves as constexpr function
    // evaluated at compile time
    constexpr int sum = Add(3,5);

    // behaves as nor

    return 0;
}
/* constant expression function rules

1. should accept and return literal types only
    (void, scalar types (int, float, char), references, etc)
2. should contain only single line statement that is a return statement
3. C++14 onwards allows multiple return statements  and conditional statments for a constexpr
4. all constexprs are implicitly inline 
    meaning you have to write constexpr's like an inline (in a header file)
*/

