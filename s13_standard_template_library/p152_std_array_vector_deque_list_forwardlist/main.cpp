#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>

void Array() {
    std::cout<<"Array()"<<std::endl;
    std::array<int, 5> arr{3,1,8,5,9};
    for(int i=0; i<arr.size(); ++i) {
        arr[i] = i;
    }
    auto itr = arr.begin();
    for(auto x : arr) {
        std::cout<<x<<" ";
    }

    std::cout<<std::endl;

    // retrieve data to be backwards compatible with c style array
    arr.data();
}

void Vector() {
    std::cout<<"\n\nVector()"<<std::endl;
    std::vector<int> coll{1,2,3,4,5};
    for (int i=0; i<5; ++i) {
        coll.push_back( i * 10);
        std::cout<<"coll.size = "<< coll.size() << std::endl;
    }

    // cann access elements with subscript operator
    coll[0] = 100;

    for(int i = 0; i < coll.size(); ++i) {
        std::cout<< coll[i] <<" ";
    }

    // most conventional way to access elements is through iterator
    auto itr = coll.begin();
    while(itr != coll.end()) {
        std::cout<<*itr++<<" ";
    }
    std::cout<<std::endl;
    // insert element at position coll.begin()
    // performance implication is that it has to shift (assign and copy) every element
    coll.insert(coll.begin(), 700);

    //can use erase to remove an element
    coll.erase(coll.end()-5);

    // can use pop_back to pop last element
    coll.pop_back();

    itr = coll.begin();
    while(itr != coll.end()) {
        std::cout<<*itr++<<" ";
    }

}

void Deque() {
    std::cout<<"\n\nDeque()"<<std::endl;
    std::deque<int> coll{1,2,3,4,5};
    // use push_back to add element to back of deque
    for (int i=0; i<5; ++i) {
        coll.push_back( i * 10);
        std::cout<<"coll.size = "<< coll.size() << std::endl;
    }

    // use push_front to add element to front of deque
    for (int i=0; i<5; ++i) {
        coll.push_front( i * 10);
        std::cout<<"coll.size = "<< coll.size() << std::endl;
    }

    // cann access elements with subscript operator
    coll[0] = 100;

    for(int i = 0; i < coll.size(); ++i) {
        std::cout<< coll[i] <<" ";
    }

    // most conventional way to access elements is through iterator
    auto itr = coll.begin();
    while(itr != coll.end()) {
        std::cout<<*itr++<<" ";
    }
    std::cout<<std::endl;
    // insert element at position coll.begin()
    // performance implication is that it has to shift (assign and copy) every element
    coll.insert(coll.begin(), 700);

    //can use erase to remove an element
    coll.erase(coll.end()-5);

    // can use pop_back to pop last element
    coll.pop_back();

    // can use pop_front to pop the first element
    coll.pop_front();

    itr = coll.begin();
    while(itr != coll.end()) {
        std::cout<<*itr++<<" ";
    }

}

void List() {
    std::cout<<"\n\n List()"<<std::endl;
    std::list<int> coll;

    for(int i = 0; i < 5; ++i) {
        coll.push_back(i * 10);
    }

    auto itr = coll.begin();
    while (itr != coll.end()) {
        std::cout<< *itr++ << " ";
    }

    itr = coll.begin();
    // insert and erase always take constant time
    coll.insert(itr, 800);
    coll.erase(itr);
    // list is good for containers that need to add and remove elements, but not provide random access

}

void ForwardList() {
    std::cout<<"\n\n ForwardList()"<<std::endl;

    std::forward_list<int> coll;

    //forward list only hast push_front
    for(int i = 0; i < 10; ++i) {
        coll.push_front(i);
    }

    for (auto x : coll) {
        std::cout<< x << " ";
    }

    // insert element after coll.begin()
    coll.insert_after(coll.begin(), 10);
    // erase element after coll.begin()
    coll.erase_after(coll.begin());

}

int main() {

    Array();
    Vector();
    Deque();
    List();
    ForwardList();

    return 0;
}