#include <iostream>

const int RED1 = 0;
const int GREEN1 = 1;
const int BLUE1 = 2;

// enum color has global scope
enum Color{RED, GREEN, BLUE};

// c++11 introduced scoped enums as follows
// scoped enums are not implicitly castable to ints
// scoped enums also allow us to specify the type
// you should prefer scoped over non-scoped enums in c++
enum class ScopedColor : long{RED=0, GREEN, BLUE};

void FillColor(Color color) {
    if(color==RED) {
        std::cout<<"RED"<<std::endl;
    }
    else if(color==GREEN) {
        std::cout<<"GREEN"<<std::endl;
    }
    else if(color==BLUE) {
        std::cout<<"BLUE"<<std::endl;
    }
}

void FillColor(ScopedColor color) {
    if(color==ScopedColor::RED) {
        std::cout<<"ScopedColor::RED"<<std::endl;
    }
    else if(color==ScopedColor::GREEN) {
        std::cout<<"ScopedColor::GREEN"<<std::endl;
    }
    else if(color==ScopedColor::BLUE) {
        std::cout<<"ScopedColor::BLUE"<<std::endl;
    }
}

void FillColorInt(int color) {
    if(color==RED1) {
        std::cout<<"const int RED"<<std::endl;
    }
    else if(color==GREEN1) {
        std::cout<<"const int GREEN"<<std::endl;
    }
    else if(color==BLUE1) {
        std::cout<<"const int BLUE"<<std::endl;
    }
    else {
        std::cout<<"None of our defined color consts!"<<std::endl;
    }
}

int main() {
    Color c = RED;
    ScopedColor sc = ScopedColor::BLUE;
    FillColor(c);
    FillColor(GREEN);
    // can still use ints, but they need to be static_cast
    FillColor(static_cast<Color>(2));
    // because this function takes an enum, we cannot pass an int to it
    //FillColor(5);
    FillColorInt(RED1);
    // with our function that takes an int, we can pass any int even if it's
    // not part of our range of interest / mapped values
    FillColorInt(5);

    FillColor(sc);

    return 0;
}