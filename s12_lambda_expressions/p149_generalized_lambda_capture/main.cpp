#include <iostream>
#include <fstream>

int main() {
    int x{5};

    // generalized lambda capture:
    auto f = [y=x](int arg) {
        return y + arg;
    };

    std::cout<<f(5)<<std::endl;

    std::ofstream out{"p149.txt"};
    auto write = [out = std::move(out)](int x) mutable{
        out<<x;
    };

    write(200);

    return 0;
}