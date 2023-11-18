#include <iostream>
#include <string>

using size_type = unsigned int;

size_type A(size_type m, size_type n);
bool palindrome(std::string s);

int main() {
    size_type m = 5;
    size_type n = 0;
    std::cout << "A(0,3): " << A(0,3) << "\n";
    std::cout << "A(0,2): " << A(0,2) << "\n";
    std::cout << "A(1,4): " << A(1,4) << "\n";
    std::cout << "A(2,4): " << A(2,4) << "\n";
    std::cout << "A(3,4): " << A(3,4) << "\n";
    std::cout << "A(4,1): " << A(4,1) << "\n";
    //std::cout << "A(5,0): " << A(5,0) << "\n";

    std::string str1 = "Hello";
    std::string str2 = "aBcba";
    std::string str3 = "abc123";
    std::string str4 = "Abcdcba";

    std::cout << "Palindrome1: " << palindrome(str1) << "\n";
    std::cout << "Palindrome2: " << palindrome(str2) << "\n";
    std::cout << "Palindrome3: " << palindrome(str3) << "\n";
    std::cout << "Palindrome4: " << palindrome("") << "\n";
}

size_type A(size_type m, size_type n) {
    if(m == 0) {
        return n+1;
    }
    if( m > 0 && n == 0) {
        return A(m-1,1);
    }
    if( m > 0 && n > 0 ) {
        return A(m-1, A(m,n-1));
    }
    else {
        return 0;
    }
}

bool palindrome(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    if(s.length() == 0 || s.length() == 1) {
        return true;
    }
    if(s[0] == s[s.length()-1]) {
        return palindrome(s.substr(1,s.length()-2));
    }
    return false;
}

/*
Your lab is to familiarize your self with recursion

1. Create a recursive function, which takes two unsigned integer arguments (m and n), that meets
   the following requirements:
    a. If m is 0, then A(m,n) = n + 1
    b. If m > 0, and n = 0, then A(m,n) is A(m-1, 1)
    c. If m > 0 and n > 0, then A(m,n) = A(m-1, A(m, n-1))
    d. Examples:
        i. A( 0, 3 ) = 4
        ii. A( 0, 2 ) = 3
        iii. A( 1, 4 ) = 6
        iv. A( 2, 4 ) = 11
        v. A( 3, 4 ) = 125
        vi. A( 4, 1 ) = 65533
        vii. A( 5, 0 ) = 65533

2. Create a function to determine if a string is a palindrome using recursion (treat different casing
   as equal: i.e. ‘a’ == ‘A’)
    a. If a string is empty or has a single character, it is a palindrome
    b. Otherwise, if the first and last character are equal, then you need to check the substring
       ignoring the first and last character to see if it is a palindrome
    c. If the first and last character are not the same, then the string is not a palindrome
*/