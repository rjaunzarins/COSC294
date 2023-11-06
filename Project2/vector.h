//Rhy Jaunzarins - 0404377, Kaylee Joyce - 0383068

#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <cmath>

using size_type = unsigned int;
using element_type = double;

class Vector {
    
    public:
        
        /**
         * Vector Constructor 
         * Precondition: None.
         * @param dimensions The number of dimensions in the data.
         * Postcondition: Initializes a new data of specified size (default = 3),
         * sets member variables, and sets all values in Vector to zero.
        */
        Vector(size_type dimensions = 3);                                   
        
        /**
         * Vector Copy Constructor
         * Preconditiion: A Vector must have been created and initialized.
         * Param: The Vector to be copied
         * Postcondition: Returns a deep copy of passed Vector.
        */
        Vector(const Vector&);                                            
        
        /**
         * Vector Move Constructor
         * Precondition: A Vector must have been created and initialized.
         * Param: The Vector to move
         * Postcondition: Moves all data from incoming Vector to new Vector.
         * Resets all data in incoming Vector to zeroes.
        */
        Vector(Vector&&);                                                 
        
        /**
         * Vector Destructor
         * Precondition: A Vector must have been created and initialized.
         * Postcondition: Deletes data and returns memory to freestore manager.
        */
        ~Vector();                                                          

        /**
         * getDimensions Function
         * Preconditiion: None.
         * Postconditiion:  Returns the number of dimensions in Vector.
        */
        size_type getDimensions() const { return dimensions; };             
        
        /**
         * reset Function
         * Precondition: None.
         * Postcondition: Sets all elements in data to 0.0.
        */
        void reset();                                                       
        
        /**
         * Equality Overload - Copy
         * Precondition: Vectors must have same dimension.
         * Param: The Vector to copy
         * Postcondition: Performs a deep copy of incoming Vector and
         * returns a reference to the new Vector.
        */
        const Vector& operator =(const Vector&) const;                   
        
        /**
         * Equality Overload - Move
         * Precondition: Vectors nust have same dimension.
         * Param: The Vector to move
         * Postcondition: Moves all data from incoming Vector to calling
         * Vector and resets data in incoming Vector to all zeroes. 
         * Returns a reference to the new Vector.
        */
        const Vector& operator =(Vector&&);                      
        
        /**
         * Multiplication Overload - Scalar
         * Precondition: None.
         * Param: The scalar amount to multiply
         * Postcondition: Multiplies each element in data by a scalar.
         * Returns the resulting Vector of the multiplication
        */
        const Vector operator *(element_type) const;                 
        
        /**
         * Division Overload - Scalar
         * Precondition: Scalar passed cannot = 0.
         * Param: The scalar amount to divide
         * Postcondition: Divide each element in data by a scalar.
         * The resulting Vector of the division
        */
        const Vector operator /(element_type) const;                 
        
        /**
         * Addition Overload - Scalar
         * Precondition: None.
         * Param: The scalar amount to add.
         * Postcondition: Adds a scalar amount to each element in data.
         * Returns the resulting Vector of the addition.
        */
        const Vector operator +(element_type) const;                 
        
         /**
         * Subtraction Overload - Scalar
         * Precondition: None.
         * Param: The scalar amount to subtract.
         * Postcondition: Subtracts a scalar amount to each element in data.
         * Returns the resulting Vector of the subtraction.
        */
        const Vector operator -(element_type) const;                 
        
        /**
         * Addition Overload - Vector
         * Precondition: Vectors must have same dimension.
         * Param: The Vector to add.
         * Postcondition: Returns the resulting Vector of the addition.
        */
        const Vector operator +(const Vector&) const;                     
        
        /**
         * Subtraction Overload - Vector
         * Precondition: Vectors must have same dimension.
         * Param: The Vector to subtract.
         * Postcondition: Returns the resulting Vector of the subtraction.
        */
        const Vector operator -(const Vector&) const;                    
        
        /**
         * Multiplication Overload - Dot Product
         * Precondition: Vectors must have same dimension.
         * Param: The Vector to dot product with the calling Vector.
         * Postcondition: Performs the dot product of the calling Vector and
         * passed Vector. Returns the dot product.
        */
        const element_type operator *(const Vector&) const;               
        
        /**
         * Division Overload - Cross Product
         * Precondition: Both Vectors must have dimension = 3.
         * Param: The Vector to cross product with the calling Vector.
         * Postcondition: Performs the cross product of the calling Vector and
         * passed Vector. Returns Vector of cross product.
        */
        const Vector operator /(const Vector&) const;                    
        
        /**
         * Subscript Overload - Non-Const Instances
         * Precondition: Valid index must be passed.
         * Param: The element to retrieve.
         * Postcondition: Returns the value in data at the specified index.
        */
        element_type& operator [](size_type index) { return data[index]; }             
        
        /**
         * Subscript Overload - Const Instances
         * Precondition: Valid index must be passed.
         * Param: The element to access.
         * Postcondition: Returns the value in data at the specified index.
        */
        element_type& operator [](size_type index) const { return data[index]; }     
        
        /**
         * magnitude Function
         * Precondition: A Vector must have been created and initialized.
         * Postcondition: Calculates and returns the magnitude of the calling Vector.
        */
        const element_type magnitude() const;

        /**
         * angleBetweenVectors Function
         * Precondition: The two Vectors must have the same dimensions.
         * Param: The first Vector
         * Param: The second Vector
         * Postcondition: Calculates and returns the angle between two vectors.
        */
        friend const element_type angleBetweenVectors(const Vector&, const Vector&);
        
        /**
         * distanceBetweenPoints Function
         * Precondition: Vectors must have same dimensions.
         * Param: The first Vector.
         * Param: The second Vector.
         * Returns: The distance between the two points.
        */
        friend const element_type distanceBetweenPoints(const Vector&, const Vector&);

    private:
        size_type dimensions;                                              
        element_type *data;                                                
};

    /**
     * Insertion Operator Overload
     * Preconditiion: None.
     * Param: The output stream object to store data to print.
     * Param: The Vector to print.
     * Returns: The modified output to print.
    */
    std::ostream& operator <<(std::ostream&, const Vector&);
    
    /**
     * Extraction Operator Overload
     * Precondition: None.
     * Param: The input stream object to store user input
     * Param:The Vector to store data in
     * Returns: The modified input stream
    */
    std::istream& operator >>(std::istream&, Vector&);

#endif