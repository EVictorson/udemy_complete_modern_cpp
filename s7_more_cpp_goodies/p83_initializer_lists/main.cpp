#include <iostream>
#include <initializer_list>
#include <cassert>

class Bag {
    int arr[10];
    int m_Size{0};
public:
    Bag() {

    }

    Bag(std::initializer_list<int> values) {
        assert(values.size() < 10);
        auto it = values.begin();
        while(it != values.end()) {
            Add(*it);
            ++it;
        }
    }
    void Add(int value) {
        assert(m_Size < 10);
        arr[m_Size++] = value;

    }

    void Remove() {
        m_Size--;
    }

    int operator [](int index) {
        return arr[index];
    }

    int GetSize()const {
        return m_Size;
    }

};

void PrintBag(Bag &bag) {
    for(int i=0; i<bag.GetSize(); ++i) {
        std::cout<<bag[i]<<" ";
    }
}

void PrintInitListIter(std::initializer_list<int> values) {
    std::cout<<"\nPrinting initalizer list with iterators."<<std::endl;
    auto it = values.begin();
    while (it != values.end()) {
        std::cout<<*it++;
    }
}

// initializer list already provides iterators so we can do this:
void PrintInitListRBF(std::initializer_list<int> values) {
    std::cout<<"\nPrinting initializer list with range based for loop."<<std::endl;
    for(auto x : values){
        std::cout<<x;
    }
}

int main() {
    // c++11 style uniform initializer
    int x{0};
    float y{3.1f};
    int arr[5]{1,2,3,4,5};
    std::string s{"HELLO"};

    // initializer list
    // initializer lists are commonly used with container classes
    std::initializer_list<int> data = {1,2,3,4};
    auto values = {1,2,3,4};

    Bag b;
    b.Add(1);
    b.Add(2);
    b.Add(3);
    std::cout<<"w/ default constructor and Add() fn"<<std::endl;
    PrintBag(b);

    std::cout<<"\nw/ parameterized constructor that accepts initializer list"<<std::endl;
    // in order for this to work we need to create a 
    // constructor that accepts an initializer list
    Bag b2{4,5,6};
    PrintBag(b2);

    PrintInitListIter({1,2,3,4,5,6});
    PrintInitListRBF({1,2,3,4,5,6,7});
    return 0;
}