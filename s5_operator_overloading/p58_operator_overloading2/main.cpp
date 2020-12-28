#include "integer.h"
#include <iostream>
#include <memory>

// our version of a smart pointer class for integer objects
class IntPtr {
    Integer *m_p;
public:
    IntPtr(Integer *p) : m_p(p) {

    }
    ~IntPtr() {
        delete m_p;
    }

    Integer *operator ->() {
        return m_p;
    }

    Integer & operator *() {
        return *m_p;
    }
};

void CreateInteger(int x) {
    std::cout<<"Create integer"<<std::endl;
    IntPtr p = new Integer;
    (*p).SetValue(x);
}

Integer Add(const Integer &a, const Integer &b) {
    Integer temp;
    temp.SetValue(a.GetValue() + b.GetValue());
    return temp;
}

int main() {
    Integer a(1), b(3);
    Integer c;
    Integer d;
    std::cout<<"a = "<<a.GetValue()<<" b = "<<b.GetValue()<<std::endl;
    Integer sum = a + b;

    std::cout<<"sum = "<<sum.GetValue()<<std::endl;

    // overloaded pre-increment
    ++sum;
    std::cout<<"sum = "<<sum.GetValue()<<std::endl;

    // overloaded post-increment
    std::cout<<"sum = "<<(sum++).GetValue()<<std::endl;
    std::cout<<"sum = "<<sum.GetValue()<<std::endl;
    
    // overloaded comparison
    std::cout<<"a == b = "<<(a==b)<<std::endl;
    
    // copy assignment
    c = a;
    std::cout<<"c = "<<c.GetValue()<<std::endl;

    // move assignment
    d = std::move(c);
    std::cout<<"d = "<<d.GetValue()<<std::endl;
    // because we have moved c to d, trying to access values from it will cause an exception
    //std::cout<<"c = "<<c.GetValue()<<std::endl;

    Integer sum1 = a + 5; // the same as a.operator+(5)
    //Integer sum2 = 5 = a; // need to overload again differently for this
    
    std::cin>>a;
    std::cout<<a<<std::endl;
    
    CreateInteger(3);

    int x = static_cast<int>(a);

    std::cout<<"Comparing initialization to assignment:\n"<<std::endl;
    std::cout<<"Initialization: "<<std::endl;
    // initialization of object aa
    Integer aa(6);
    std::cout<<"\nAssignment: "<<std::endl;
    // assignment of 6 to object bb
    Integer bb;
    // should be performing a move or copy assign here but I don't see it doing that
    // must be some compiler trickery
    bb = 6;
    std::cout<<"\nend of comparison"<<std::endl;

    return 0;
}