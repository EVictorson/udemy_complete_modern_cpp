#include <iostream>
#include <string.h>

// Primary template
template<typename T>
T Max(T x, T y) {
    std::cout<<typeid(T).name()<<std::endl;
    return x > y ? x : y;
}

// Explicit Instantiation
template char Max(char x, char y);

// without explicit specialization the Max() function would just compare the addresses of the two variables passed in
// Explicit Specialization
template<> const char * Max<const char*>(const  char *x, const char *y) {
    std::cout<<"Max<const char*>()"<<std::endl;
    return strcmp(x,y) > 0 ? x : y;

}

int main() {
    const char *b{"B"};
    const char *a{"A"};
    auto s = Max(a, b);
    std::cout<<s<<std::endl;

    return 0;
}