#include <iostream>
#include <type_traits>

template<typename T>
T Divide(T a, T b) {
    // can also use a static_assert to perform introspection at compile time:
    //static_assert(std::is_floating_point<T>::value, "only floating point supported");
    
    // use type_trait for introspection to determine if we can perform division
    if(std::is_floating_point<T>::value == false) {
        std::cout<<"Use floating point types only"<<std::endl;
        return 0;
    }
    return a / b;
} 

template<typename T>
void Check(T&&) {
    std::cout<<std::boolalpha;
    std::cout<<"Is reference? "<<std::is_reference<T>::value<<std::endl;

    std::cout<<"After removing: "<<
        std::is_reference<typename std::remove_reference<T>::type>::value <<std::endl;

}


int main() {
    std::cout<<std::boolalpha
    << "Is integer? " << std::is_integral<int>::value << std::endl;

    std::cout<<Divide(5,2)<<std::endl;

    Check(5);
    int value{};
    Check(value);

}