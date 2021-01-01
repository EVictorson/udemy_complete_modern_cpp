#include <iostream>

template<int size>
void Print() {
    char buffer[size];
    std::cout<< size << std::endl;
}

// int size is a nontype template argument
// STL uses nontype template arguments like this to determine sizes
template<typename T, int size>
T Sum(T (&parr)[size]) {
    T sum{};
    for (int i = 0; i < size ; ++i) { 
        sum += parr[i];
    }
    return sum;
}

int main() {
    Print<3>();

    int arr[]{1,2,3,4};
    // the begin function uses a nontype template argument
    auto it = std::begin(arr);
    int sum = Sum(arr);
    std::cout<< sum << std::endl;
    
    return 0;
}