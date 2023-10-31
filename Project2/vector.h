#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <cmath>

using size_type = size_t;
using element_type = double;

class Vector {
    
    public:
        
        /**
         * Vector Constructor 
         * Initializes dimensions to 3 if no value is passed
         * @param dimensions The number of dimensions in the array
        */
        Vector(size_type dimensions = 3);                                   //Constructor
        
        /**
         * Vector Copy Constructor
         * Performs a deep copy of the members in v
         * @param v The Vector to be copied
        */
        Vector(const Vector& v);                                            //Copy Constructor - Pass by reference - const so original cannot be changed
        
        /**
         * Vector Move Constructor
         * Moves all the data in the incoming Vector into the new Vector
         * Resets all the data in the incoming Vector to all zeros
         * @param v The Vector to move
        */
        Vector(Vector&& v);                                                 //Move Constructor
        
        /**
         * Vector Destructor
         * Delete array and return memory to freestore manager
        */
        ~Vector();                                                          //Destructor

        /**
         * getDimensions Function
         * @return The number of dimensions in Vector
        */
        size_type getDimensions() const { return dimensions; };             //Return the number of dimensions
        
        /**
         * reset Function
         * Sets all elements in array to 0.0
        */
        void reset();                                                       //Reset 
        
        /**
         * Equality Overload - Copy
         * Performs a deep copy of Vector v
         * @param v The Vector to copy
         * @return A reference to the new Vector
        */
        const Vector& operator =(const Vector& v) const;                    //Deep copy
        
        /**
         * Equality Overload - Move
         * Move all the data in the incoming Vector into the calling Vector
         * Resets all the data in the incoming Vector to all zeros
         * @param v The Vector to move
         * @return A reference to the new Vector
        */
        const Vector& operator =(Vector&& v) noexcept;                      //Move   
        
        /**
         * Multiplication Overload - Scalar
         * Multiply each element in array by a scalar amount
         * @param scalar The scalar amount to multiply
         * @return The resulting Vector of the multiplication
        */
        const Vector operator *(element_type scalar) const;                 //Scalar Mul - Member
        
        /**
         * Division Overload - Scalar
         * Divide each element in array by a scalar amount
         * @param scalar The scalar amount to divide
         * @return The resulting Vector of the division
        */
        const Vector operator /(element_type scalar) const;                 //Scalar Div - Member
        
        /**
         * Addition Overload - Scalar
         * Add a scalar amount to each element in array
         * @return The resulting Vector of the addition
        */
        const Vector operator +(element_type scalar) const;                 //Scalar Add - Member
        
        /**
         * Subtraction Overload - Scalar
         * Subtract a scalar amount from each element in array
         * @param scalar The scalar amount to subtract
         * @return The resulting Vector of the subtraction
        */
        const Vector operator -(element_type scalar) const;                 //Scalar Sub - Member
        
        /**
         * Addition Overload - Vector
         * Each corresponding element of the Vectors are added
         * @param v The Vector to add
         * @return The resulting Vector of the addition
        */
        const Vector operator +(const Vector& v) const;                     //Vector Add
        
        /**
         * Subtraction Overload - Vector
         * Each corresponding element Vector v are subtracted from array
         * @param v The Vector to subtract
         * @return The resulting Vector of the subtraction
        */
        const Vector operator -(const Vector& v) const;                     //Vector Sub
        
        /**
         * Multiplication Overload - Dot Product
         * Performs the dot product on calling Vector and v
         * @param v The Vector to multiply by
         * @return The dot product of the two Vectors
        */
        const element_type operator *(const Vector& v) const;               //Vector Mult (dot product)
        
        /**
         * Division Overload - Cross Product
         * Performs the cross product on calling Vector and v
         * @param v The Vector to divide by
         * @return The resulting Vector of the cross product
        */
        const Vector operator /(const Vector& v) const;                     //Vector Div (cross product
        
        /**
         * Subscript Overload - Non-Const Instances
         * Allows access to the elements of array with the subscript 
         * operator for non-const instances
         * @param index The element to access
         * @return The value in array at the specified index
        */
        double& operator [](int index) { return array[index]; }             //[] Overload
        
        /**
         * Subscript Overload - Const Instances
         * Allows access to the elements of array with the subscript 
         * operator for const instances
         * @param index The element to access
         * @return The value in array at the specified index
        */
        double& operator [](int index) const { return array[index]; }       //[] Overload const
        
        /**
         * magnitude Function
         * Calculates the magnitude of the calling Vector
         * @return The magnitude of the Vector
        */
        const element_type magnitude() const;

        /**
         * angleBetweenVectors Function
         * Calculates the angle between two vectors of the same dimension
         * @param v1 The first Vector
         * @param v2 The second Vector
         * @return The angle between the two Vectors
        */
        friend const element_type angleBetweenVectors(const Vector& v1, const Vector& v2);
        
        /**
         * distanceBetweenPoints Function
         * Calculates the distance between the points of two Vectors
         * of the same dimension
         * @param v1 The first Vector
         * @param v2 The second Vector
         * @return The distance between the two points
        */
        friend const element_type distanceBetweenPoints(const Vector& v1, const Vector& v2);
        
        /**
         * Insertion Operator Overload
         * Allows printing of a Vector object using the Insertion operator
         * @param outStream The output stream object to store data to print
         * @param v The Vector to print
         * @return The modified output to print
        */
        friend std::ostream& operator <<(std::ostream& outStream, const Vector& v);
        
        /**
         * Extraction Operator Overload
         * Allows the use of user input for creating a Vector object with 
         * the extraction operator
         * @param inStream The input stream object to store user input
         * @param v The Vector to store data in
         * @return The modified input stream
        */
        friend std::istream& operator >>(std::istream& inStream, Vector& v);

    private:
        size_type dimensions;                                               //The number of dimensions in the array
        element_type *array;                                                //Pointer for element_type array
};

#endif  //VECTOR_H