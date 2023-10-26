#include <vector>
#include <iostream>
// #include "vector.h"

using size_type = size_t;
using element_type = double;

class Vector {
    
    public:
        Vector(size_type dimensions = 1);                               //Constructor
        Vector(const Vector& v);                                        //Copy Constructor - Pass by reference - const so original cannot be changed
        Vector(Vector&& v);                                             //Move Constructor
        ~Vector();                                                      //Destructor

        size_type getDimensions() const { return dimensions; };         // Allows for inlining
        void reset();
        
        friend std::ostream& operator <<(std::ostream& outStream, const Vector& v);
        friend std::istream& operator >>(std::istream& inStream, Vector& v);
    
    private:
        size_type dimensions;
        element_type* array = new element_type[dimensions];
};


int main() {

    Vector v1(3);
    std::cout << "Enter array: ";
    std::cin >> v1;
    std::cout << "Dimensions: " << v1.getDimensions() << std::endl;
    std::cout << v1 << std::endl;
    
    Vector v2(v1);
    std::cout << "Dimensions: " << v2.getDimensions() << std::endl;
    std::cout << v2 << std::endl;
    
    Vector v3(std::move(v1));   
    std::cout << "Dimensions: " << v3.getDimensions() << std::endl;
    std::cout << v3 << std::endl;

    size_type size;
    std::cout << "Enter size: ";
    std::cin >> size;
    Vector v4(size);
    std::cout << "Enter array: ";
    std::cin >> v4;
    std::cout << "Dimensions: " << v4.getDimensions() << std::endl;
    std::cout << v4 << std::endl;
    std::cout << "Dimensions: " << v1.getDimensions() << std::endl;
    std::cout << v1 << std::endl;

    delete [] &v1;
    delete [] &v2;
    delete [] &v3;
    delete [] &v4;

    std::cout << v1;
}
//! figure out what array(dimensions, 0.0) is doing
Vector::Vector(size_type dimensions) : dimensions(dimensions), array(new element_type[dimensions]{0.}) {}    // after : is initializer list

Vector::Vector(const Vector& v) : dimensions(v.dimensions), array(new element_type[v.dimensions]) {
    for (size_type i = 0; i < v.dimensions; ++i) {
        array[i] = v.array[i];
    }
}    // after : is initializer list

Vector::Vector(Vector&& v) : dimensions(v.dimensions), array(new element_type[v.dimensions]) {
    array = std::move(v.array);
    v.dimensions = 0;
}

Vector::~Vector() {
    delete []array;
}
        
void Vector::reset() {
    for (size_type i = 0; i < dimensions; ++i) {
        array[i] = 0.0;
    }
}

std::ostream& operator <<(std::ostream& outStream, const Vector& v) {
    for (size_type i = 0; i < v.dimensions; ++i) {
       outStream << v.array[i] << " ";
    }
    return outStream;
}

std::istream& operator >>(std::istream& inStream, Vector& v) {          //!doesnt add new elements if array is larger than default size
    char eatChar;
    element_type dimen;
    if(!(inStream >> eatChar)) {
        std::cin.clear(); 
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        std::cerr << "\nInvalid Input." << std::endl;
        return inStream;
    }
    for (size_type i = 0; i < v.dimensions; ++i) {      //use dimensions so reset() works
        inStream >> v.array[i];
        if(!(inStream >> eatChar)) {
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::cerr << "\nInvalid Input." << std::endl;
            return inStream;
        }
    }
    return inStream;
}