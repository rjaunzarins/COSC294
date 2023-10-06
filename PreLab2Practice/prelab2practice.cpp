#include <iostream> // For I/O
#include <fstream>  // For File Input/Output
#include <string>   // For strings
#include <cstdlib>  // For rand and srand


int main() {

    int n1, n2, max;
    n1 = 10;
    n2 = 20;

    /*
    if(n1 > n2)
        max = n1;
    else    
        max = n2;
    */ 

    //Same statement with conditional operator
     max = (n1 > n2) ? n1 : n2;

     std::cout << "Max = " << max << std::endl;

     //FILE I/O
     std::string input;
     std::ifstream inputStream; // For file input
     std::ofstream outputStream; // For file output
    inputStream.open("text.txt");
    outputStream.open("text2.txt");
    
    while(inputStream >> input){
        std::cout << input << " "; //Writing to std::cout
        outputStream << input << " "; //Writing to "text2.txt"
    }
    inputStream.close();
    outputStream.close();

    /*
    srand(time(0));
    int random = rand()%10;
    std::cout << random << std::endl;
    */
}