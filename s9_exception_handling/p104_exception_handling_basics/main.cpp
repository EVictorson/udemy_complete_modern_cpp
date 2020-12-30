#include <iostream>
#include <limits>

int ProcessRecords(int count) {
    if (count < 10) {
        throw std::out_of_range("Count should be greater than 10");
    }
    //if new fails it throws of type bad_alloc
    int *p = new int[count];
    int *pArray = (int*)malloc(count * sizeof(int));
    if (pArray == nullptr) {
        throw std::runtime_error("Failed to allocate memory");
    }
    for (int i = 0; i<count; ++i) {
        pArray[i] = i;
    }
    free(pArray);
    delete(p);
    return 0;
}

int main() {
    try {
        //std::cout<<std::numeric_limits<int>::max()<<std::endl;
        //std::cout<<std::numeric_limits<int>::max()+1<<std::endl;
        //ProcessRecords(std::numeric_limits<int>::max());
        ProcessRecords(5);
    }
    /*
    catch (std::runtime_error &ex) {
        std::cout<< ex.what() <<std::endl;
    }
    catch(std::out_of_range &ex) {
        std::cout<< ex.what() <<std::endl;
    }
    catch (std::bad_alloc &ex) {
        std::cout<< ex.what() <<std::endl;
    }
    */
    // all exceptions inherit from base class std::exception, so we can do this:
    catch(std::exception &ex) {
        std::cout<< ex.what() <<std::endl;
    }

    // can catch all exceptions (without information) w/
    // avoid the ellipses catch block, but can use it as the last catch to catch everything
    catch (...) {
        std::cout<<"Exception"<<std::endl;
    }

    return 0;
}