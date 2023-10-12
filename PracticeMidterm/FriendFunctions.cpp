#include <iostream>
#include <cmath>

class EqualateralTriangle {
    public:
        EqualateralTriangle(double a = 1);
        EqualateralTriangle(const EqualateralTriangle& et);
        void setA(double a);
        inline double getA() const { return a; }                    //Must be CONST to work with overloaded operator methods
        inline double getPerimeter() const { return perimeter; }
        inline double getArea() const { return area; }
        //void printTriangle();
        friend std::ostream& operator <<(std::ostream& output, const EqualateralTriangle& et);
        friend std::istream& operator >>(std::istream& input, EqualateralTriangle& et);
    private:
        double a;
        double perimeter;
        double area; 
};

const EqualateralTriangle operator +(const EqualateralTriangle& et1, const EqualateralTriangle& et2);
const EqualateralTriangle operator -(const EqualateralTriangle& et1, const EqualateralTriangle& et2);
bool operator ==(const EqualateralTriangle& et1, const EqualateralTriangle& et2);
const EqualateralTriangle operator -(const EqualateralTriangle& et);

void setPrecision();

int main() {

    EqualateralTriangle et1(3);
    EqualateralTriangle et2(4);
    EqualateralTriangle et3(et1);
    EqualateralTriangle et4 = et1 + et2;
    EqualateralTriangle et5;
    std::cout << "Enter value for side: ";
    std::cin >> et5;
    setPrecision();
    std::cout << et1 << "\n" << et2 << "\n" << et3 << "\n" << et4 << "\n" << et5 << std::endl;   //Printed with overloaded << operator
    std::cout << "\net1 = et2: " << (et1 == et2) << std::endl;
    std::cout << "et1 = et3: " << (et1 == et3) << std::endl;
}

void setPrecision() {
    std::cout.setf(std::ios::fixed);
    std::cout.setf(std::ios::showpoint);
    std::cout.precision(2);
}

//*CONSTRUCTOR
EqualateralTriangle::EqualateralTriangle(double a) : a(a) {
    perimeter = ( (sqrt(3) / 4) * pow(a,2) );
    area = pow(a,3);
}

//*COPY CONSTRUCTOR
EqualateralTriangle::EqualateralTriangle(const EqualateralTriangle& et) : a(et.a), perimeter(et.perimeter), area(et.area) {}

// void EqualateralTriangle::printTriangle() {
//     std::cout << "Perimeter = " << perimeter << "\n" << "Area = " << area << std::endl;
// }

//OVERLOADED << OPERATOR
std::ostream& operator <<(std::ostream& output, const EqualateralTriangle& et) {
    output << "Length = " << et.a << "\n" 
           << "Perimeter = " << et.perimeter << "\n" 
           << "Area = " << et.area << std::endl;
    return output;
}
//OVERLOADED >> OPERATOR
std::istream& operator >>(std::istream& input, EqualateralTriangle& et) {
    int a;
    input >> a; 
    et.setA(a);
    return input;
}

//OVERLOADED + OPERATOR
const EqualateralTriangle operator +(const EqualateralTriangle& et1, const EqualateralTriangle& et2) {
    return EqualateralTriangle( et1.getA() + et2.getA() );
}
//OVERLOADED - OPERATOR
const EqualateralTriangle operator -(const EqualateralTriangle& et1, const EqualateralTriangle& et2) {
    return EqualateralTriangle( et1.getA() - et2.getA() );
}
//OVERLOADED == OPERATOR
bool operator ==(const EqualateralTriangle& et1, const EqualateralTriangle& et2) {
    return (et1.getA() == et2.getA());
}
//OVERLOADED - OPERATOR
const EqualateralTriangle operator -(const EqualateralTriangle& et) {
    return EqualateralTriangle(-(et.getA()));

}

void EqualateralTriangle::setA(double a) {
    this->a = a;
    perimeter = ( (sqrt(3) / 4) * pow(a,2) );
    area = pow(a,3);
}