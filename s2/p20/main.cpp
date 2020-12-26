#include <iostream>

int main() {

    //referent
    int x = 10;

    // reference
    int &ref = x;
    std::cout<<"x = "<< x << std::endl;
    std::cout<<"ref = "<< ref << std::endl;

    int y = 20;
    ref = y;
    std::cout<<"y = "<< y << std::endl;
    std::cout<<"ref = "<< ref << std::endl;

    return 0;
}

/* Differences between references and pointers:
references always need an initializer, they're optional with pointers
references should be initialized by an l-value, that's not needed with a pointer
references cannot be null or nullptr, pointers can be
references are bound to referent, pointers can point to other variables
references do not require storage, it just captures the address of referent.  Points have their own storage and will have a different address
references do not require dereferencing,  pointers require dereferencing to access the value pointed to
*/