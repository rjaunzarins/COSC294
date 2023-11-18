#include <iostream>

template<class T>				
void swapValues( T& var1, T& var2 ) {
    T temp = var1;
    var1 = var2;
    var2 = temp;
}

template<class T>
void bubbleSort(T arr[], size_t size) {
    for(size_t i = 0; i < size-1; ++i) {
        for(size_t j = i+1; j < size; ++j) {
            if(arr[i] > arr[j]) {
                swapValues(arr[i], arr[j]);
            }
        }
    }
}

template<class T>
void printArray(T arr[], size_t size) {
    for (size_t i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout <<"\n"; 
}

template<class T>
void fillArray(T arr[], size_t size) {
    std::cout << "Enter " << size << " values for array: ";
    for(size_t i = 0; i < size; ++i) {
        std::cin >>s arr[i];  
    }      
}

int main() {

    int a = 10;
    int b = 5;
    swapValues(a, b);
    std::cout << "A: " << a << "\nB: " << b << "\n";

    std::cout << "Integer Array - \n";
    constexpr size_t intSize = 5;
    int intArr[intSize];
    fillArray(intArr, intSize);
    printArray(intArr, intSize);
    bubbleSort(intArr, intSize);
    printArray(intArr, intSize);

    std::cout << "Double Array - \n";
    constexpr size_t doubleSize = 5;
    double doubleArr[doubleSize];
    fillArray(doubleArr, doubleSize);
    printArray(doubleArr, doubleSize);
    bubbleSort(doubleArr, doubleSize);
    printArray(doubleArr, doubleSize);
}

