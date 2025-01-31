#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Record {
    int id;
    char name[10];
};

void WriteRecord(Record *p) {
    std::ofstream binstream("records", std::ios::binary | std::ios::out);
    binstream.write((const char*)p, sizeof(Record));
}

Record GetRecord() {
    std::ifstream input {"records", std::ios::binary | std::ios::in};
    Record r;
    input.read((char*)&r, sizeof(Record));
    return r;
}

int main() {
    std::ofstream textstream{"data"};
    textstream << 12345678;

    std::ofstream binstream{"binary", std::ios::binary | std::ios::out};
    int num{12345678};
    binstream.write((const char*)&num, sizeof(num)); 
    num = 0;
    binstream.close();

    std::ifstream input{"binary", std::ios::binary | std::ios::in};
    input.read((char*)&num, sizeof(num));

    std::cout<< num << std::endl;

    Record r;
    r.id = 1001;
    strcpy(r.name, "Eric");
    WriteRecord(&r);

    Record r2 = GetRecord();

    return 0;
}