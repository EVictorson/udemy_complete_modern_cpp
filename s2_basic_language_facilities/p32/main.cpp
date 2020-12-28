#include <iostream>

void Print(int count, char ch) {
    for(int i = 0; i < count; i++) {
        std::cout<< ch;
    }
    std::cout<<std::endl;
}

void EndMessage() {
    std::cout<<"End of program."<<std::endl;
}

int main() {
    // atexit takes in a pointer to a function to be called at exit
    std::atexit(EndMessage);
    Print(5, '#');

    // function pointer
    // note: the function name is a reference, so we don't need to use &Print
    void(*pfn) (int, char) = Print;
    pfn(8, '@');

    return 0;
}