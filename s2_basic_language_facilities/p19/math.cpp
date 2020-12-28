#include "math.h"

// add two numbers and return the sum
int Add(int*a, int*b) {
    int sum = *a + *b;

    return sum;
}

// add two numbers and return the sum through the third pointer
void AddVal(int *a, int *b, int *result) {
    *result = *a + *b;
}

// swap the value of two integers using pointers
void Swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// generate the factorial of a number and return it through a pointer
void Factorial(int *a, int *result) {
    int fact{1};
    for(int i = *a; i>0; i--) {
        fact = fact * i;
    }
    *result = fact;
}
