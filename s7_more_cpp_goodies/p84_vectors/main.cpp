#include <iostream>
#include <vector>

void PrintVec(std::vector<int> &v) {
    for (auto x : v) {
        std::cout<< x <<" ";
    }
}

int main() {
    std::vector<int> v{1,2,3};
    v.push_back(4);

    // Access
    // access is performed with subscript operator which is already overloaded for vector class
    v[0] = 100;
    for(int i = 0; i < v.size(); ++i) {
        std::cout<<v[i]<<" ";
    }

    // or, even better, use a range based for loop
    std::cout<<"\nprint w/ range based for loop"<<std::endl;
    for(auto x : v) {
        std::cout<< x <<" ";
    }

    // Delete
    auto it = v.begin();
    v.erase(it);
    std::cout<<"\ndeleting first element"<<std::endl;
    PrintVec(v);


    // Insert
    std::cout<<"\nInsert 100 back in at beginning of vector"<<std::endl;
    it = v.begin();
    v.insert(it, 100);
    PrintVec(v);
    return 0;
}