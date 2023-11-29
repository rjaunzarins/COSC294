#include <iostream>

template<class T>
class MyStack {
    public:
        MyStack() : stack(std::vector<T>()) {}  // Creates an empty stack
        void push( const T& value);             // Pushes the given value onto the stack
        T pop();                                // Pops the top value from the stack and returns it
        T& top();                               // Returns the top value of the stack without removing it
        bool isEmpty();                         // Returns true if the stack is empty, false otherse
        void printStack();                      // Prints the stack
    private:
        std::vector<T> stack;
};

// Pushes the given value onto the stack
template<class T>
void MyStack<T>::push(const T& value) {
    stack.push_back(value);
}

// Pops the top value from the stack and returns it
template<class T>
T MyStack<T>::pop() {
    T temp = stack.back();
    stack.pop_back();
    return temp;
}

// Returns the top value of the stack without removing it
template<class T>
T& MyStack<T>::top() {
    return stack.back();
}

// Returns true if the stack is empty, false otherse
template<class T>
bool MyStack<T>::isEmpty() {
    return stack.empty();
}   

// Prints the stack
template<class T>
void MyStack<T>::printStack() {
    for (size_t i = 0; i < stack.size(); ++i) {
        std::cout << stack[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    
    MyStack<int> stack;
    std::cout << "Bool isEmpty: " << stack.isEmpty() << "\n";
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.printStack();
    std::cout << "Pop: " << stack.pop() << "\n";
    stack.printStack();
    std::cout << "Top: " << stack.top() << "\n";
    stack.printStack();
    std::cout << "Bool isEmpty: " << stack.isEmpty() << "\n";

}