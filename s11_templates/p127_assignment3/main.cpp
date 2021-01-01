#include <iostream>
#include <string>

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

// Explicit Instantiation
//template int ArraySum(std::string *parr, int size);

// explicit specialization for pointer to array of std::strings
template<> 
std::string ArraySum<std::string>(std::string *parr, int arrsize) {
    std::string sum{};
    for (int i = 0; i<arrsize; ++i) {
        sum += (parr[i]);
    }

    return sum;
}

// template argument list with non-type template argument int size
// which is deduced from the size of the referenced array

template<typename T, int size>
T ArraySum(T (&arr)[size]) {
    T sum{};
    for (int i=0; i<size; ++i) {
        sum += arr[i];
    }

    return sum;
}


template<typename T>
T ArrayMax(T *parr, int arrsize) {
    T max{};
    for (int i=0; i<arrsize; ++i) {
        if(parr[i] > max) {
            max = parr[i];
        }
    }

    return max;
}

template<typename T, int size>
T ArrayMax(T (&arr)[size]) {
    T max{};
    for (int i=0; i<size; ++i) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }

    return max;
}

// Primary template
template<typename T>
T Max(T x, T y) {
    std::cout<<typeid(T).name()<<std::endl;
    return x > y ? x : y;
}

// Explicit Specialization for strings
template<> std::string Max<std::string>(std::string x, std::string y) {
    return x.compare(y) > 0 ? x : y;
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

template<typename T, int size>
std::pair<T,T> MinMax(T (&arr)[size]) {
    std::pair<T, T> minmax{};
    T val{};
    for (int i=0; i<size; ++i) {
        val = arr[i];
        if(val < minmax.first) {
            minmax.first = arr[i];
        }
        if(val > minmax.second) {
            minmax.second = arr[i];
        }
    }

    return minmax;
}


int main() {
    int arr[5]{1,2,3,4,5};
    int *parr = arr;
    std::string str1 = "abcd";
    std::string str2 = "abcdef";
    std::string strarr[2]{str1, str2};
    auto strmax = Max(str1, str2);
    std::cout<<"strmax = "<<strmax<<std::endl;

    auto strarrsum = ArraySum(strarr);
    std::cout<<"str array sum = "<<strarrsum<<std::endl;

    auto out = ArraySum(parr, 5);
    std::cout<<"Out = "<<out<<std::endl;
    std::cout<<"Using nontype template argument method: "<<std::endl;
    auto out2 = ArraySum(arr);
    std::cout<<"Out2 = "<<out2<<std::endl;

    auto max = ArrayMax(parr, 5);
    std::cout<<"Max = "<<max<<std::endl;
    std::cout<<"Using nontype template argument method: "<<std::endl;
    auto max2 = ArrayMax(arr);
    std::cout<<"Max2 = "<<max2<<std::endl;


    auto minmax = MinMax(parr, 5);
    std::cout<<"MinMax = "<<minmax.first<<", "<<minmax.second<<std::endl;
    std::cout<<"Using nontype template argument method: "<<std::endl;
    auto minmax2 = MinMax(arr);
    std::cout<<"MinMax2 = "<< minmax2.first<<", "<<minmax2.second<<std::endl;
    return 0;
}