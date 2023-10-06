#include <iostream>
#include <ctime>

//fillArr - fills in array with random integers
void fillArr(int arr[], int size);

//printArr - prints array
void printArr(int arr[], int size);

void sortArray(int arr[], int size);

void sortAsc(int arr[], int size);

void sortDesc(int arr[], int size);

void bubbleSortAsc(int arr[], int size);

void bubbleSortDesc(int arr[], int size);

void selectionSortAsc(int arr[], int size);

void selectionSortDesc(int arr[], int size);

int binarySearch(int arr[], int size, int value);

int sequentialSearch(int arr[], int size, int value);

void fill2DArray(int arr2D[][5], int size);

void sort2DArrayRows(int arr2D[][5], int size);

void print2DArray(int arr2D[][5], int size);

void sort2DArrayWhole(int arr2D[][5], int size);

bool search2DArray(int arr2D[][5], int size, int value);

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
    //Sort array
    sortArray(arr, size);

    int arr2D[size][size];
    fill2DArray(arr2D, size);
    std::cout << "2D Array: " << std::endl;
    print2DArray(arr2D, size);
    //sort2DArrayRows(arr2D, size);
    sort2DArrayWhole(arr2D, size);
    std::cout << "Enter value to search for: ";
    int value;
    std::cin >> value;
    bool found = search2DArray(arr2D, size, value);
    if(found)
        std::cout << "Element was found" << std::endl;
    else   
        std::cout << "Element was not found" << std::endl;
    
}

void sortArray(int arr[], int size) {
    sortAsc(arr, size);
    sortDesc(arr, size);
    bubbleSortAsc(arr, size);
    bubbleSortDesc(arr, size);
    selectionSortAsc(arr, size);
    selectionSortDesc(arr, size);
    int search;
    std::cout << "Enter value to search for: ";
    std::cin >> search;
    int result = binarySearch(arr, size, search);
    std::cout << "Found at element: " << result << std::endl;
    std::cout << "Enter value to search for: ";
    std::cin >> search;
    result = sequentialSearch(arr, size, search);
    std::cout << "Found at element: " << result << std::endl;
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


void sortAsc(int arr[], int size) {
    //Loop through array
    for(int i = 0; i < size-1; i++) {
        //Declare max = first array element
        int min = arr[i];
        //Search through array for larger element
        for(int j = i+1; j < size; j++) {
            //If larger element found, swap to arr[i]
            if(arr[j] < min){
                min = arr[j];
                arr[j] = arr[i];
                arr[i] = min;
            }
        }
    }
    //Print sorted array
    std::cout << "SortAsc: ";
    printArr(arr, size);
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


void bubbleSortAsc(int arr[], int size) {
    //Loop through array
    for(int i = size -1; i > 0; i--) {
        for(int j = 0; j < i; j++) {
            //If larger element found, swap to arr[i]
            if(arr[j] > arr[j+1]){
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    //Print sorted array
    std::cout << "BubbleSortAsc: ";
    printArr(arr, size);
}


void bubbleSortDesc(int arr[], int size) {
    //Loop through array
    for(int i = size -1; i > 0; i--) {
        for(int j = 0; j < i; j++) {
            //If larger element found, swap to arr[i]
            if(arr[j] < arr[j+1]){
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    //Print sorted array
    std::cout << "BubbleSortDesc: ";
    printArr(arr, size);
}


void selectionSortAsc(int arr[], int size) {
    //Loop through array from 0 to second last element
    for(int i = 0; i < size-1; i++) {
        //Set minIndex to first element and minValue to value at first element
        int minIndex = i;
        int minValue = arr[i];
        //Loop through second time from i+1 to last element
        for(int j = i+1; j < size; j++) {
            //If arr[j] is less than arr[minIndex]
            if(arr[j] < arr[minIndex]){
                //Assign arr[j] to minValue
                minValue = arr[j];
                //Assign j to minIndex
                minIndex = j;
            }
        }
        //When loop has been searched, swap minValue to arr[i] and arr[i] to arr[minIndex]
        arr[minIndex] = arr[i];
        arr[i] = minValue;
    }
    std::cout << "SelectionSortAsc: ";
    printArr(arr, size);
}


void selectionSortDesc(int arr[], int size) {
    //Loop through array from 0 to second last element
    for(int i = 0; i < size-1; i++) {
        //Set maxIndex to first element and maxValue to value at first element
        int maxIndex = i;
        int maxValue = arr[i];
        //Loop through second time from i+1 to last element
        for(int j = i+1; j < size; j++) {
            //If arr[j] is greater than arr[maxIndex]
            if(arr[j] > arr[maxIndex]) {
                //Assign arr[j] to maxValue
                maxValue = arr[j];
                //Assign j to maxIndex
                maxIndex = j;
            }
        }
        //When loop has been searched, swap maxValue to arr[i] and arr[i] to arr[maxIndex]
        arr[maxIndex] = arr[i];
        arr[i] = maxValue;
    }
    std::cout << "SelectionSortDesc: ";
    printArr(arr, size);
}

//Use binary search to find value. Array must be in ascending order
int binarySearch(int arr[], int size, int value) {
    
    //Sort array in ascending order - required for binary search
    selectionSortAsc(arr, size);
    
    int first = 0;
    int last = size - 1;
    int middle;
    int position = -1;
    bool found = false;
    
    //While value is not found and there are elements to search
    while(!found && first <= last){
        //Calculate midpoint
        middle = (first + last) / 2;
        //If midpoint matches value, found
        if(arr[middle] == value) {
            found = true;
            position = middle;
        }
        //else, if middle is greater than value
        else if(arr[middle] > value) 
           last = middle - 1;
        //else, if middle is less than value
        else    
            first = middle + 1;
    }
    return position;
}


int sequentialSearch(int arr2D[], int size, int value) {
    for(int i = 0; i < size; i++) {
        if(arr2D[i] == value)
            return i;
    }
    return -1;
}


void fill2DArray(int arr2D[][5], int size) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            arr2D[i][j] = rand()%10 + 1;
        }
    }
}


void print2DArray(int arr2D[][5], int size) {
    
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            std::cout << arr2D[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}


void sort2DArrayRows(int arr2D[][5], int size) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            for(int k = i; k < size; k++) {
                for(int l = j+1; l < size; l++) {
                    if(arr2D[i][j] > arr2D[k][l]) {
                        int temp = arr2D[i][j];
                        arr2D[i][j] = arr2D[k][l];
                        arr2D[k][l] = temp;
                    }
                }
            }
        }
    }
    std::cout << "Sorted 2D Aray By Row: " << std::endl;
    print2DArray(arr2D, size);
}


void sort2DArrayWhole(int arr2D[][5], int size) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            for(int k = 0; k < size; k++) {
                for(int l = 0; l < size; l++) {
                    if(arr2D[i][j] < arr2D[k][l]) {
                        int temp = arr2D[i][j];
                        arr2D[i][j] = arr2D[k][l];
                        arr2D[k][l] = temp;
                    }
                }
            }
        }
    }
    std::cout << "Sorted 2D Aray Whole: " << std::endl;
    print2DArray(arr2D, size);
}


bool search2DArray(int arr2D[][5], int size, int value) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            if(arr2D[i][j] == value)
                return true;
        }
    }
    return false;
}