#include <iostream>

void NewArrays() {
    int *p = new int[5]{1,2,3,4,5};
    std::cout<<"p = "<<*p<<std::endl;
    delete []p;
    p = nullptr;
}

void TwoD() {
    int *p1 = new int[3]{0};
    int *p2 = new int[3]{0};
    
    int **pData = new int *[2];
    pData[0] = p1;
    pData[1] = p2;

    pData[0][1] = 2;

    for (int i = 0; i<2; i++) {
        for (int j = 0; j<3; j++) {
            std::cout<<"pData["<<i<<"]["<<j<<"] = "<<pData[i][j]<<std::endl;
        }
    }

    delete []p1;
    delete []p2;
    delete []pData;
}

int main () {
    NewArrays();
    TwoD();

    return 0;
}