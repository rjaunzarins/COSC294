#include <iostream>
#include <cmath>

void printOutput(int num1, char op, int num2);
//Prints output based on user input (num1, op, num2)

int main() {

    int num1, num2;
    char op;
    
    std::cout << "Enter simple equation ( a + b ): ";
    std::cin >> num1 >> op >> num2;

    printOutput(num1, op, num2);

    std::cout << __cplusplus;
}

void printOutput(int num1, char op, int num2){
    //Define enum to check user input
    enum ops { ADD = '+', SUB = '-', MUL = '*', DIV = '/', MOD = '%' };

    //Switch to make calculation based on ops
    switch(op){
        case ADD:
            std::cout << num1 << " + " << num2 << " = " << (num1+num2) << std::endl;
            break;
        case SUB:
            std::cout << num1 << " - " << num2 << " = " << (num1-num2) << std::endl;
            break;
        case MUL:
            std::cout << num1 << " * " << num2 << " = " << (num1*num2) << std::endl;
            break;
        case DIV:
            if(num2 == 0){
                std::cerr << "Cannot divide by zero!" << std::endl;
                break;
            }
            else {
                std::cout << num1 << " / " << num2 << " = " << (num1/num2) << std::endl;
                break;
            }
        case MOD:
            if(num2 == 0){
                std::cerr << "Cannot divide by zero!" << std::endl;
                break;
            }
            else {
                std::cout << num1 << " % " << num2 << " = " << (fmod(num1,num2)) << std::endl;
                break;
            }
        default:
            std::cout << "Cannot recognize math symbol" << std::endl;
            break;
    }
}