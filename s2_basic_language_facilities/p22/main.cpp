#include <iostream>

// Pass by value (wont work!)
void swap_by_value(int x, int y) { 
    int temp = x;
    x = y;
    y = x;
}

// Pass by pointer (or sometimes called by address)
void swap_by_ptr(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Pass by reference
void swap_by_ref(int &x, int &y) { 
    int temp = x;
    x = y;
    y = temp;
}

int main () {
    int x, y;
    x = 1;
    y = 5;

    std::cout<<"Values before swap_by_value:  x = "<<x<<" y = "<<y<<std::endl;
    swap_by_value(x, y);
    std::cout<<"Values after swap_by_value: x = "<<x<<" y = "<<y<<"\n"<<std::endl;

    int *ptrx = &x;
    int *ptry = &y;
    std::cout<<"Values before swap_by_ptr:  x = "<<x<<" y = "<<y<<std::endl;
    swap_by_ptr(ptrx, ptry);
    std::cout<<"Values after swap_by_ptr: x = "<<x<<" y = "<<y<<"\n"<<std::endl;

    std::cout<<"Values before swap_by_ref:  x = "<<x<<" y = "<<y<<std::endl;
    swap_by_ref(x, y);
    std::cout<<"Values after swap_by_ref: x = "<<x<<" y = "<<y<<std::endl;

    return 0;
}