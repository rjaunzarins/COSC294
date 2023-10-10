// #include <vector>
// #include <iostream>
// #include "vector.h"


// // class Vector {
// //     public:
// //         Vector(size_t dimensions);                              //Constructor
// //         Vector(const Vector& v);                                //Copy Constructor - Pass by reference - const so original cannot be changed
// //         size_t getDimensions() const { return dimensions; };    // Allows for inlining
// //         void reset();
// //         friend std::ostream& operator <<(std::ostream& outStream, const Vector v);
// //         friend std::istream& operator >>(std::istream& inStream, Vector v);
// //     private:
// //         size_t dimensions;
// //         std::vector<double> array;
        
// // };


// // int main() {
// //     Vector v1(10);
// //     std::cout << "Dimensions: " << v1.getDimensions() << std::endl;
// //     // for (size_t i = 0; i < v1.getDimensions(); i++)
// //     // {
// //     //     std::cout << v1.array[i] << " " << std::endl;
// //     // }
// //     Vector v2(v1);
// //     std::cout << v1 << std::endl;
// //     std::cout << "Dimensions: " << v2.getDimensions() << std::endl;
// //     std::cout << v2 << std::endl;
    

// // }

// Vector::Vector(size_t dimensions) : dimensions(dimensions) {
//     for (size_t i = 0; i < dimensions; i++) {
//         array.push_back(0);
//     }
// }

// Vector::Vector(const Vector& v) {
//     dimensions = v.getDimensions();
//     for (size_t i = 0; i < v.array.size(); i++)
//     {
//         array.push_back(v.array[i]);
//     }
    
// }

// std::ostream& operator <<(std::ostream& outStream, const Vector v) {
//     for (size_t i = 0; i < v.array.size(); ++i) {
//        outStream << v.array[i] << " " << std::endl;
//     }
//     return outStream;
// }
        
// std::istream& operator >>(std::istream& inStream, Vector v) {
//     for (size_t i = 0; i < v.array.size(); ++i) {
//        inStream >> v.array[i];
//     }
//     return inStream;
// }