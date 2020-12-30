#include <iostream>

/*
Convert the following functions into templates

int Add(int x,int y) ; //Return the sum of two elements
int ArraySum(int *pArr, int arrSize); //Returns the sum of array elements
int Max(int *pArr, int arrSize) ; //Return the largest element in the array
std::pair<int,int> MinMax(int *pArr, int arrSize) ; //Return the smallest and largest element in a pair
Take care to avoid copies of user-defined objects wherever applicable.
*/

template<typename T>
T Add(T x, T y) {
    return x + y;
}

template<typename T>
T ArraySum(T *parr, int arrsize) {
    T sum{};
    for (int i=0; i<arrsize; ++i) {
        sum += parr[i];
    }

    return sum;
}

template<typename T>
T Max(T *parr, int arrsize) {
    T max{};
    for (int i=0; i<arrsize; ++i) {
        if(parr[i] > max) {
            max = parr[i];
        }
    }

    return max;
}


template<typename T>
std::pair<T,T> MinMax(T *parr, int arrsize) {
    std::pair<T, T> minmax{};
    T val{};
    for (int i=0; i<arrsize; ++i) {
        val = parr[i];
        if(val < minmax.first) {
            minmax.first = parr[i];
        }
        if(val > minmax.second) {
            minmax.second = parr[i];
        }
    }

    return minmax;
}

int main() {
    int arr[5]{1,2,3,4,5};
    int *parr = arr;

    auto out = ArraySum(parr, 5);
    std::cout<<"Out = "<<out<<std::endl;

    auto max = Max(parr, 5);
    std::cout<<"Max = "<<max<<std::endl;

    auto minmax = MinMax(parr, 5);
    std::cout<<"MinMax = "<<minmax.first<<", "<<minmax.second<<std::endl;

    return 0;
}