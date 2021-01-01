#include <iostream>

template<typename T>
struct Unnamed {
    int operator()(T x, T y) const {
        return x + y;
    }
};

int main() {
    // fn is just a function object instance
    auto fn = []() {
        std::cout<<"Welcome to lambda expressions"<<std::endl;
    };

    fn();
    std::cout<<typeid(fn).name()<<std::endl;

    // lambda expression with trailing return type specification
    // can also apply template methodology to lambda expressions using auto 
    // auto sum = [](int x, int y) -> int
    auto sum = [](auto x, auto y) {
        return x + y;
    };

    std::cout<<"sum ints = "<<sum(1,3)<<std::endl;
    std::cout<<"sum floats = "<<sum(5.5f, 2.2f)<<std::endl;

    // the above sum lambda expression is the same as the function object
    // except the compiler implicitly creates the function object
    Unnamed<int> n;
    std::cout<<"Sum fcn object = "<<n(1,3)<<std::endl;

    return 0;
}