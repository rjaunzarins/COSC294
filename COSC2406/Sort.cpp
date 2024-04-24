#include <iostream>

int data[10];
int size = 10;
void sort(int*, int);

void sort2( int *arr, int size ) {
    for ( int i = 0; i < size - 1; ++i ) {
        for ( int j = 1; j < size - i; ++j ) {
            if ( arr[j] < arr[j - 1] ) {
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
                //swap( array[j], array[j - 1] );
            }
        }
    }
}

int main() { // 10 marks
    srand(time(0));
    for ( int i = 0; i < 10; ++i ) {
        data[i] = rand()%20 + 1;
    }
    for ( int i = 0; i < 10; ++i ) {
        std::cout << data[i];
        if ( i != 9 )
        std::cout << ", ";
    }
    std::cout << std::endl;
    sort2( data, 10 );
    for ( int i = 0; i < 10; ++i ) {
        std::cout << data[i];
        if ( i != 9 )
        std::cout << ", ";
    }
}

void sort( int *data, int size ) { // 10 marks
    for ( int i = 0; i < size - 1; ++i ) {
        int min = i;
        for ( int j = i+1; j < size; ++j ) {
            if ( data[j] < data[min] ) {
                min= j;
            }
        }
        if ( min != i ) {
            int temp = data[i];
            data[i] = data[min];
            data[min] = temp;
        }
    }
}


