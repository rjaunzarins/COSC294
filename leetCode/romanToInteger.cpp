#include <iostream>

int romanToInt(std::string s);

int main() {

std::string s1 = "III";
std::string s1 = "LVIII";
std::string s1 = "MCMCIV";
std::string s1 = "III";

}

int romanToInt(std::string s) {
    int sum = 0;
    int num = 0;
    for (size_t i = 0; i < s.length(); i++) {
        if(s[i] == 'I') {
            ++sum;
            if(s[i+i] == 'V') {
                num = num + (5-sum);
                sum = 0;
            }
            else if( s[i+1] == 'X') {
                num = num + (10-sum);
                sum = 0;
            }
        }
    }
    
    
    return 0;
}