// range based for loops

#include <iostream>
int main() {
    using namespace std;

    int arr[] = {1,2,3,4,5};

    // standard for loop:
    cout<<"Standard for loop."<<endl;
    for (int i = 0; i < 5; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<"\n"<<endl;

    // range based for loop (similar to for foo in bar w/ python)
    cout<<"Range based for loop."<<endl;
    for (const auto & x : arr) {
        cout<< x <<" ";
    }

    return 0;
}