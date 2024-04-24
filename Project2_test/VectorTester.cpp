//Rhy Jaunzarins - 0404377, Kaylee Joyce - 0383068

#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>
#include "vector.h"

using element_type = double;
using size_type = unsigned int;


void setElementPrecision(size_type precision);                                                                      //Set double precision to specified amount
void fillVector(Vector& vectorIn);                                                                                  //File vector data with random doubles
element_type getRandomElementType();                                                                                //Return a random double between -10 and 10


int main() {

    srand(time(0));
    setElementPrecision(2);                                                                                         //Set to two decimal places

    std::cout << "\n------------------- User Input -------------------\n";
    int userSize = -1;
    while(userSize < 1) {    
        std::cout << "Enter vector dimensions:\t";                                                                      
        std::cin >> userSize; 
    }                                                                                                               //Overloaded extraction operator
    Vector userVector(userSize);
    if(userSize > 0) {                                                                                              //Constructor       
        std::cout << "Enter userVector vector:\t";
        std::cin >> userVector;                                                                                     //Overloaded extraction operator
    }
    std::cout << "\nuserVector Dimensions:\t\t" << userVector.getDimensions() << std::endl;                         //getDimensions()
    std::cout << "userVector:\t\t\t" << userVector << "\n\n";                                                       //Overloaded insertion operator

    //Constructor Overloads
    std::cout << "\n------------- Constructor Overloads --------------" << "\n";
    Vector constructVector(3);
    fillVector(constructVector);
    std::cout << "constructVector:\t\t" << constructVector << "\n";
    Vector copyConstructVector(constructVector);                                                                    //Copy constructor
    std::cout << "\ncopyConstructVector Dimensions: " << copyConstructVector.getDimensions() << std::endl;
    std::cout << "copyConstructVector:\t\t" << copyConstructVector << "\n";
    std::cout << "constructVector after copy:\t" << constructVector << "\n";                                        //Vector.data still contains data
    Vector moveConstructVector(std::move(constructVector));                                                         //Move constructor
    std::cout << "\nmoveConstructVector Dimensions: " << moveConstructVector.getDimensions() << std::endl;
    std::cout << "moveConstructVector:\t\t" << moveConstructVector << "\n";                                         //Show object moved from is emptyy
    std::cout << "constructVector after move:\t" << constructVector << "\n\n";                                      //Construct is now empty


    //Assignment Overloads
    std::cout << "\n--------------- Assignment Overloads --------------" << "\n";
    Vector assignVector(3);
    fillVector(assignVector);
    std::cout << "assignVector:\t\t\t" << assignVector << "\n";
    Vector copyAssign;
    copyAssign = assignVector;                                                                                      //Copy assignment operator
    std::cout << "\ncopyAssignVector:\t\t" << copyAssign << "\n";
    std::cout << "assignVector after copy:" << assignVector << "\n";
    Vector moveAssign;
    moveAssign = std::move(assignVector);                                                                           //Move assignment operator
    std::cout << "\nmoveAssignVector:\t\t" << moveAssign << "\n";
    std::cout << "assignVector after move:\t" << assignVector << "\n";
    moveAssign.reset();                                                                                             //reset() function
    std::cout << "\nReset moveAssign:\t\t" << moveAssign << "\n";                        


    //Vectors for Scalar/Arithmetic Overloads
    std::cout << "\n--------------- Calculation Vectors ---------------\n";
    Vector calcVect1;                                                                                               //Default constructor
    fillVector(calcVect1);
    std::cout << "calcVect1:\t\t\t" << calcVect1 << "\n";  
    Vector calcVect2;
    fillVector(calcVect2);
    std::cout << "calcVect2:\t\t\t" << calcVect2 << "\n"; 
    
    
    //Scalar Overloads
    std::cout << "\n---------------- Scalar Overloads -----------------" << "\n";
    std::cout << "Scalar Multiplication (* 3.4):\t" << (calcVect1 * 3.4) << "\n";                                   //Scalar multiplication
    std::cout << "Scalar Division (/ 5.3):\t" << (calcVect1 / 5.3) << "\n";                                         //Scalar division
    std::cout << "Scalar Subtraction (- 1.2):\t" << (calcVect1 - 1.2) << "\n";                                      //Scalar subtraction
    std::cout << "Scalar Addition (+ 2.3):\t" << (calcVect1 + 2.3) << "\n";                                         //Scalar addition

    //Vector Arithmetic Overloads
    std::cout << "\n----------- Vector Arithmetic Overloads -----------" << "\n";
    std::cout << "Dot product:\t\t\t" << (calcVect1*calcVect2) << "\n";                                             //Dot product
    std::cout << "Cross Product:\t\t\t" << (calcVect1/calcVect2) << "\n";                                           //Cross product
    std::cout << "Subtraction:\t\t\t" << (calcVect1-calcVect2) << "\n";                                             //Vector subtraction
    std::cout << "Addition:\t\t\t" << (calcVect1+calcVect2) << "\n";                                                //Vector addition

    //Additional Calculations
    std::cout << "\n------------- Additional Calculations -------------" << "\n";
    std::cout << "calcVect1 Magnitude =\t\t" << calcVect1.magnitude() << "\n";
    std::cout << "calcVect2 Magnitude =\t\t" << calcVect2.magnitude() << "\n";
    std::cout << "Angle Between Vectors =\t\t" << angleBetweenVectors(calcVect1,calcVect2) << " degrees\n";
    std::cout << "Distance Between Points =\t" << distanceBetweenPoints(calcVect1,calcVect2) << "\n\n";
}


void setElementPrecision(size_type precision) {
    std::cout.setf(std::ios::fixed);
    std::cout.setf(std::ios::showpoint);
    std::cout.precision(precision);
}

element_type getRandomElementType() {
    int randInt = rand() % 2001 - 1000;                                                                             //Random int between -1000 and 1000
    return (static_cast<element_type>(randInt)/100.0);                                                              //Return element_type between -10 and 10
}

void fillVector(Vector& vectorIn) {
    for(size_type i = 0; i < vectorIn.getDimensions(); ++i) {
        vectorIn[i] = getRandomElementType();                                                               
    }
}