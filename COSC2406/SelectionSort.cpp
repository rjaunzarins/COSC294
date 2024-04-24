// C++ program for implementation of  
// selection sort  
#include <iostream> 
using namespace std; 
  
//Swap function 
void swap(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}  
  
void selectionSort(int arr[], int n)  
{  
    int i, j;  
    for (i = 0; i < n-1; i++) {  
        for (j = i+1; j < n; j++) { 
            if (arr[j] < arr[i]) { 
                swap(&arr[j], &arr[i]); 
            } 
        }
    }  
}  
  
//Function to print an array 
void printArray(int arr[], int size)  {  
    int i;  
    for (i=0; i < size; i++)  
        cout << arr[i] << " ";  
    cout << endl;  
}  
  
// Driver program to test above functions  
int main()  
{  
    int arr[] = {64, 25, 12, 22, 11};  
    int n = sizeof(arr)/sizeof(arr[0]);  
    selectionSort(arr, n);  
    cout << "Sorted array: ";  
    printArray(arr, n);  
    return 0;  
}