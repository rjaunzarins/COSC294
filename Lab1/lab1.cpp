#include <iostream>

int main() {

    double num1, num2;

    std::cout << "Enter 2 doubles: ";
    std::cin >> num1 >> num2;

    std::cout << num1 << " + " << num2 << " = " << (num1+num2) << std::endl;
    std::cout << num1 << " - " << num2 << " = " << (num1-num2) << std::endl;
    std::cout << num1 << " * " << num2 << " = " << (num1*num2) << std::endl;
    if (num2 == 0)
        std::cout << "Cannot divide by zero" << std::endl;
    else {   
        std::cout << num1 << " / " << num2 << " = " << (num1/num2) << std::endl;
        std::cout << num1 << " % " << num2 << " = " << (std::fmod(num1,num2)) << std::endl;
    }
    std::cout << __cplusplus;
}