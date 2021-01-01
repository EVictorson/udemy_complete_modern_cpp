#include <iostream>

using Comparator = bool(*)(int, int);

template<typename T, int size>
void Sort(T(&arr)[size], Comparator comp) {
    for (int i=0; i < size-1; ++i) {
        for (int j=0; j < size-1; ++j) {
            if (comp(arr[j], arr[j+1])) {
                T temp = std::move(arr[j]);
                arr[j] = std::move(arr[j+1]);
                arr[j+1] = std::move(temp);
            }
        }
    }
}

// function pointers as comparators
bool CompGT(int x, int y) {
    return x > y;
}

bool CompLT(int x, int y) {
    return x < y;
}

int main() {
    int arr[]{1,6,8,4,0};

    for (auto x: arr) {
        std::cout<<x<<" ";
    }
    std::cout<< std:: endl;

    Sort(arr, CompGT);
    for (auto x : arr) {
        std::cout<< x <<" ";
    }
    std::cout<<std::endl;


    return 0;
}