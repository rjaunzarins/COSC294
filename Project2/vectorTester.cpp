//Rhy Jaunzarins - 0404377, Kaylee Joyce - 0383068

#include <iostream>
#include <cmath>
#include <ctime>
#include "vector.h"

using element_type = double;
using size_type = unsigned int;


//Set double precision to specified amount
void setPrecision(int precision);
//File vector data with random doubles
void fillVector(Vector& vectorIn);
//Return a random double between -10 and 10
int getRandomDouble();


int main() {

    srand(time(0));
    setPrecision(2);                                                                                            //Set to two decimal places

    std::cout << "\n--------------- User Input ---------------\n";
    //cin & cout Overloads 
    std::cout << "Enter vector dimensions: ";
    size_type userSize;
    std::cin >> userSize;
    Vector userVector(userSize);                                                                                //Constructor       
    std::cout << "Enter userVector vector: ";
    std::cin >> userVector;                                                                                     //Overloaded extraction operator
    std::cout << "\nuserVector Dimensions: " << userVector.getDimensions() << std::endl;                        //getDimensions()
    std::cout << "userVector: " << userVector << "\n\n";                                                        //Overloaded insertion operator


    //Constructor Overloads
    std::cout << "\n--------- Constructor Overloads ----------" << "\n";
    Vector constructVector(3);
    fillVector(constructVector);
    std::cout << "constructVector: " << constructVector << "\n";
    Vector copyConstructVector(constructVector);                                                                //Copy constructor
    std::cout << "\ncopyConstructVector Dimensions: " << copyConstructVector.getDimensions() << std::endl;
    std::cout << "copyConstructVector: " << copyConstructVector << "\n";
    std::cout << "constructVector after copy: " << constructVector << "\n";                                     //Vector.data still contains data
    Vector moveConstructVector(std::move(constructVector));                                                     //Move constructor
    std::cout << "\nmoveConstructVector Dimensions: " << moveConstructVector.getDimensions() << std::endl;
    std::cout << "moveConstructVector: " << moveConstructVector << "\n";
    std::cout << "constructVector after move: " << constructVector << "\n\n";                                   //Vector.data pointing to nullptr


    //Assignment Overloads
    std::cout << "\n----------- Assignment Overloads ----------" << "\n";
    Vector assignVector(3);
    fillVector(assignVector);
    std::cout << "assignVector: " << assignVector << "\n";
    Vector copyAssign;
    copyAssign = assignVector;                                                                                  //Copy assignment operator
    std::cout << "\ncopyAssignVector: " << copyAssign << "\n";
    std::cout << "assignVector after copy: " << assignVector << "\n";
    Vector moveAssign;
    moveAssign = std::move(assignVector);                                                                       //Move assignment operator
    std::cout << "\nmoveAssignVector: " << moveAssign << "\n";
    std::cout << "assignVector after move: " << assignVector << "\n";
    moveAssign.reset();                                                                                         //reset() function
    std::cout << "\nReset moveAssign: " << moveAssign << "\n";                        


    //Vectors for Scalar/Arithmetic Overloads
    std::cout << "\n----------- Calculation Vectors -----------\n";
    Vector calcVect1;                                                                                           //Default constructor
    fillVector(calcVect1);
    std::cout << "calcVect1: " << calcVect1 << "\n";  
    Vector calcVect2;
    fillVector(calcVect2);
    std::cout << "calcVect2: " << calcVect2 << "\n"; 
    
    
    //Scalar Overloads
    std::cout << "\n------------ Scalar Overloads -------------" << "\n";
    std::cout << "Scalar Multiplication: " << (calcVect1 * 3.4) << "\n";                                        //Scalar multiplication
    std::cout << "Scalar Division: " << (calcVect1 / 5.3) << "\n";                                              //Scalar division
    std::cout << "Scalar Subtraction: " << (calcVect1 - 1.2) << "\n";                                           //Scalar subtraction
    std::cout << "Scalar Addition: " << (calcVect1 + 2.3) << "\n";                                              //Scalar addition

    //Vector Arithmetic Overloads
    std::cout << "\n------- Vector Arithmetic Overloads -------" << "\n";
    std::cout << "Dot product: " << (calcVect1*calcVect2) << "\n";                                              //Dot product
    std::cout << "Cross Product: " << (calcVect1/calcVect2) << "\n";                                            //Cross product
    std::cout << "Subtraction: " << (calcVect1-calcVect2) << "\n";                                              //Vector subtraction
    std::cout << "Addition: " << (calcVect1+calcVect2) << "\n";                                                 //Vector addition

    //Additional Calculations
    std::cout << "\n--------- Additional Calculations ---------" << "\n";
    std::cout << "calcVect1 Magnitude = " << calcVect1.magnitude() << "\n";
    std::cout << "calcVect2 Magnitude = " << calcVect2.magnitude() << "\n";
    std::cout << "Angle Between Vectors = " << angleBetweenVectors(calcVect1,calcVect2) << "°\n";
    std::cout << "Distance Between Points = " << distanceBetweenPoints(calcVect1,calcVect2) << "\n\n";
}


void setPrecision(size_type precision) {
    std::cout.setf(std::ios::fixed);
    std::cout.setf(std::ios::showpoint);
    std::cout.precision(precision);
}

element_type getRandomElementType() {
    //Random int betwenn -1000 and 1000
    int randInt = rand() % 2001 - 1000;
    return (static_cast<element_type>(randInt)/100.0);
}

void fillVector(Vector& vectorIn) {
    for(size_type i = 0; i < vectorIn.getDimensions(); ++i) {
        vectorIn[i] = getRandomElementType();                                                               
    }
}