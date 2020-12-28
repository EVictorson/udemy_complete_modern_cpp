#include "integer.h"
#include <iostream>
#include <memory>

void Display(Integer *p) {
    if(!p) {
        return;
    }
    std::cout<<"p->GetValue() = "<<p->GetValue()<<std::endl;
}

// factory method
Integer* GetPointer(int value) {
    Integer *p = new Integer{value};
    return p;
}

void Store(std::unique_ptr<Integer> &p) {
    std::cout<<"mock storing data to a file: "<<p->GetValue()<<std::endl;
}

void Operate(int value) {
    std::unique_ptr<Integer> p{GetPointer(value)};
    if(p==nullptr) {
        p.reset(new Integer{value});
    }
    p->SetValue(100);
    
    // call display with p.get() to get the underylying pointer
    Display(p.get());
    // use reset to destroy the object currently managed by the unique_ptr 
    // and take ownership of the pointer
    // below, we destroy the old Integer pointer and replaces it with a new one
    p.reset(new Integer{});

    // store the line number in the pointer
    std::cout<<"which constructor is called here?"<<std::endl;
    // should be a copy assignment, but will get optimized by compiler
    // to be just a parameterized constructor
    *p = __LINE__;
    std::cout<<"which constructor was called?"<<std::endl;
    Display(p.get());
    Store(p);
}

int main() {
    Operate(5);
    return 0;
}