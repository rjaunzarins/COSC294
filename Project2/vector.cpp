#include <iostream>
#include <cmath>
#include "vector.h"

/**
 * Vector Constructor
*/
Vector::Vector(size_type dimensions) : dimensions(dimensions), array(new element_type[dimensions]{0.}) {}    // after : is initializer list

/**
 * Vector Copy Constructor
 * Copy elements of v to calling instance
*/
Vector::Vector(const Vector& v) : dimensions(v.dimensions), array(new element_type[v.dimensions]) {
    for (size_type i = 0; i < v.dimensions; ++i) {
        array[i] = v.array[i];
    }
}    

/**
 * Vector Move Constructor
 * Moves members of v to calling instance, then reset v
*/
Vector::Vector(Vector&& v) : dimensions(v.dimensions), array(std::move(v.array)) {
    v.reset();
    v.array = nullptr;        //! Looks like its supposed to do this but the project doc seems to ask for something different
}

/**
 * Vector Destructor
 * Deletes array from memory
 */
Vector::~Vector() {
    delete [] array;
}

/**
 * reset Function  
 * Sets all elements in array to 0.0      
 */
void Vector::reset() {
    //dimensions = 0;
    for (size_type i = 0; i < dimensions; ++i) {
        array[i] = 0.0;
    }
}

/**
 * Equality Operator Overload - Copy Vector
 */
const Vector& Vector::operator =(const Vector& v) const {
    if(this != & v && dimensions == v.dimensions) {
        for (size_type i = 0; i < v.dimensions; i++) {
            array[i] = v[i];
        }
    }
    return *this;
}                    

/**
 * Equality Operator Overload - Move Vector
 */
const Vector& Vector::operator =(Vector&& v) noexcept {
    if(this != &v) {
        delete [] array;
        dimensions = v.dimensions; 
        array = v.array;
        v.reset();
        //v.array = nullptr;    //! Should this be in the method?
    }
    return *this;
}                    

/**
 * Multiplication Operator Overload - Scalar Multiplication
 */
const Vector Vector::operator *(element_type scalar) const {
    Vector solution(dimensions);
    for (size_type i = 0; i < dimensions; i++) {
        solution[i] = array[i] * scalar;
    }
    return solution;       //*Should this change v or return new Vector?
}    

/**
 * Division Operator Overload - Scalar Division
 */
const Vector Vector::operator /(element_type scalar) const {
    Vector solution(dimensions);
    for (size_type i = 0; i < dimensions; i++) {
        solution[i] = array[i] / scalar;
    }
    return solution; 
}    

/**
 * Addition Operator Overload - Scalar Addition
 */
const Vector Vector::operator +(element_type scalar) const {
    Vector solution(dimensions);
    for (size_type i = 0; i < dimensions; i++) {
        solution[i] = array[i] + scalar;
    }
    return solution; 
}    

/**
 * Subtraction Operator Overload - Scalar Subtraction
 */
const Vector Vector::operator -(element_type scalar) const {
    Vector solution(dimensions);
    for (size_type i = 0; i < dimensions; i++) {
        solution[i] = array[i] + scalar;
    }
    return solution; 
}

/**
 * Addition Operator Overload - Vector Addition
 */
const Vector Vector::operator +(const Vector& v) const {
    if(dimensions != v.dimensions) {
        std::cout << "Error: Vectors must be of the same size for vector addition\n";
        return Vector(0);
    }
    Vector solution(dimensions);
    for (size_type i = 0; i < solution.dimensions; ++i) {
        solution[i] = array[i] + v[i];
    }
    return solution;
}

/**
 * Subtraction Operator Overload - Vector Subtraction
 */
const Vector Vector::operator -(const Vector& v) const {
    if(dimensions != v.dimensions) {
        std::cout << "Error: Vectors must be of the same size for vector subtraction\n";
        return Vector(0);
    }
    Vector solution(dimensions);
    for (size_type i = 0; i < solution.dimensions; ++i) {
        solution[i] = array[i] - v[i];
    }
    return solution;
}

/**
 * Multiplication Operator Overload - Dot Product
 */
const element_type Vector::operator *(const Vector& v) const {
    if(dimensions != v.dimensions) {
        std::cout << "Error: Vectors must be of the same size for dot product\n";
        return 0.0;
    }
    element_type solution = 0;
    for (size_type i = 0; i < dimensions; ++i) {
        solution += array[i] * v.array[i];
    }
    return solution;
}

/**
 * Division Operator Overload - Cross Product
 */
const Vector Vector::operator /(const Vector& v) const {
    if(dimensions != 3 || v.dimensions != 3) {
        std::cout << "Error: Vectors must both be of dimension 3\n";
        return Vector(0);
    }
    Vector solution(3);
    solution[0] = (array[2]*v.array[3]) - (array[3]*v.array[2]);
    solution[1] = (array[3]*v.array[1]) - (array[1]*v.array[3]); 
    solution[2] = (array[1]*v.array[2]) - (array[2]*v.array[1]);
    return solution;
}

/**
 * magnitude Function
 */
const element_type Vector::magnitude() const {
    element_type solution = 0.;
    for (size_type i = 0; i < dimensions; ++i) {
        solution += pow(array[i],2);
    }
    return sqrt(solution);
}

/**
 * angleBetweenVectors Function
 */
const element_type angleBetweenVectors(const Vector& v1, const Vector& v2) {
    if(v1.dimensions != v2.dimensions) {
        std::cout << "Error - must be of same dimension" << "\n";
        return 0.0;
    }
    double cosineAngle = ( (v1*v2) / ((v1.magnitude()) * (v2.magnitude())) );
    double angle = acos(cosineAngle);       //Angle in Radians
    return ( angle * (180/M_PI) );          //Return angle in degrees
    
}

/**
 * distanceBetweenPoints Function
 */
const element_type distanceBetweenPoints(const Vector& v1, const Vector& v2) {
    if(v1.dimensions != v2.dimensions) {
        std::cout << "Error - must be of same dimension" << "\n";
        return 0.0;
    }
    double sum = 0;
    for(size_type i = 0; i < v1.dimensions; ++i) {
        sum += pow((v1[i] - v2[i]),2);
    }
    return sqrt(sum);
}

/**
 * Insertion Operator Overload
 */
std::ostream& operator <<(std::ostream& outStream, const Vector& v) {
    outStream << "{";
    for (size_type i = 0; i < v.dimensions; ++i) {
        if(i < (v.dimensions - 1)) {
            outStream << v[i] << ",";
        }
        else {
            outStream << v[i];
        }
    }
    outStream << "}";
    return outStream;
}

/**
 * Extraction Operator Overload
 */
std::istream& operator >>(std::istream& inStream, Vector& v) {     
    char eatChar;

    if(!(inStream >> eatChar)) {
        std::cin.clear(); 
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        std::cerr << "\nInvalid Input." << std::endl;
        return inStream;
    }
    for (size_type i = 0; i < v.getDimensions(); ++i) {      //use dimensions so reset() works
        if(!(inStream >> v[i])) {
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::cerr << "\nInvalid Input." << std::endl;
            return inStream;
        }
        if(!(inStream >> eatChar)) {
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::cerr << "\nInvalid Input." << std::endl;
            return inStream;
        }
    } 
    return inStream;
}