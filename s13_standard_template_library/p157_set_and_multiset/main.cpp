#include <iostream>
#include <set>

void Set() {
    // set will store values in sorted order
    // by default will use comparator less (to sort in ascending order)
    std::set<int> s{8,2,0,9,5};

    std::set<int, std::greater<int>> s1{8,2,0,9,5};
    std::multiset<int, std::greater<int>> ms{8,2,0,9,5};

    s.insert(1);
    s.insert(3);
    //set does not allow duplicates, but multi_set does
    s.insert(3);
    s.insert(3);

    ms.insert(1);
    ms.insert(3);
    ms.insert(3);
    ms.insert(3);

    // cannot access through iterators with set (it's a const)
    auto itr = s.begin();

    std::cout<<"standard set (sorts w/ std::less<>)"<<std::endl;
    while (itr != s.end()) {
        std::cout<< *itr++ << " ";
    }
    std::cout<<std::endl;

    auto itr1 = s1.begin();
    std::cout<<"set w/ specified sorting function std::greater<>"<<std::endl;
    while (itr1 != s1.end()) {
        std::cout<< *itr1++ << " ";
    }

    std::cout<<std::endl;
    auto itr2 = ms.begin();
    std::cout<<"multiset sorted with greater"<<std::endl;
    while (itr2 != ms.end()) {
        std::cout<< *itr2++ << " ";
    }

    s.erase(0);
    s.erase(s.begin());

    // find will return iterator to element if it's found
    itr = s.find(9);
    std::cout<<std::endl;
    if (itr != s.end()) {
        std::cout<<"Element found"<< std::endl;
    }
    else {
        std::cout<<"Not found"<<std::endl;
    }

    // find with multiset will return the first occurance
    // to find all occurances use equal_range
    auto found = ms.equal_range(3);

    while (found.first != found.second) {
        std::cout << *found.first++<<" ";
    }




}

int main() {

    Set();
    return 0;
}