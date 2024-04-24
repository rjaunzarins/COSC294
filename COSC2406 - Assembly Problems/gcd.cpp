#include <iostream>

int gcd ( int x, int y ) {
    if ( y == 0 ) return x;
    else return gcd( y, x % y );
}

int main() {
    int x = 15;
    int y = 5;

    int greatest = gcd(x, y);

    std::cout << greatest << std::endl;
}