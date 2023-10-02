#include <iostream>
#include <cmath>

void getInput(double& num1, char& cOp, double& num2);

double calculate(double& num1, char cOp, double& num2);

//void printOutput(int num1, char op, int num2);
//Prints output based on user input (num1, op, num2)

enum Ops { ADD = '+', SUB = '-', MUL = '*', DIV = '/', MOD = '%' };

int main() {

    double num1, num2; 
    Ops op;
    char cOp;
    char answer = 'n';
    double result;
    
    do {
        getInput(num1, cOp, num2);
        op = static_cast<Ops>(cOp);
        result = calculate(num1, op, num2);
        std::cout << num1 << " " << cOp << " " << num2 << " = " << result << std::endl;
        std::cout << "Do you want to enter another equation? ";
        std::cin >> answer;
    }while(answer == 'Y' || answer == 'y');
   

    //printOutput(num1, cOp, num2);

    std::cout << std::endl << __cplusplus;
}


void getInput(double& num1, char& cOp, double& num2) {
        
        bool valid = false;

        while(!valid) {
            std::cout << "Enter simple equation ( a + b ): ";   // num1, cOp, num2
            std::cin >> num1;
            
            if(std::cin) { // or if(cin.fail()) -- If num1 is valid, continue
                std::cin >> cOp; 
                
                if(cOp == '+' || cOp == '-' || cOp == '*' || cOp == '%' || cOp == '/') {    // If cOp is valid, continue
                    std::cin >> num2;
                    if(std::cin){           // If num3 is valid, continue
                        valid = true;       // All 3 are valid, therefore valid = true
                    }
                    else {  // else, if user didn't input a number
                        std::cin.clear(); // reset failbit
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input, next, request user reinput
                        std::cout << "Invalid Equation" << std::endl;
                    }
                }
                else { // else, if user didn't input a proper char
                    std::cin.clear(); // reset failbit
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input, next, request user reinput
                   std::cout << "Invalid Equation" << std::endl;
                }
            }
            else { // else, if user didn't input a number
                std::cin.clear(); // reset failbit
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input, next, request user reinput
                std::cout << "Invalid Equation" << std::endl;
            }
        }
    
}


double calculate(double& num1,  char cOp, double& num2) {

    switch(cOp){
        case ADD:
            return (num1+num2);
        case SUB:
            return(num1-num2);
        case MUL:
            return (num1*num2);
        case DIV:
            return (num1/num2);
        case MOD:
            return (fmod(num1,num2));
        default:
            return 0.;
    } 
} 

