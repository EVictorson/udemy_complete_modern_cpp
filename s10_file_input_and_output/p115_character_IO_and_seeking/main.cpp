#include <iostream>
#include <fstream>
#include <string>

void Write() {
    std::ofstream out{"test.txt"};
    if(!out) {
        std::cout<< "Could not open file for writing"<< std::endl;
        return;
    }

    // tellp() returns the current position of the put pointer

    std::string msg{"C++ was invented by Bjarne"};
    for (char ch : msg) {
        out.put(ch);
    }

    // use seekp() to seek to ofstream index
    out.seekp(5);
    out.put('#');

}

void Read() {
    std::ifstream input{"test.txt"};
    if(!input) {
        std::cout<< "Source file not found."<<std::endl;
        return;
    }

    // to tell the get pointer where to start, use seekg()
    // second overload of input.seekg() is: input.seekg(offset, base_position)
    // input.seekg(10, std::ios::beg)
    //input.seekg(5);

    // tellg() returns the current position of the get pointer
    std::cout<< "Current position is: "<< input.tellg() << std::endl;
    char ch{};

    // get pointer gets the current index in the stream
    while (input.get(ch)) {
        std::cout << ch;
    }
}

void UsingFstream() {
    std::fstream stream{"file.txt"};
    if(!stream) {
        std::cout<<"FILE DOES NOT EXIST.  CREATING ONE."<<std::endl;
        std::ofstream out{"file.txt"};
        out.close();
        stream.open("file.txt");
    }
    stream<<"Hello world"<<std::endl;
    // after writing to file, both put and get pointers are at the end
    // before we read, we need to seek get pointer to the begining.

    stream.seekg(0);
    std::string line;
    std::getline(stream, line);
    std::cout<< line << std::endl;
}

int main() {
    Write();
    Read();
    UsingFstream();

    return 0;
}