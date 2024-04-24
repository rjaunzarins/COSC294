#include <iostream> 
using namespace std; 
  
// Recursive Binary Search function to find the index of an 
// element 'x' in a sorted array 'arr' if elements is 
// present, otherwise it return -1 
  
// low: The index of the first element in the current 
// sub-array high: The index of the last element in the 
// current sub-array 
int binarySearch(int arr[], int low, int high, int x) { 
    if (high >= low) {                                      // Base case: If the search space becomes empty, the element is not present in the array 
        int mid = low + (high - low) / 2;                   // Calculate the middle index to divide the search space in half 
        if (arr[mid] == x)                                  // If the middle element is equal to 'x', we have found the element, return its index 
            return mid; 
        if (arr[mid] > x)                                   // If the middle element is greater than 'x', search in the left half of the array 
            return binarySearch(arr, low, mid - 1, x); 
        return binarySearch(arr, mid + 1, high, x);         // If the middle element is less than 'x', search in the right half of the array 
    } 
    return -1;                                              // If the base case is reached, the element is not present in the array, return -1 
} 
  
int main() { 
    int arr[] = { 2, 3, 4, 10, 40 }; 
    int x = 3;                                             // Element to be searched 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int result = binarySearch(arr, 0, n - 1, x); 
    if (result == -1) 
        cout << "Element is not present in array";
    else
        cout << "Element is present at index " << result << endl; 
}