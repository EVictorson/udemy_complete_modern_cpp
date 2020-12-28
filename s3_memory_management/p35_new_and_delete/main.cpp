#include <iostream>
#include <stdio.h>
#include <stdlib.h>

void Malloc() {
    int *p = (int*)malloc(5 * sizeof(int));
    if (p==NULL) {
        printf("failed to allocate memory\n");
        return;
    }
    *p = 5;
    printf("p = %d", *p);
    free(p);
    p = nullptr;
}

void New() {
    // allocate uninitialized memory on the heap
    int *p = new int;
    *p = 6;
    std::cout<<" p = "<< *p <<std::endl;
    delete p;
    p = nullptr;

    // allocate initialized memory on the heap
    int *p2 = new int(5);
    std::cout<<"p2 = "<<*p2<<std::endl;
    delete p2;
    p2 = nullptr;
}

int main() {
    New();

    return 0;
}