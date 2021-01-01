#include <iostream>

template<typename T, int size>
class Stack {
public:

    Stack() = default;
    // copy constructor uses short hand notation (without <T, size>)
    // shorthand notation can be used when it's implemented inside the class
    Stack(const Stack &obj) {
        top_ = obj.top_;
        for (int i = 0; i < top_; ++i) {
            buffer_[i] = obj.buffer_[i];
        }
    }
    
    void push(const T &elem) {
        buffer_[++top_] = elem;
    }

    void pop() {
        --top_;
    }

    const T& top() const {
        return buffer_[top_];
    }

    bool isEmpty() {
        return top_ == -1;
    }

    static Stack create() {
        return Stack<T, size>();
    }

private:
    T buffer_[512];
    int top_{-1};
};

/*
template<typename T, int size>
void Stack<T, size>::pop() {
    --top_;
}*/


int main() {

    //Stack<float, 10> stack;
    // or using factory method:
    Stack<float, 10> stack = Stack<float, 10>::create();
    
    stack.push(3);
    stack.push(1);
    stack.push(6);
    stack.push(9);

    while(!stack.isEmpty()) {
        std::cout<< stack.top() << " ";
        stack.pop();
    }

    return 0;
}