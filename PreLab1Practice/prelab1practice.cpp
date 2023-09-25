#include <iostream>
using namespace std;
int main() {
    double num1, num2, num3;
    char op1, op2;
    double total;

    enum sign { PLUS = '+', MINUS = '-', MULT = '*', DIV = '/'};

    std::cout << "Enter 3 numbers separated by 2 operators: ";
    std::cin >> num1 >> op1 >> num2 >> op2 >> num3;
    
    switch(op1) {
        case PLUS:
            total = (num1 + num2);
            break;
        case MINUS:
            total = (num1 - num2);
            break;
        case MULT:
            total = (num1*num2);
            break;
        case DIV:
            if(num2 == 0){
                std::cout << "Error: Cannot divide by zero!";
                exit(0);
            }
            else {
                total = (num1/num2);
            }
            break;
    }
    switch(op2) {
        case PLUS:
            total += num3;
            break;
        case MINUS:
            total -= num3;
            break;
        case MULT:
            total *= num3;
            break;
        case DIV:
            if(num3 == 0){
                std::cout << "Error: Cannot divide by 0!";
                exit(0);
            }
            else {
                total /= num3;
            }
            break;
    }

    std::cout << "Total: " << total << std::endl;

    std::cout << __cplusplus;

    return 0;
}
