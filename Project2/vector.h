#include <vector>

class Vector {
    public:
        Vector(unsigned int dimensions);        //Constructor
        Vector(const Vector& v);                     //Copy Constructor - Pass by reference - const so original cannot be changed
        unsigned int getDimensions() { return dimensions; };    // Allows for inlining
        void reset();
    private:
        unsigned int dimensions;
        std::vector<double> array;
};
