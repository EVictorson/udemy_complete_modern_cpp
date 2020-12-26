#include <iostream>

int main() {
    int arr[] = {1,2,3,4,5};

    std::cout<<"using range based for loop"<<std::endl;
    for (auto x : arr){
        std::cout<<x<<std::endl;
    }

    auto range = arr;
    auto begin = std::begin(arr);
    auto end = std::end(arr);

    std::cout<<"using begin and end pointers."<<std::endl;
    for( ; begin != end; ++begin) {
        std::cout<<*begin<<std::endl;
        auto v = *begin;
    }

    return 0;
}