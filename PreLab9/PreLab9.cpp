#include <iostream>
#include "PreLab9.h"

int main() {
   
    int n = 500;
    int sum = sumValues(n);
    std::cout << "Sum from 0 to " << n << ": " << sum << "\n";


    int m = 20;
    int fibVal = fibValue(m);
    std::cout << "Fib value at " << m << ": " << fibVal << "\n";


    int numDiscs = 3;
    std::cout << "\nTower of Hanoi:\n";
    hanoi(numDiscs, 'A', 'C', 'B');


    int num1 = 24, num2 = 18;
    int commonDenom = gcd(num1, num2);
    std::cout << "\nGCD = " << commonDenom << "\n";


    std::cout << "\nBinary Search: \n";
    int size = 10;
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int search = 8;
    int location = binarySearch(arr, 0, size-1, search);
    std::cout << "Located at: " << location << "\n";


    int numToSum = 1358901;
    int sumDigits = sumOfDigits(numToSum);
    std::cout << "Sum of digits of " << numToSum << " is: " << sumDigits << "\n";
}

//Return sum of values between 0 and n
int sumValues(int n) {
    if(n == 0) {
        return 0;
    }
    return sumValues(n-1) + n;
}

//Return n number in fib sequence
int fibValue(int n) {
    if(n == 0) {
        return 0;
    }
    if(n == 1) {
        return 1;
    }
    return fibValue(n-1) + fibValue(n-2);
}

//Tower of Hanoi
void hanoi(int num, char fromPeg, char toPeg, char tempPeg) {
    if(num == 0) {
        //std::cout << "flag1\n";
        return;
    }
    //std::cout << "flag2\n";
    hanoi(num - 1, fromPeg, tempPeg, toPeg);
    //std::cout << "flag3\n";
    std::cout << "Move disc " << num << " from peg " << fromPeg << " to peg " << toPeg << "\n";
    hanoi(num - 1, tempPeg, toPeg, fromPeg);
    //std::cout << "flag4\n";
}

//Return Greatest Common Divisor
int gcd(int num1, int num2) {
    if(num1 % num2 == 0) {
        return num2;
    }
    return gcd(num2, num1 % num2);
}

//Return element value is found at (-1 if not found)
int binarySearch(int array[], int first, int last, int value) {
	
    int middle;		
    if(first > last) {
        return -1;
    }
    middle = (first+last) / 2;
    if(array[middle] == value) {
        return middle;
    }
    else if(array[middle] < value) {
        return binarySearch(array, middle+1, last, value);
    }
    else {
        return binarySearch(array, first, middle-1, value);
    }
}

int sumOfDigits(int num) {
    if(num == 0 ) {
        std::cout << "Num0: " << num << "\n";
        return 0;
    }
    if(num < 10) {
        std::cout << "Num<10: " << num << "\n";
        return num;
    }
    std::cout << "Num: " << num << "\n";
    std::cout << "Num%10: " << num%10 << "\n";
    return sumOfDigits(num/10) + num%10;
}

// int productOfTwoNums(int num1, int num2) {
//     if(num2 == 0) {
//         return 0;
//     }
//     return num1 + productOfTwoNums(num2 - 1);   //!not right
// }