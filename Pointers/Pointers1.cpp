#include <iostream>


std::vector<int> twoSum(std::vector<int>& nums, int target);

void printNumber( int* numberPtr ) {
    std::cout << *numberPtr << "\n";
}

void printLetter( char* charPtr ) {
    std::cout << *charPtr << "\n";
}

void print( void* ptr, char type ) {            //Compiler will not catch if you pass wrong type as another -> use with discretion
    switch(type) {
        case 'i': std::cout << "Int: " << *(int*)ptr << "\n"; break;
        case 'd': std::cout << "Double: " << *(double*)ptr << "\n"; break;
        case 'f': std::cout << "Float: " << *(float*)ptr << "\n"; break;
        case 'c': std::cout << "Char: " << *(char*)ptr << "\n";   break;
        default: std::cout << "Error: Unknown Type\n";
    }
}



int main() {

    int n = 5;
    std::cout << "n: " << n << "\n";
    std::cout << "Address of n: " << &n << "\n";
    int* ptr = &n;
    std::cout << "Address of ptr: " << ptr << "\n";
    std::cout << "Value at address ptr is pointing to: " << *ptr << "\n";
    *ptr = 6;
    std::cout << "Change value at address ptr is pointing to: " << *ptr << "\n";
    std::cout << "n: " << n << "\n";

    int* ptr2;
    //*ptr2 = 5;    //ptr2 has no address --> cannot do this
    int m = 7;
    std::cout << "m: " << m << "\n";
    std::cout << "Address of m: " << &m << "\n";
    ptr2 = &m;      //You must do this after initializing m
    std::cout << "Address of ptr2: " << ptr2 << "\n";
    std::cout << "Value at address ptr2 is pointing to: " << *ptr2 << "\n";
    *ptr2 = 10;     // Now you can change the value at that address
    std::cout << "Change value in address ptr2 is pointing to: " << *ptr2 << "\n";

    //--------------------------------------------
    std::cout << "--------------------------------------------\n";
    int number = 5;
    //printNumber(&number);     //not needed with 'print' function
    char letter = 'c';
    //printLetter(&letter);     //not needed with 'print' function
    print(&number, 'i');        //int type
    print(&letter, 'c');        //char type
    print(&letter, 'b');        //unknown type
    print(&letter, 'i');        //pass char as int -- WRONG!

    //--------------------------------------------
    std::cout << "--------------------------------------------\n";

    constexpr int size = 5;
    int arr[size] = {1,1,2,3,5};
    std::cout << "Address of arr: " << arr << " \n";                //Print address of arr
    std::cout << "Address of arr[0]: " << &arr[0] << "\n";
    std::cout << "Address of arr[1]: " << &arr[1] << "\n";
    std::cout << "Address of arr[2]: " << &arr[2] << "\n";
    std::cout << "Address of arr[3]: " << &arr[3] << "\n";
    std::cout << "Address of arr[4]: " << &arr[4] << "\n\n";
    std::cout << "Dereferenced arr[0]: " << *(arr) << "\n";         //Print value at address same as arr[0]
    std::cout << "Dereferenced arr[1]: " << *(arr+1) << "\n";
    std::cout << "Dereferenced arr[2]: " << *(arr+2) << "\n";
    std::cout << "Dereferenced arr[3]: " << *(arr+3) << "\n";
    std::cout << "Dereferenced arr[4]: " << *(arr+4) << "\n\n";

    for(size_t i = 0; i < size; ++i) {
        std::cout << "Element[" << i << "]: " << *(arr+i) << "\n";  //Print in loop with dereferenced element
    }

    std::cout << "\n";

    std::vector<int> nums = {3,2,4};
    int target = 6;
    std::vector<int> solution = twoSum(nums,target);
    
    std::cout << "Element: (" << solution[0] << "," << solution[1] << ")\n";
    std::cout << "0%10 = " << 0%10 
              << "\n1%10 = " << 1%10
              << "\n2%10 = " << 2%10
              << "\n3%10 = " << 3%10
              << "\n4%10 = " << 4%10
              << "\n5%10 = " << 5%10
              << "\n6%10 = " << 6%10
              << "\n7%10 = " << 7%10
              << "\n8%10 = " << 8%10
              << "\n9%10 = " << 9%10;

    // std::vector<int> nums = {1,2,3,4,5,6};
    // int* is = &nums[0];
    // int* ie = &nums[nums.size()-1];
    // int size = nums.size();
    // while(is != ie) {
    //        if(*is == *ie) {
    //             std::cout << *is << " + " << *ie << " = " << (*is+*ie) << "\n";
    //        }
    //        //is = *(nums+1); 
    // }

}


//Two Sum - 
// start with sorted elements
//For a given vector add two elements - return a vector of all elemnts that add to target number
// cannot use element more than once
// * start with pointer on vec[0] and vec[end],
//      • if the sum is greater than target, move vec[end]-1 (back one)
//      • if the sum is smaller than target, move vec[0]+1 (up one)



std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::vector<int> solution;
    int head = 0, tail;
    while(head < nums.size()) {
        tail = head+1;
        while(tail < nums.size()) {
            if(nums[head] + nums[tail] == target)
                return solution = {head,tail};
            ++tail;
        }
        ++head;
    }  
    return solution = {-1,-1};  
}





//      0 0 0 0 0
//      1 1 1 1 1
//      2 2 2 2 2
//      3 3 3 3 3
//      4 4 4 4 4