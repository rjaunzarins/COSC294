#include <iostream>
#include <string>

std::string reverseString(const std::string& input) {
    std::string reversedString = input;
    size_t length = reversedString.length();

    for (size_t i = 0, j = length - 1; i < j; ++i, --j) {
        // Swap characters at positions i and j
        char temp = reversedString[i];
        reversedString[i] = reversedString[j];
        reversedString[j] = temp;
    }

    return reversedString;
}

std::string reverseStringRecursively(const std::string& input, size_t index = 0) {
    if (index == input.length()) {
        // Base case: reached the end of the string
        return "";
    }

    // Recursive case: reverse the rest of the string and append the current character
    return reverseStringRecursively(input, index + 1) + input[index];
}

int main() {
    std::string userInput;

    std::cout << "Enter a string: ";
    std::getline(std::cin, userInput);

    std::string reversedResult = reverseStringRecursively(userInput);

    std::cout << "Original String: " << userInput << std::endl;
    std::cout << "Reversed String: " << reversedResult << std::endl;

    std::cout << "Enter a string: ";
    std::getline(std::cin, userInput);

    reversedResult = reverseString(userInput);
    std::transform(reversedResult.begin(), reversedResult.end(), reversedResult.begin(), ::toupper);

    std::cout << "Original String: " << userInput << std::endl;
    std::cout << "Reversed String: " << reversedResult << std::endl;

    return 0;
}