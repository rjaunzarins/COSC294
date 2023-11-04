#include <iostream>
#include <cmath>
#include <ctime>
#include "vector.h"

void setPrecision(int precision);
int getRandomInt();

int main() {

    srand(time(0));
    // Vector v1(3);
    // std::cout << "Enter V1 array: ";
    // std::cin >> v1;
    // std::cout << "V1 Dimensions: " << v1.getDimensions() << std::endl;
    // std::cout << v1 << std::endl;

    // Vector v5(3);
    // std::cout << "Enter V5 array: ";
    // std::cin >> v5;
    // std::cout << "V5 Dimensions: " << v5.getDimensions() << std::endl;
    // std::cout << v5 << std::endl;
    
    // Vector v2(v1);
    // std::cout << "V2 Dimensions: " << v2.getDimensions() << std::endl;
    // std::cout << v2 << std::endl;
    
    // v2 = std::move(v1);   
    // std::cout << "New V2 Dimensions: " << v2.getDimensions() << std::endl;
    // std::cout << v2 << std::endl;
    // // std::cout << "V1 Dimensions after move: " << v1.getDimensions() << std::endl;
    // // std::cout << v1 << std::endl;

    // Vector v3 = std::move(v2);   
    // std::cout << "V3 Dimensions: " << v3.getDimensions() << std::endl;
    // std::cout << v3 << std::endl;

    // size_type size;
    // std::cout << "Enter V4 size: ";
    // std::cin >> size;
    // Vector v4(size);
    // std::cout << "Enter V4 array: ";
    // std::cin >> v4;
    // std::cout << "V4 Dimensions: " << v4.getDimensions() << std::endl;
    // std::cout << v4 << std::endl;



    Vector v1(abs(-3));
    // v1 = {3,-4,5};
    //v1[0] = getRandomInt(); v1[1] = getRandomInt(); v1[2] = getRandomInt();
    v1[0] = 1; v1[1] = -2; v1[2] = 3;
    std::cout << v1 << "\n";
    // Vector v2(std::move(v1));
    // //v2[0] = getRandomInt(); v2[1] = getRandomInt(); v2[2] = getRandomInt();
    // //v2[0] = 0; v2[1] = 1; v2[2] = 4;
    // std::cout << "V2 address: " << &v2 << "\n";
    // //v2 = {2,7,-3};
    // std::cout << "V1 + 2 = " << v1*2 << "\n";
    // std::cout << "V2 - 2 = " << v2/2 << "\n";



    


    // std::cout << "V1 = " << v1 << "\n";
    // std::cout << "V2 = " << v2 << "\n";
    // element_type v1mag = v1.magnitude();
    // element_type v2mag = v2.magnitude();
    
    // std::cout << "Dot product v1 * v2: " << (v1*v2) << "\n";
    // std::cout << "Cross Product v1 / v2: " << (v1/v2) << "\n";
    // std::cout << "Subtraction v1 - v2: " << (v1-v2) << "\n";
    // std::cout << "Addition v1 + v2: " << (v1+v2) << "\n";

    // setPrecision(2);
    // std::cout << "V1 Magnitude = " << v1mag << "\n";
    // std::cout << "V2 Magnitude = " << v2mag << "\n";
    // std::cout << "Angle Between Vectors = " << angleBetweenVectors(v1,v2) << "°\n";
    // std::cout << "Distance Between Points = " << distanceBetweenPoints(v1,v2) << "\n";

    // v1.reset();
    // std::cout << "Reset V1: " << v1 << "\n";

    // std::cout << __cplusplus << std::endl;
    
}

void setPrecision(int precision) {
    std::cout.setf(std::ios::fixed);
    std::cout.setf(std::ios::showpoint);
    std::cout.precision(precision);
}

int getRandomInt() {
    //Random int betwenn -9 and 9
    return (rand()%20 - 10);
}