#include <iostream>

int main() {
    //Try to modify x1 & x2 and see the compilation output
    int x = 5 ;
    const int MAX = 12 ;
    int &ref_x1 = x ;
    const int &ref_x2 = x ;

    ref_x1 = 10;
    //ref_x2 = 20; // will vomit with:  error: assignment of read-only reference ‘ref_x2’
    
    
    //Try to modify the pointer (e.g. ptr1) and the pointee value (e.g. *ptr1)
    const int *ptr1 = &x ;
    int *const ptr2 = &x ;
    const int * const ptr3 = &x ;

    int blah = 2;
    ptr1 = &blah;   // works fine
    //*ptr1 = 10;   // error: assignment of read-only location ‘* ptr1’

    //ptr2 = blah;  // error: assignment of read-only variable ‘ptr2’
    *ptr2 = 10;     // works fine

    //ptr3 = &blah;  // error: assignment of read-only variable ‘ptr3’
    //*ptr3 = 10;    // error: assignment of read-only location ‘*(const int*)ptr3’

    

    //Find which declarations are valid. If invalid, correct the declaration
    const int *ptr5 = &MAX ;    // valid
    //int *ptr4 = &MAX ;          // error: invalid conversion from ‘const int*’ to ‘int*’ 
    const int *const ptr4 = &MAX;   // correction
    
    const int &r1 = ref_x1 ;
    //int &r2 = ref_x2 ;    // error: binding reference of type ‘int&’ to ‘const int’ discards qualifiers
    const int &r2 = ref_x2; // correction

    const int *&p_ref1 = ptr1 ;
    //const int*&p_ref2 = ptr2 ;  // error: cannot bind non-const lvalue reference of type ‘const int*&’ to an rvalue of type ‘const int*’
    const int*const &p_ref2 = ptr2 ;    // correction

    return 0;
}