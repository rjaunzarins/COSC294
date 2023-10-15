#include <iostream>

class ComplexNumber {
    public:
        ComplexNumber(int real = 1, int imaginary = 1);
        void setReal(int real);
        void setImaginary(int imaginary);
        int getReal() const { return real; }
        int getImaginary() const { return imaginary; };
        const ComplexNumber operator +(const ComplexNumber& complex) const;
        friend std::ostream& operator <<(std::ostream& outStream, const ComplexNumber& complex);
    private:
        int real;
        int imaginary;
};

int main() {
    ComplexNumber cn1(2,-4);
    ComplexNumber cn2(2,3);
    ComplexNumber cn3 = cn1 + cn2;
    std::cout << cn1 << " + " << cn2 << " = " << cn3 << std::endl;
}

ComplexNumber::ComplexNumber(int real, int imaginary) : real(real), imaginary(imaginary) {}

void ComplexNumber::setReal(int real) { this->real = real; }

void ComplexNumber::setImaginary(int imaginary) { this->imaginary = imaginary; }

const ComplexNumber ComplexNumber::operator +(const ComplexNumber& complex) const {
    return ComplexNumber(real + complex.real, imaginary + complex.imaginary);
}
std::ostream& operator <<(std::ostream& outStream, const ComplexNumber& complex) {
    if(complex.imaginary >= 0) {    
        outStream << "(" << complex.real << "+" << complex.imaginary << "i)";
        return outStream;
    }
    else {
        outStream << "(" << complex.real << "-" << abs(complex.imaginary) << "i)";
        return outStream;
    }
}