#include <iostream>

template<class T>
class Arr {
    public:
        Arr(size_t size ) : size(size), arr(new T[size]) {}
        void fillArray() {
            std::cout << "Enter " << size << " values for array: ";
            for(size_t i = 0; i < size; ++i) {
            std::cin >> arr[i];  
            } 
        }
        void printArray() {
            for (size_t i = 0; i < size; ++i) {
                std::cout << arr[i] << " ";
            }
            std::cout <<"\n"; 
        }
        void bubbleSort() {}
        void swapValues( T& var1, T& var2 ) {}
    private:
        T *arr;
        size_t size;
};

template<class T>
class Pair {
    public:
        Pair(T firstValue, T secondValue ) : firstValue(firstValue), secondValue(secondValue) {}
        T getFirst() { return firstValue; }
        T getSecond() { return secondValue; }
        T getSum() { return firstValue + secondValue; }
    private:
        T firstValue;
        T secondValue;
};

template<class T>
class third : public Pair<T> {
    public:
        Third( T firstValue, T secondValue, T thirdValue) : Pair<T>(firstValue, secondValue), thirdValue(thirdValue) {}
        T getThird() { return thirdValue; }
        T getSum() { return Pair<T>::getSum() + thirdValue; }
    private:
        T thirdValue;
};





// //Swap the values of two T's
// template<class T>				
// void swapValues( T& var1, T& var2 ) {
//     T temp = var1;
//     var1 = var2;
//     var2 = temp;
// }

// //Sort array in place using swapValues function
// template<class T>
// void bubbleSort(T arr[], size_t size) {
//     for(size_t i = 0; i < size-1; ++i) {
//         for(size_t j = i+1; j < size; ++j) {
//             if(arr[i] > arr[j]) {
//                 swapValues(arr[i], arr[j]);
//             }
//         }
//     }
// }

// //Print the array
// template<class T>
// void printArray(T arr[], size_t size) {
//     for (size_t i = 0; i < size; ++i) {
//         std::cout << arr[i] << " ";
//     }
//     std::cout <<"\n"; 
// }

// //Fill an array manually
// template<class T>
// void fillArray(T arr[], size_t size) {
//     std::cout << "Enter " << size << " values for array: ";
//     for(size_t i = 0; i < size; ++i) {
//         std::cin >> arr[i];  
//     }      
// }

int main() {

    // int a = 10;
    // int b = 5;
    // swapValues(a, b);
    // std::cout << "A: " << a << "\nB: " << b << "\n";

    // std::cout << "Integer Array - \n";
    // constexpr size_t intSize = 5;
    // int intArr[intSize];
    // fillArray(intArr, intSize);                 //Fill int array
    // printArray(intArr, intSize);                //Print unsorted int array
    // bubbleSort(intArr, intSize);                //Sort int array
    // printArray(intArr, intSize);                //Print sorted int array

    // std::cout << "Double Array - \n";
    // constexpr size_t doubleSize = 5;
    // double doubleArr[doubleSize];
    // fillArray(doubleArr, doubleSize);           //Fill double array
    // printArray(doubleArr, doubleSize);          //Print unsorted double array
    // bubbleSort(doubleArr, doubleSize);          //Sort double array
    // printArray(doubleArr, doubleSize);          //Print sorted double array
    Arr<int> array(5);
    array.fillArray();
    array.printArray();
}

