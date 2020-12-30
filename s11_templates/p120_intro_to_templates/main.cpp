#include <iostream>

// motivation:
// instead of overriding a bunch of functions that accept different types
// we can create a function template
/*
int Max(int x, int y) {
    return x > y ? x : y;
}
float Max(float x, float y) {
    return x > y ? x : y;
}
*/

template<typename T>
T Max(T x, T y){
    return x > y ? x : y;
}

int main() {
    auto num = Max(3.3f, 5.8f);
    std::cout << num << std::endl;
    auto num2 = Max(38, 12);
    std::cout << num2 << std::endl;

    return 0;
}