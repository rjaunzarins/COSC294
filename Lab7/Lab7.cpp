#include <iostream>

class DynamicArray {
    public:
        DynamicArray(size_t size = 0); 
        ~DynamicArray();
        size_t size() const { return arrSize; };
        double *arr;
    private:
        size_t arrSize;
};

void fillArray(double arr[], size_t size);
void printArray(double arr[], size_t size);
void printReverse(double arr[], size_t size);
double getAverage(double arr[], size_t size);
double getSum(double arr[], size_t size);
void getArraySize(size_t &size);

int main() {

    size_t size;
    getArraySize(size);
    DynamicArray arr1(size);
    fillArray(arr1.arr, arr1.size());
    printArray(arr1.arr, arr1.size());
    printReverse(arr1.arr, arr1.size());
    std::cout << "Sum = " << (getSum(arr1.arr, arr1.size())) << "\n";
    std::cout << "Average = " << (getAverage(arr1.arr, arr1.size())) << "\n";
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


DynamicArray::DynamicArray(size_t size) {
    arrSize = size;
    arr = new double[arrSize];
}

DynamicArray::~DynamicArray() {
    delete [] arr;
}