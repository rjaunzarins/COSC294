#include <iostream>

    //fillArr - fills in array with random integers
void fillArr(int arr[], int size);

//printArr - prints array
void printArr(int arr[], int size);

void checkEqualElements(int arr[], int size);

void sortDesc(int arr[], int size);

int main() {

    //Declare array size
    constexpr int size = 5;
    //Declare arr
    int arr[size];
    //Fill array with random ints between 1 and 10
    fillArr(arr, size);
    //Print initial array
    std::cout << "Default Array: ";
    printArr(arr, size);
    sortDesc(arr, size);
    checkEqualElements(arr, size);

}


void fillArr(int arr[], int size) {
    //Set seed based on current time
    srand(time(0));
    //Fill array with ints between 1 and 10
    for(int i = 0; i < size; i++) {
        arr[i] = rand()%10 + 1;
    }
}


void printArr(int arr[], int size) {
    //Loop through array and print elements
    for(int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void sortDesc(int arr[], int size) {
    //Loop through array
    for(int i = 0; i < size-1; i++) {
        //Declare max = first array element
        int min = arr[i];
        //Search through array for larger element
        for(int j = i+1; j < size; j++) {
            //If larger element found, swap to arr[i]
            if(arr[j] > min){
                min = arr[j];
                arr[j] = arr[i];
                arr[i] = min;
            }
        }
    }
    //Print sorted array
    std::cout << "SortDesc: ";
    printArr(arr, size);
}

void checkEqualElements(int arr[], int size) {
    
    std::cout << "Unique Elements: ";
    for(int i = 0; i < size; i++) {
        bool unique = true;
        for(int j = 0; j < size; j++) {
            if(i != j) {
                if(arr[i] == arr[j]) {
                    unique = false;
                }
            }
        }
        if(unique) {
            std::cout << arr[i] << " ";
        }
    }
    std::cout << "\nNo more unique elements." << std::endl;
    
}