#include <iostream>
#include <fstream>
#include <string>
#include <experimental/filesystem>

int main() {
    using namespace std::experimental::filesystem;
    path source(current_path());
    source /= "s10_file_input_and_output/p114_copy_utility_example";
    source /= "main.cpp";
    std::cout<<"Source = "<<source<<std::endl;

    path dest(current_path());
    dest /= "copy_of_main.cpp";

    std::ifstream input{source};
    if(!input) {
        std::cout<<"Source file not found."<<std::endl;
        return -1;
    }

    std::ofstream output{dest};

    std::string line;
    while (!std::getline(input, line).eof()) {
        output << line << std::endl;
    }

    input.close();
    output.close();

    return 0;
}