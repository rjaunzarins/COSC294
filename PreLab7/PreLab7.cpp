#include <iostream>

void getArraySize(size_t &size);
void fillArray(double arr[], size_t size);
void fillArrayPointer( double *arr, size_t &size);
double getSum(double arr[], size_t size);
double getAverage(double arr[], size_t size);
void printArray(double arr[], size_t size);
void printArrayPointer(double *arr, size_t size);
void printReverse(double arr[], size_t size);
void printReversePointer(double *arr, size_t size);

int main() {

    size_t size;
    getArraySize(size);
    double *arr = new double[size];
    fillArray(arr, size);
    printArray(arr, size);
    printReverse(arr, size);
    std::cout << "Sum: " << getSum(arr,size) << std::endl;
    std::cout << "Average: " << getAverage(arr,size) << std::endl;
    delete [] arr;
}

void getArraySize(size_t &size) {
    std::cout << "Enter size: ";
    std::cin >> size;
}

void fillArray(double arr[], size_t size) {
    for (size_t i = 0; i < size; ++i) {
        std::cout << "Enter element [" << i << "]: ";
        std::cin >> arr[i];
    }
}

void fillArrayPointer( double *arr, size_t &size) {
    std::cout << "Enter size: ";
    std::cin >> size;
    for (size_t i = 0; i < size; ++i) {
        std::cout << "Enter element [" << i << "]: ";
        std::cin >> arr[i];
    }
}

double getSum(double arr[], size_t size) {
    double sum = 0;
    for (size_t i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return sum;
}

double getAverage(double arr[], size_t size) {
    return (getSum(arr, size) / size);
}

void printArray(double arr[], size_t size) {
    std::cout << "{";
    for (size_t i = 0; i < size; ++i) {
        if(i < size - 1) {
            //std::cout << arr[i] << ",";
            std::cout << *(arr+i) << ",";
        }
        else {
            //std::cout << arr[i];
            std::cout << *(arr+i);
        }
    }
    std::cout << "}\n";
}

void printArrayPointer(double *arr, size_t size) {
    std::cout << "{";
    for (size_t i = 0; i < size; ++i) {
        if(i < size - 1) {
            std::cout << arr[i] << ",";
        }
        else {
            std::cout << arr[i];
        }
    }
    std::cout << "}\n";
}

void printReverse(double arr[], size_t size) {
    std::cout << "{";
    for ( size_t i = size; i --> 0; ) {
        if(i > 0) {
            std::cout << arr[i] << ",";
        }
        else {
            std::cout << arr[i];
        }
    }
    std::cout << "}\n";
}

void printReversePointer(double *arr, size_t size) {
    std::cout << "{";
    for ( int i = size-1; i >= 0; --i ) {
        if(i > 0) {
            std::cout << arr[i] << ",";
        }
        else {
            std::cout << arr[i];
        }
    }
    std::cout << "}\n";
}