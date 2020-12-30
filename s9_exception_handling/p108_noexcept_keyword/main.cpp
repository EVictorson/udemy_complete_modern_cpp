#include <iostream>

void Test(int x) noexcept(false) {
    std::cout<<"Test: "<< x <<std::endl;
    throw x;
}

int Sum(int x, int y) noexcept(noexcept(Test(x))) {
    Test(x);
    return x + y;
}

class A {
public:
    // destructors are implicitly noexcept(true) in C++11 onwards
    ~A() {
        // because of this implicitly noexcept(true) having destructor throw cause program to terminate
        //throw 3;
    }
};

int main() {
    A a;

    // print whether a.~A() is noexcept
    std::cout<<"~A() is noexcept: "<< std::boolalpha << noexcept(a.~A()) <<std::endl;
    try {
        Sum(3, 5);
    }
    catch (int x) {
        std::cout<<"Caught: "<< x << std::endl;
    }
}