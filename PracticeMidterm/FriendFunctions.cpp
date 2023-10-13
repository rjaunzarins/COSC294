#include <iostream>
#include <cmath>

class EqualateralTriangle {
    public:
        EqualateralTriangle(double a = 1);
        EqualateralTriangle(const EqualateralTriangle& et);
        void setA(double a);
        double getA() const { return a; }                   // Inline function - Must be CONST to work with overloaded operator methods
        double getPerimeter() const { return perimeter; }   // Inline function
        double getArea() const { return area; }             // Inline function
        //void printTriangle();
        
        //Overloading '=' needs to be a member function - there is a default '=' operator function for all classes
        
        // Member Overloads
        double& operator[](int index);                      // [] overload - member function
        const EqualateralTriangle operator ++();            //prefix ++ - member function
        const EqualateralTriangle operator ++(int flag);    //Postfix ++ - member function - uses int in method signature to show its for postfix overload
        // Non-Member Friend Function Overloads
        friend std::ostream& operator <<(std::ostream& output, const EqualateralTriangle& et);  //must return & otherwise a new copy is made
        friend std::istream& operator >>(std::istream& input, EqualateralTriangle& et);        
        friend const EqualateralTriangle operator +(const EqualateralTriangle& et1, const EqualateralTriangle& et2);
        friend const EqualateralTriangle operator +(const EqualateralTriangle& et1, int length);
        friend const EqualateralTriangle operator +(int length, const EqualateralTriangle& et1);
        friend const EqualateralTriangle operator -(const EqualateralTriangle& et1, const EqualateralTriangle& et2);
        friend bool operator ==(const EqualateralTriangle& et1, const EqualateralTriangle& et2);
        friend const EqualateralTriangle operator -(const EqualateralTriangle& et);
    private:
        double a;
        double perimeter;
        double area; 
};



//Set decimal places to 2 in print
void setPrecision();

int main() {
    setPrecision();
    EqualateralTriangle et1(3);
    std::cout << "Length: " << et1[1] << " Perimeter: " << et1[2] << " Area: " << et1[3] << std::endl;
    EqualateralTriangle et2(4);
    EqualateralTriangle et3(et1);
    EqualateralTriangle et4 = et1 + et2;
    EqualateralTriangle et5 = et4 + 5;
    EqualateralTriangle et6;
    
    std::cout << "Enter value for side: ";
    std::cin >> et6;
    std::cout << et1 << "\n" << et2 << "\n" << et3 << "\n" << et4 << "\n" << et5 << "\n" << et6 << std::endl;   //Printed with overloaded << operator
    std::cout << "et: " << et6 << "\net6++: " << et6++ << "\n++et6: " << ++et6 << std::endl;
    std::cout << "et6 after et6++ executes: " << et6 << std::endl;
    std::cout << "\net1 = et2: " << (et1 == et2) << std::endl;
    std::cout << "et1 = et3: " << (et1 == et3) << std::endl;
}

void setPrecision() {
    std::cout.setf(std::ios::fixed);
    std::cout.setf(std::ios::showpoint);
    std::cout.precision(2);
}

//!!!!!!!!CONSTRUCTOR - which way to do it??????
EqualateralTriangle::EqualateralTriangle(double a) : a(a), perimeter((sqrt(3) / 4) * pow(a,2)), area(pow(a,3)) {
    // perimeter = ( (sqrt(3) / 4) * pow(a,2) );
    // area = pow(a,3);
}

//*COPY CONSTRUCTOR
EqualateralTriangle::EqualateralTriangle(const EqualateralTriangle& et) : a(et.a), perimeter(et.perimeter), area(et.area) {}

// void EqualateralTriangle::printTriangle() {
//     std::cout << "Perimeter = " << perimeter << "\n" << "Area = " << area << std::endl;
// }

void EqualateralTriangle::setA(double a) {
    this->a = a;
    perimeter = ( (sqrt(3) / 4) * pow(a,2) );
    area = pow(a,3);
}

//OVERLOADED << OPERATOR
std::ostream& operator <<(std::ostream& output, const EqualateralTriangle& et) {
    output << "Length = " << et.a << "\n" 
           << "Perimeter = " << et.perimeter << "\n" 
           << "Area = " << et.area << std::endl;
    return output;
}
//OVERLOADED >> OPERATOR
std::istream& operator >>(std::istream& input, EqualateralTriangle& et) {
    int a; input >> a; et.setA(a); return input;
}
//OVERLOADED + OPERATOR - friend non-member
const EqualateralTriangle operator +(const EqualateralTriangle& et1, const EqualateralTriangle& et2) {
    return EqualateralTriangle( et1.a + et2.a );
}
//OVERLOADED + OPERATOR - friend non-member
const EqualateralTriangle operator +(const EqualateralTriangle& et1, int length) {
    return EqualateralTriangle( et1.a + length);
}
//OVERLOADED + OPERATOR - friend non-member
const EqualateralTriangle operator + (int length, const EqualateralTriangle& et1) {
    return EqualateralTriangle( et1.a + length);
}
//OVERLOADED - OPERATOR - friend non-member
const EqualateralTriangle operator -(const EqualateralTriangle& et1, const EqualateralTriangle& et2) {
    return EqualateralTriangle( et1.a - et2.a );
}
//OVERLOADED == OPERATOR - friend non-member
bool operator ==(const EqualateralTriangle& et1, const EqualateralTriangle& et2) {
    return (et1.a == et2.a);
}
//OVERLOADED - (negate) OPERATOR - friend non-member
const EqualateralTriangle operator -(const EqualateralTriangle& et) {
    return EqualateralTriangle(-(et.a));
}
//OVERLOADED [] - member function
double& EqualateralTriangle::operator[](int idx) {
    if(idx == 1) return a;
    else if( idx == 2) return perimeter;
    else if(idx == 3) return area;
    else { std::cout << "Illegal index\n"; std::exit(1); }
}
//OVERLOADED ++ - Prefix Version - Member Function
const EqualateralTriangle EqualateralTriangle::operator ++() {
    return EqualateralTriangle(++a);
}
//OVERLOADED ++ - Postfix Version - Member Function - uses int in method signature to show its for postfix overload
const EqualateralTriangle EqualateralTriangle::operator ++(int flag) {
    return EqualateralTriangle(a++);
}

