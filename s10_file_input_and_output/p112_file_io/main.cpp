#include <iostream>
#include <fstream>
#include <string>

void Write() {
    // can create ofstream object by either calling constructor with direct initialization or
    // by callin open:
    std::ofstream out{"data.txt"};
    out<<"Hello world."<<std::endl;
    out << 10 << std::endl;
    out.close();
}

void Read() {
    // can create ifstream object by either calling constructor with direct initialization or
    // by callin open:
    std::ifstream input; //{"data.txt"};
    input.open("data.txt");

    // can check below if block with this:
    //input.open("dat.txt");
    // check to see if ifstream object was successfully created
    /*
    if(!input.is_open()) {
        std::cout<<"Could not open the file"<<std::endl;
        return;
    }
    */
    // can alternatively check with:
    if(input.fail()) {
        std::cout<<"Could not open the file."<<std::endl;
        return;
    }

    std::string message;
    std::getline(input, message);
    int value{};
    input >> value;
    // uncomment this to have input.good() return false
    //input >> value;

    if (input.eof()) {
        std::cout<<"End of file encountered."<<std::endl;
    }

    if (input.good()) {
        std::cout<<"I/O operations were successful."<<std::endl;

    }
    else {
        std::cout<<"Some I/O operations failed."<<std::endl;
    }
    // can manually set the state
    input.setstate(std::ios::failbit);
    // clear() clears the return bits
    input.clear();
    input.close();
    std::cout<< message << " : " << value << std::endl;
}

int main() {
    Write();
    Read();

    return 0;
}