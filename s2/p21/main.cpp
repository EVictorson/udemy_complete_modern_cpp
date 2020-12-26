#include <iostream>
#include "math.h"

int main() {
    int a, b, ret;
    a = 4;
    b = 2;

    std::cout<<"Demonstrating Add function w/ reference."<<std::endl;
    std::cout<<"A = "<< a <<" b = "<< b <<" ret = "<< ret << std::endl;
    Add(a, b, ret);
    std::cout<<"A = "<< a <<" b = "<< b <<" ret = "<< ret << "\n"<<std::endl;

    std::cout<<"Demonstrating factorial function w/ reference."<<std::endl;
    std::cout<<"A = "<< a <<" ret = "<< ret << std::endl;
    Factorial(a, ret);
    std::cout<<"A = "<< a <<" ret = "<< ret << "\n"<<std::endl;

    std::cout<<"Demonstrating swap function w/ reference."<<std::endl;
    std::cout<<"A = "<< a <<" b = "<< b << std::endl;
    Swap(a, b);
    std::cout<<"A = "<< a <<" b = "<< b <<"\n"<<std::endl;


    return 0;
}