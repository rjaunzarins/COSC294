#include <iostream>
#include <fstream>

//! Part B - #4
class A {
    A() = default;
};

//! Part D - a)
//* ComplexNumber Declaration
class ComplexNumber {
    public:
        ComplexNumber(int a = 1, char op = '+', int b = 1);
        void setA(int a);
        void setB(int b);
        void setOp(char op);
        int getA() const {return a; };
        char getOp() const {return op; };
        int getB() const {return b; };
        friend std::ostream& operator <<(std::ostream& outStream, const ComplexNumber num);
    private:
        int a, b;
        char op;
}; //* End ComplexNumber

//* ComplexNumber overloaded operators
const ComplexNumber operator +(const ComplexNumber& complex1, const ComplexNumber& complex2);

//! Part B - 1
void test(double, int);
void test(int, double);

//! Part C - #5
int returnDecimalRep(int num);
//! Part C - #6
std::vector<int> returnSum(const std::vector<int>& v1, const std::vector<int>& v2);

int main() {
    ComplexNumber num1(4, '+', 0);
    std::cout << "Num 1: " << num1 << std::endl;
    ComplexNumber num2(4, '+', -7);
    std::cout << "Num 2: " << num2 << std::endl;
    ComplexNumber sum(num1 + num2);
    std::cout << "Sum: " << sum << std::endl;
    std::cout << num1 << " + " << num2 << " = " << sum << std::endl;
    
    //! Test Method
    //* test(3,2);

    //! Part B - #2
    std::cout.setf(std::ios::fixed);
    std::cout.setf(std::ios::showpoint);
    std::cout.precision(2);
    double v = 7.;
    double f = (3/7) * v + 8.;
    std::cout << f << std::endl;
    
    //! Part C - #5
    int answ = returnDecimalRep(-51);
    std::cout << answ << std::endl;
    
    //! Part C - #6
    std::vector<int> v1 = {1, 3, 5};
    std::vector<int> v2 = {2, 7, 4};
    std::vector<int> v3 = returnSum(v1, v2);
    for (size_t i = 0; i < v3.size(); i++) { std::cout << v3[i] << " "; }
    std::cout << std::endl;

    //! Part A - 2 - True
    int a = 1;
    const int b = 1;
    const int c = 2;
    switch(a) {
        case b: std::cout << "b" << std::endl; break;
        case c: std::cout << "c" << std::endl; break;
        default: std::cout << "default" << std::endl; break;
    }
    //! Part A - 3 - False
    for (size_t i = 1; i <= 10; ) { std::cout << i << " "; ++i; }
    std::cout << std::endl;

    //! Part A - 4 - True
    std::ofstream outStream;
    std::ifstream inStream;
    outStream.open("file.txt");
    for (size_t i = 0; i < 10; i++) { outStream << i << " "; }
    outStream << std::endl;
    outStream.close();
    inStream.open("file.txt");
    int i;
    while(inStream >> i) { std::cout << i << " "; }
    std::cout << std::endl;
    inStream.close();

    //! Part B - 4
    //* A a();    // Interpreted as a functions declaration a(), with return type A
}

//! Part B:
//* void test(double a, int b) {
//*     std::cout << "Test 1" << std::endl;
//* }

//* void test(int a, double b) {
//*     std::cout << "Test 2" << std::endl;
//* }

//! Part C - #5
//Write a function declaration which takes an integer parameter and returns the number
//of digits in the decimal representation of the parameter. For example, if the function
//is called with 2947 as its argument, it should return 4. For -51 it would be 2.
int returnDecimalRep(int num) {
    int count = 0;
    num = abs(num);
    while(num >= 1) {
        num = num/10;
        ++count;
    }
    return count;
}

//! Part C - #6
//Write a function that takes two vector's of ints as parameters by constant
//reference and returns a new vector of its which contains the pairwise sum of
//the two parameters' vectors. Assume the two input vectors are the same size.
std::vector<int> returnSum(const std::vector<int>& v1, const std::vector<int>& v2) {
    std::vector<int> v3;
    for (size_t i = 0; i < v1.size(); i++) {
        v3.push_back(v1[i] + v2[i]);
    }
    return v3;
}

//! Part D - b)
//* ComplexNumber Class
ComplexNumber::ComplexNumber(int a, char op, int b) : a(a) {
    if((b < 0) && (op == '+')){
        this->b = abs(b);
        this->op = '-';
    } 
    else if((b < 0) && (op == '-')) {
        this->b = abs(b);
        this->op = '+';
    }
    else {
        this->b = b;
        this->op = op;
    }
}
void ComplexNumber::setA(int a) { this->a = a; }
void ComplexNumber::setOp(char op) { this->op = op; }
void ComplexNumber::setB(int b) { this->b = b; }
std::ostream& operator <<(std::ostream& outStream, const ComplexNumber num) {
    outStream << "(" << num.a << num.op << num.b << "i)";
    return outStream;
}
const ComplexNumber operator +(const ComplexNumber& complex1, const ComplexNumber& complex2) {
    int x, y;
    char ops;
    x = (complex1.getA() + complex2.getA());
    if(complex1.getOp() == '+' && complex2.getOp() == '+') {
        y = complex1.getB() + complex2.getB();
        ops = '+';
    }
    else if(complex1.getOp() == '-' && complex2.getOp() == '+'){
        y = -(complex1.getB()) + complex2.getB();
        if(y<0) {
            ops = '-';
            y = abs(y);
        }
        else 
            ops = '+';
        return ComplexNumber(x, ops, y);
    }
    else if(complex1.getOp() == '+' && complex2.getOp() == '-') {
        y = complex1.getB() - complex2.getB();
        if(y<0) {
            ops = '-';
            y = abs(y);
        }
        else 
            ops = '+';
    }
    else if(complex1.getOp() == '-' && complex2.getOp() == '-') {
        y = complex1.getB() + complex2.getB();
        if(y < 0) {
            ops = '-';
            y = abs(y);
        }
        else
            ops = '+';
    }
    return ComplexNumber(x, ops, y);
} //* End ComplexNumber Class

