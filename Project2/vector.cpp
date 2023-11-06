//Rhy Jaunzarins - 0404377, Kaylee Joyce - 0383068

#include <iostream>
#include <cmath>
#include "vector.h"

//Constructor
Vector::Vector(size_type dimensions) : dimensions(dimensions), data(new element_type[dimensions]{0.}) {} 

//Copy Constructor
Vector::Vector(const Vector& vectorIn) : dimensions(vectorIn.dimensions), data(new element_type[vectorIn.dimensions]) {
    for (size_type i = 0; i < vectorIn.dimensions; ++i) {
        data[i] = vectorIn.data[i];
    }
}    

//Move Constructor
Vector::Vector(Vector&& vectorIn) : dimensions(vectorIn.dimensions), data(vectorIn.data) {
    vectorIn.dimensions = 0;
    vectorIn.data = nullptr; 
}

//Destructor
Vector::~Vector() {
    if(data != nullptr) {
        delete [] data;
    }
}

//reset Function
void Vector::reset() {
    for (size_type i = 0; i < dimensions; ++i) {
        data[i] = 0.0;
    }
    //dimensions = 0;
}

//Equality Operator Overload - Copy Vector
const Vector& Vector::operator =(const Vector& vectorIn) const {
    if(this != &vectorIn && dimensions == vectorIn.dimensions) {
        for (size_type i = 0; i < vectorIn.dimensions; ++i) {
            data[i] = vectorIn[i];
        }
    }
    return *this;
}               

//Equality Operator Overload - Move Vector
const Vector& Vector::operator =(Vector&& vectorIn) {
    if(this != &vectorIn) {
        delete [] data;
        dimensions = vectorIn.dimensions; 
        data = vectorIn.data;
        vectorIn.dimensions = 0;
        vectorIn.data = nullptr;   
    }
    return *this;
}                    

//Multiplication Operator Overload - Scalar Multiplication
const Vector Vector::operator *(element_type scalar) const {
    Vector scalarProduct(dimensions);
    for (size_type i = 0; i < dimensions; i++) {
        scalarProduct[i] = static_cast<element_type>(data[i] * scalar);
    }
    return scalarProduct;     
}    

//Division Operator Overload - Scalar Division
const Vector Vector::operator /(element_type scalar) const {
    if(scalar == 0) {
        std::cerr << "Error - cannot divide by zero.\n";
        exit(1);
    }
    Vector scalarQuotient(dimensions);
    for (size_type i = 0; i < dimensions; i++) {
        scalarQuotient[i] = static_cast<element_type>(data[i] / scalar);
    }
    return scalarQuotient; 
}    

//Addition Operator Overload - Scalar Addition
const Vector Vector::operator +(element_type scalar) const {
    Vector scalarSum(dimensions);
    for (size_type i = 0; i < dimensions; i++) {
        scalarSum[i] = static_cast<element_type>(data[i] + scalar);
    }
    return scalarSum; 
}    

//Subtraction Operator Overload - Scalar Subtraction
const Vector Vector::operator -(element_type scalar) const {
    Vector scalarSubtact(dimensions);
    for (size_type i = 0; i < dimensions; i++) {
        scalarSubtact[i] = static_cast<element_type>(data[i] + scalar);
    }
    return scalarSubtact; 
}

 //Addition Operator Overload - Vector Addition
const Vector Vector::operator +(const Vector& vectorIn) const {
    if(dimensions != vectorIn.dimensions) {
        std::cerr << "Error: Vectors must be of the same size for vector addition\n";
        exit(1);
    }
    Vector summedVector(dimensions);
    for (size_type i = 0; i < summedVector.dimensions; ++i) {
        summedVector[i] = static_cast<element_type>(data[i] + vectorIn[i]);
    }
    return summedVector;
}

//Subtraction Operator Overload - Vector Subtraction
const Vector Vector::operator -(const Vector& vectorIn) const {
    if(dimensions != vectorIn.dimensions) {
        std::cerr << "Error: Vectors must be of the same size for vector subtraction\n";
        exit(1);
    }
    Vector subtractedVector(dimensions);
    for (size_type i = 0; i < subtractedVector.dimensions; ++i) {
        subtractedVector[i] = static_cast<element_type>(data[i] - vectorIn[i]);
    }
    return subtractedVector;
}

//Multiplication Operator Overload - Dot Product
const element_type Vector::operator *(const Vector& vectorIn) const {
    if(dimensions != vectorIn.dimensions) {
        std::cerr << "Error: Vectors must be of the same size for dot product\n";
        exit(1);
    }
    element_type dotProduct = 0;
    for (size_type i = 0; i < dimensions; ++i) {
        dotProduct += data[i] * vectorIn.data[i];
    }
    return dotProduct;
}

//Division Operator Overload - Cross Product
const Vector Vector::operator /(const Vector& vectorIn) const {
    if(dimensions != 3 || vectorIn.dimensions != 3) {
        std::cerr << "Error: Vectors must both be of dimension 3\n";
        exit(1);
    }
    Vector crossProduct(3);
    crossProduct[0] = (data[1]*vectorIn[2] - data[2]*vectorIn[1]);  
    crossProduct[1] = (data[2]*vectorIn[0] - data[0]*vectorIn[2]); 
    crossProduct[2] = (data[0]*vectorIn[1] - data[1]*vectorIn[0]); 
    return crossProduct;
}

//magnitude Function
const element_type Vector::magnitude() const {
    element_type sumOfSquares = 0.;
    for (size_type i = 0; i < dimensions; ++i) {
        sumOfSquares += pow(data[i],2);
    }
    return sqrt(sumOfSquares);
}

//angleBetweenVectors Function
const element_type angleBetweenVectors(const Vector& vectorIn1, const Vector& vectorIn2) {
    if(vectorIn1.dimensions != vectorIn2.dimensions) {
        std::cerr << "Error - must be of same dimension" << "\n";
        exit(1);
    }
    double cosineAngle = ( (vectorIn1*vectorIn2) / ((vectorIn1.magnitude()) * (vectorIn2.magnitude())) );
    double radAngle = acos(cosineAngle);       //Angle in Radians
    return ( radAngle * (180/M_PI) );          //Return angle in degrees
    
}

//distanceBetweenPoints Function
const element_type distanceBetweenPoints(const Vector& vectorIn1, const Vector& vectorIn2) {
    if(vectorIn1.dimensions != vectorIn2.dimensions) {
        std::cerr << "Error - must be of same dimension" << "\n";
        exit(1);
    }
    double sumOfSquares = 0;
    for(size_type i = 0; i < vectorIn1.dimensions; ++i) {
        sumOfSquares += pow((vectorIn1[i] - vectorIn2[i]),2);
    }
    return sqrt(sumOfSquares);
}

//Insertion Operator Overload
std::ostream& operator <<(std::ostream& outStream, const Vector& vectorIn) {
    outStream << "{";
    for (size_type i = 0; i < vectorIn.getDimensions(); ++i) {
        if(i < (vectorIn.getDimensions() - 1)) {
            outStream << vectorIn[i] << ",";
        }
        else {
            outStream << vectorIn[i];
        }
    }
    outStream << "}";
    return outStream;
}

//Extraction Operator Overload
std::istream& operator >>(std::istream& inStream, Vector& vectorIn) {     
    char eatChar;
    if(!(inStream >> eatChar)) {
        std::cin.clear(); 
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        std::cerr << "\nInvalid Input." << std::endl;
        return inStream;
    }
    for (size_type i = 0; i < vectorIn.getDimensions(); ++i) {      
        if(!(inStream >> vectorIn[i])) {
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::cerr << "\nInvalid Input." << std::endl;
            return inStream;
        }
        else if(!(inStream >> eatChar)) {
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::cerr << "\nInvalid Input." << std::endl;
            return inStream;
        }
    } 
    return inStream;
}