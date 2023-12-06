#include <iostream>
#include <string>
#include <cstring>

void getUserInput(char cStirng2[]);
int characterSearch(char arr[], char c);
void removeCharacter(char arr[], char target);
void printReverseString(char cString[]);
void returnReverseString(char cString[]);
void reverseCString(char cString[]);

int main() {

    char cString[]= "ab ab ab";
    int occurrences;
    occurrences = characterSearch(cString, 'a');
    std::cout << "Occurrences: " << occurrences << "\n";

    //get user input
    std::cout << "Enter a string: ";
    char cString2[50];
    char removeChar;
    getUserInput(cString2);
    printReverseString(cString2);
    reverseCString(cString2);
    std::cout << "Reverse String: " << cString2 << std::endl;
    printReverseString(cString2);

    // std::cout << "Enter character to remove: ";
    // std::cin >> removeChar;

    // //remove char and print
    // removeCharacter(cString2, removeChar);
    // std::cout << "New String: " << cString2 << std::endl;



}

void getUserInput(char cString2[]) {
    if(!std::cin.getline(cString2, 50)) {      //Dereference cString2
        std::cout << "String too large\n";
        exit(1);
    }
}

int characterSearch(char arr[], char target) {
    int i = 0;
    int count = 0;
    while (arr[i] != '\0') {
        if(arr[i] == target) {
            ++count;
        }
        ++i;
    }
    return count;
}

void removeCharacter(char arr[], char target) {
    int i = 0;
    while (arr[i] != '\0') {
        if(arr[i] == target) {
            int j = i;
            if(arr[j] == arr[j+1]) {
                int k = j+1;
                int countSimilar = 1;
                while(arr[j] == arr[k]) {                        
                    ++countSimilar;
                    ++k;
                }
                while (arr[j] != '\0') {
                    arr[j] = arr[j+countSimilar];
                    ++j;
                }    
            }
            else {
                while (arr[j] != '\0') {
                    arr[j] = arr[j+1];
                    ++j;
                }     
            } 
        }
        ++i;
    }
    arr[std::strlen(arr)] = '\0';
}

void printReverseString(char cString[]) {
    //std::cout << "Reverse String: ";
    int len = std::strlen(cString);
    for(int i = len-1; i >= 0; --i)
        std::cout << cString[i];
    std::cout << std::endl;
}

void returnReverseString(char cString[]) {
    // int len = std::strlen(cString);
    // char reverseCString[len];
    // for (int i = len, j = 0; j < len; --i, ++j) 
    //     reverseCString[j] = cString[i];
    // reverseCString[len] = '\0';
    // cString = reverseCString;
}

void reverseCString(char cString[]) {
    size_t length = std::strlen(cString);
    for (size_t i = 0, j = length - 1; i < j; ++i, --j) {
        // Swap characters at positions i and j
        char temp = cString[i];
        cString[i] = cString[j];
        cString[j] = temp;
    }
}