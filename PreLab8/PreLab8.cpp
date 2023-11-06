#include <iostream>
#include <fstream>
#include <iomanip>

void formatFile(std::ifstream &inStream, std::ofstream &outStream);
void printToFile(std::ofstream &outStream, double sum);
double readFromFile(std::ifstream &inStream);

int main() {

    std::string filename1 = "DoubleFile.txt";
    std::string filename2 = "SumFile.txt";
    std::string filename3 = "FormatFile.txt";
    std::ifstream inStream(filename1);
    std::ofstream outStream(filename2);
    std::ofstream outStream2(filename3);
    
    double sum = readFromFile(inStream);
    inStream.close();
    inStream.open(filename1);
    printToFile(outStream, sum);
    formatFile(inStream, outStream2);
}

void formatFile(std::ifstream &inStream, std::ofstream &outStream) {

    double num;
    if( inStream.is_open() ) {
        if( outStream.is_open() ) {
            while( inStream >> num ) {
                outStream << std::setw(8) << num << "\n";
                std::cout << std::setw(8) << num << "\n";
            }
            std::cout << "\nPrinted to file2.\n";
            if( inStream.eof() ) {
                std::cout << "End of file reached2.\n";
            }
            else if( inStream.fail() ) {
                std::cerr << "Failed to read.\n";
                //inStream.clear();
            }
        }
        else {
        std::cerr << "Unable to open file.\n";
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
        std::cerr << "Unable to open file.\n";
    }
}

double readFromFile(std::ifstream &inStream) {
    //std::ifstream inStream(filename);
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
            //inStream.clear();
        }
    }
    else {
        std::cerr << "Unable to open file.\n";
        //inStream.clear();
    }
    return sum;
}