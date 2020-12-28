#include <iostream>

// size of union will be size of its largest member
// since it can only have one active member at a time
union Test{
    int x;
    char ch;
    double d;
    Test() : ch{'a'} {
        std::cout<<__FUNCTION__<<std::endl;
    }

    ~Test() {
        std::cout<<__FUNCTION__<<std::endl;
    }
};

int main() {
    std::cout<<"Size of Test = "<<sizeof(Test)<<std::endl;
    Test t;
    std::cout<<t.ch <<std::endl;
    t.x = 1000;
    // unions can only have one active member
    // so this will have undefined behavior
    std::cout<<t.ch<<std::endl;
}