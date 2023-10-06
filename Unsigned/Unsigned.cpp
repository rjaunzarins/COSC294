#include <iostream>

int main() {
    signed int a = -2;
    unsigned int b = 1;
    signed c = -2;
    unsigned d = 1;
    
    std::cout << "Signed int: " << a << std::endl;
    std::cout << "Unsigned int: " << b << std::endl;
    std::cout << "Signed: " << c << std::endl;
    std::cout << "Unsigned: " << d << std::endl;
    std::cout << "Signed int + unsigned int: " << a + b << std::endl;
    std::cout << "Signed + unsigned: " << c + d << std::endl;
    std::cout << "Signed int + (int)unsigned int: " << a + (int)b << std::endl;
    std::cout << "Signed + (int)unsigned: " << c + (int)d << std::endl;
}