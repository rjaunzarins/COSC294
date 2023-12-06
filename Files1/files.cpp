#include <iostream>
#include <fstream>
#include <sstream>

void printToFile(const std::string& filename, const std::string& text);
void appendToFile(const std::string& filename, const std::string& text);
void readFromFile(const std::string& filename);
void readLineFromFile(const std::string& filename);

int main() {
    
    std::string stringToFile = "Hello this is the string to print to file.";
    std::cout << "\n";
    printToFile("stringFile.txt", stringToFile);
    appendToFile("stringFile.txt", stringToFile);
    readFromFile("stringFile.txt");
    readLineFromFile("stringile.txt");  // error in name
    readLineFromFile("stringFile.txt");
}

void printToFile(const std::string& filename, const std::string& text) {
    std::ofstream outStream(filename);
    if( outStream.is_open() ) {
        outStream << text << std::endl;
        std::cout << "Printed to file.\n";
    }
    else {
        std::cerr << "Unable to open file.\n";
    }
}

void appendToFile(const std::string& filename, const std::string& text) {
    std::ofstream outStream(filename, std::ios::app);   //Open file in append mode
    if( outStream.is_open() ) {
        outStream << text << "\n";
        std::cout << "Appended to file.\n";
    }
    else {
        std::cerr << "Unable to open file.\n";
    }
}

void readFromFile(const std::string& filename) {
    std::ifstream inStream(filename);
    std::string str;
    while(inStream >> str) {
        std::cout << str << " ";
    }
    std::cout << std::endl;
}

void readLineFromFile(const std::string& filename) {
    std::ifstream inStream(filename);
    std::string line;
    if( inStream.is_open() ) {
        while( std::getline(inStream, line) ) {
            std::cout << line << "\n";
        }
        if( inStream.eof() ) {
            std::cout << "End of file reached.\n";
        }
        else if( inStream.fail() ) {
            std::cerr << "Failed to read.\n";
            //inStream.clear();
        }
    }
    else {
        std::cerr << "Unable to open file.\n";
        //inStream.clear();
    }
}