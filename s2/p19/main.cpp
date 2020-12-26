#include <iostream>
#include "math.h"

int main() {
    int x{1};
    int y{5};
    int z{0};

    int *ptrx = &x;
    int *ptry = &y;
    int *ptrz = &z;

    std::cout<<"Demonstrating the add function."<<std::endl;
    int ret = Add(ptrx, ptry);
    std::cout<<"Ret = "<< ret <<"\n"<<std::endl;

    std::cout<<"Demonstrating the addval function."<<std::endl;
    std::cout<<"Value of z before call = "<<z<<std::endl;
    AddVal(ptrx, ptry, ptrz);
    std::cout<<"Value of z after call = "<<z<<"\n"<<std::endl;

    std::cout<<"Demonstrating the swap function."<<std::endl;
    std::cout<<"Before call: x = "<<x<<" and y = "<<y<<std::endl;
    Swap(ptrx, ptry);
    std::cout<<"After call: x = "<<x<<" and y = "<<y<<"\n"<<std::endl;


    std::cout<<"Demonstrating the factorial function."<<std::endl;
    Factorial(ptrx, ptrz);
    std::cout<<"Factorial output = "<<z<<std::endl;

    return 0;
}