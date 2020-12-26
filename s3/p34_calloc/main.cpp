// examples of c-style dynamic memory allocation with malloc and calloc

#include <stdio.h>
#include <stdlib.h>

int main() {
    // use c-style malloc to allocate raw data of size int on the heap
    // in c++ you need to cast the return of malloc()
    int *p = (int*)malloc(sizeof(int));
    *p = 5;
    printf("value pointed to py p = %d", *p);
    printf("\n");

    // free the allocated heap memory so as to prevent a memory leak
    free(p);
    // right now p is a dangling pointer, a pointer that points to memory that doesn't exist
    p = nullptr;
    // p is no longer a dangling pointer

    // if using a debugger on visual studio or similar you can watch the memory change


    // demonstrating using calloc as well:
    // calloc initializes memory to 0
    int *p2 = (int*)calloc(1, sizeof(int));
    printf("value pointed to by p2 = %d", *p2);
    printf("\n");
    free(p2);
    p2 = nullptr;

    return 0;
}