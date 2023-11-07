#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>

void appendFormatToSumFile(std::ifstream &inStream, std::ofstream &outStream);
void formatToFile(std::ifstream &inStream, std::ofstream &outStream);
void printToFile(std::ofstream &outStream, double sum);
double readFromFile(std::ifstream &inStream);

int main() {

    std::string filename1 = "DoubleFile.txt";
    std::string filename2 = "SumFile.txt";
    std::string filename3 = "FormatFile.txt";
    std::ifstream inStream(filename1);
    std::ofstream outStream(filename2);
    std::ofstream outStream2(filename3);
    std::ofstream outStream3(filename2, std::ios::app);
    
    double sum = readFromFile(inStream);
    inStream.close();
    inStream.open(filename1);
    printToFile(outStream, sum);
    //formatToFile(inStream, outStream2);
    appendFormatToSumFile(inStream, outStream3);
}

void formatToFile(std::ifstream &inStream, std::ofstream &outStream) {
    double num;
    std::stringstream str;
    if( inStream.is_open() ) {
        str.setf(std::ios::fixed);
        str.setf(std::ios::showpoint);
        while( inStream >> num ) {
            str << std::setprecision(2) << num << "\n";
        }
        if( inStream.eof() ) {
            std::cout << "End of file reached2.\n";
        }
        else if( inStream.fail() ) {
            std::cerr << "Failed to read.\n";
        }
        outStream << str.str();
        std::cout << "\nPrinted.\n";
    }
    else {
        std::cerr << "Unable to open file.\n";
    }    
}

void appendFormatToSumFile(std::ifstream &inStream, std::ofstream &outStream) {
    double num;
    std::stringstream str;
    if( inStream.is_open() ) {
        if( outStream.is_open() ) {
            str.setf(std::ios::fixed);
            str.setf(std::ios::showpoint);
            while( inStream >> num ) {
                str << std::setprecision(2) << num << "\n";
            }
            if( inStream.eof() ) {
                std::cout << "End of file reached2.\n";
            }
            else if( inStream.fail() ) {
                std::cerr << "Failed to read.\n";
            }
            outStream << "Doubles read for sum:\n";
            outStream << str.str();
            outStream << "Printed.\n";
        }
        else {
            std::cerr << "Unable to open.\n";
        }
    }
    else {
        std::cerr << "Unable to open file.\n";
    }    
}


void printToFile(std::ofstream &outStream, double sum) {
    if( outStream.is_open() ) {
        outStream.setf(std::ios::fixed);
        outStream.setf(std::ios::showpoint);
        outStream << std::setprecision(2) << sum << std::endl;
        std::cout << sum << "\nPrinted to file1.\n";
    }
    else {
        std::cerr << "Unable to open output file.\n";
    }
}

double readFromFile(std::ifstream &inStream) {
    double num;
    double sum = 0;
    
    if( inStream.is_open() ) {
        while( inStream >> num ) {
            sum += num;
            std::cout << num << " ";
        }
        std::cout << "\n";
        if( inStream.eof() ) {
            std::cout << "End of file reached1.\n";
        }
        else if( inStream.fail() ) {
            std::cerr << "Failed to read.\n";
        }
    }
    else {
        std::cerr << "Unable to open input file.\n";
    }
    return sum;
}