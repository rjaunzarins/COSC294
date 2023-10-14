#include <vector>
#include <iostream>
// #include "vector.h"

using size_type = unsigned;
using element_type = double;

class Vector {
    
    public:
        Vector(size_type dimensions = 1);                               //Constructor
        Vector(const Vector& v);                                    //Copy Constructor - Pass by reference - const so original cannot be changed
        Vector(Vector&& v);                                          //Move Constructor

        size_type getDimensions() const { return dimensions; };     // Allows for inlining
        void reset();
        
        friend std::ostream& operator <<(std::ostream& outStream, const Vector& v);
        friend std::istream& operator >>(std::istream& inStream, Vector& v);
    
    private:
        size_type dimensions;
        std::vector<element_type> array;
        
};


int main() {
    Vector v1(10);
    std::cout << "Dimensions: " << v1.getDimensions() << std::endl;
    std::cout << v1 << std::endl;
    Vector v2(v1);
    std::cout << "Dimensions: " << v2.getDimensions() << std::endl;
    std::cout << v2 << std::endl;
    //Vector v3 = std::move(v1);      //! why error but working?
    size_type size;
    std::cout << "Enter size: ";
    std::cin >> size << std::endl;
    Vector v3(size);
    std::cout << v3;
    std::cout << "Enter array: ";
    std::cin >> v3;
    std::cout << "Dimensions: " << v3.getDimensions() << std::endl;
    std::cout << v3 << std::endl;
    std::cout << "Dimensions: " << v1.getDimensions() << std::endl;
    std::cout << v1 << std::endl;

    // std::cout << v3;

}
//! figure out what array(dimensions, 0.0) is doing
Vector::Vector(size_type dimensions) : dimensions(dimensions), array(dimensions, 0.0) {}    // after : is initializer list

Vector::Vector(const Vector& v) : dimensions(v.dimensions), array(v.array) {}    // after : is initializer list

Vector::Vector(Vector&& v) : dimensions(v.dimensions), array(std::move(v.array)) {
    v.reset();
}
        
void Vector::reset() {
    // for (size_type i = 0; i < array.size(); ++i) {
    //     array[i] = 0.0;
    // }
    dimensions = 0;         //! should this be here?
    array.resize(0);        //! should this be here?
}

std::ostream& operator <<(std::ostream& outStream, const Vector& v) {
    for (size_type i = 0; i < v.array.size(); ++i) {
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
    for (size_type i = 0; i < v.array.size(); ++i) {
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