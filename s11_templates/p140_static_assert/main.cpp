#include <iostream>

int main() {
    //static_assert(sizeof(void*)==4, "Compile in 32-bit mode only");
    static_assert(sizeof(void*)==8, "compile in 64-bit mode only");
    return 0;
}