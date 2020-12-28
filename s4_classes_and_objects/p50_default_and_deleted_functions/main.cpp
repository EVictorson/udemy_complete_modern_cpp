#include <iostream>

class Integer{
    int m_value{0};
public:
    // explicitly ask compiler to create default constructor
    Integer() = default;
    
    /*Integer() {
        m_value = 0;
    }
    */

   Integer(int value) {
       m_value = value;
   }

    // explicitly ask compiler to create default copy constructor
    // this is unnecessary as it will do it without us asking.
    // Integer(const Integer &) = default;

    // if however, we would like to delete a function, in this case
    // the copy constructor.
    // if we want to explicitly disallow copy construction, we can delete it.
    Integer(const Integer &) = delete;

    void PrintValue() {
        std::cout<<"m_value = "<<m_value<<std::endl;
    }

    void SetValue(int value) {
        m_value = value;
    }

    // let's say we want to prevent setvalue from being called with a float
    // we can explicitly delete setvalue called with a float
    void SetValue(float) = delete;

};

int main () {
    Integer i1;
    
    // will print m_value = 0 since we have initialized it to 0 in the declaration.
    i1.PrintValue();
    
    Integer i2(3);

    i1.SetValue(5);

    // this won't compile since we've deleted setvalue that accepts a float
    //i1.SetValue(67.1);

    return 0;
}