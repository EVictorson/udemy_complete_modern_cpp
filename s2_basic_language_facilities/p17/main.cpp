// uniform initialization w/ c++11

#include <iostream>
#include <string>

int main() {
    int a1; // uninitialized
    int a2 = 0; // copy initialization?
    int a3(5); // direct initialization
    
    std::string s1;
    std::string s2("C++"); //Direct initialization

    char d[8] = {'a', 'b', 'c', 'd'}; //Aggregate initialization


    // Moving on to c++11 uniform initialization
    // always use uniform initialization for non-built in types
    int b1{};   //value initialization (defaults to 0)
    std::cout<<"b1 = "<<b1<<std::endl;
    int b2(); // Most Vexing Parse (because it creates a function b2 that takes a void and returns int)
    int b3{5}; // direct initialization

    char e1[8]{};

    // create value on heap that's default initialized to 0
    int *p1 = new int{};

    char*p2 = new char[8]{};

}

/* types of initialization
1. value initialization => T obj{};
2. Direct initialization => T obj{v};
3. copy initialization => T obj = v;


*/