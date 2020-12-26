// pointers
#include <iostream>

int main () {
    int x = 10;
    // print address of x
    std::cout<<"address of x = "<<&x<<std::endl;
    
    // pointer points to memory address of x
    int *ptr = &x;
    std::cout<<"memory location pointed to by ptr = "<<ptr<<std::endl;

    // dereference pointer to see value stored in memory address pointed to by pointer
    std::cout<<"value in memory location pointed to by ptr = "<<*ptr<<std::endl;

    // c++11 introduced nullptr macro to supplant NULL
    void *ptr2 = nullptr;
    std::cout<<"ptr2 assigned to nullptr = "<<ptr2<<std::endl;

    return 0;
}