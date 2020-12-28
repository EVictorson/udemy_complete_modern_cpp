#include <iostream>

// returns an r-value (temporary value to be assigned to an l-value)
int Add(int x, int y) {
    return x + y;
}

// returns an l-value
int & Transform(int &x) {
    x *= x;
    return x;
}

void Print(int &x) {
    std::cout<<"Print(int&)"<<std::endl;
}

void Print(const int &x) {
    std::cout<<"Print(const int&)"<<std::endl;
}

void Print(int &&x) {
    std::cout<<"Print(int&&)"<<std::endl;
}

int main() {
    // r-value reference
    //int &&r1 = 10;
    
    // r-value reference
    //int &&r2 = Add(3, 2);

    // x is l-value
    //int x = 0;
    // cannot assign an l-value to an r-value reference
    //int &&r3 = x;

    //int &ref = Transform(x);
    //const int &ref2 = 3;


    int x = 10;
    // because x is an l-value, this will bind to print that accepts an int (lvalue) 
    Print(x);

    // temporaries always bind to r-value references
    // but they can also bind to const l-value references
    Print(3);

    return 0;
}