// #include <iostream>
// #include <vector>

// class Vector {
//     public:
//         Vector(size_t dimensions);                              //Constructor
//         Vector(const Vector& v);                                //Copy Constructor - Pass by reference - const so original cannot be changed
//         size_t getDimensions() const { return dimensions; };    // Allows for inlining
//         void reset();
//         friend std::ostream& operator <<(std::ostream& outStream, const Vector v);
//         friend std::istream& operator >>(std::istream& inStream, Vector v);
//     private:
//         size_t dimensions;
//         std::vector<double> array;
        
// };