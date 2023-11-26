#include <iostream>
#include <cmath>

//Swap the values of two T's
template<class T>				
void swapValues( T& var1, T& var2 ) {
    T temp = var1;
    var1 = var2;
    var2 = temp;
}

//Selection Sort Function
template<class T>
void selectionSort(T arr[], size_t size) {
    for(size_t i = 0; i < size-1; ++i) {
        size_t minIndex = i;
        for(size_t j = i+1; j < size; ++j) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swapValues(arr[i], arr[minIndex]);
    }
}

// Specialized template instantiation for doubles
template<>
void selectionSort<double>(double arr[], size_t size) {
    for (size_t i = 0; i < size - 1; ++i) {
        size_t minIndex = i;
        for (size_t j = i + 1; j < size; ++j) {
            if (std::abs(arr[j]) < std::abs(arr[minIndex])) {
                minIndex = j;
            }
        }
        swapValues(arr[i], arr[minIndex]);
    }
}

//Print Array
template<class T>
void printArray( T arr[], size_t size) {
        for(size_t i = 0; i < size; ++i) {
        std::cout << arr[i];
        if(i < size-1) {
            std::cout << ",";
        }
    }
    std::cout << "\n";
}

int main() {
    size_t size = 5;
    int intArr[] = {5,4,3,2,1};
    double doubleArr[] = {5.5,-7.4,3.3,-6.2,1.1};

    printArray(intArr, size);
    selectionSort(intArr, size);
    printArray(intArr, size);

    printArray(doubleArr, size);
    selectionSort(doubleArr, size);
    printArray(doubleArr, size);
}



