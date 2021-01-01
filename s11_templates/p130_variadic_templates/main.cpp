#include <iostream>

/*
template<typename T>
void Print(std::initializer_list<T> args) {
    for (const auto &x : args) {
        std::cout<< x << " ";
    }
}*/

void Print() {
    
}

// template parameter pack
template<typename T, typename...Params>
//function parameter pack
void Print(T a, Params... args) {
    //std::cout <<"sizeof parameter pack = "<< sizeof...(args)<<std::endl;
    std::cout<<a;
    if (sizeof...(args) != 0) {
        std::cout<<", ";
    }
    else {
        std::cout<<std::endl;
    }
    Print(args...);

}

int main() {
    Print(1, 2.5, 3, "4");

    return 0;
}
/*
1. Print(1, 2.5, 3, "4");
2. Print(2.5, 3, "4");
3. Print(3, "4");
4. Print("4");
5. Print();
*/