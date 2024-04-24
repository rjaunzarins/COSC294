#include <iostream>

int c ( int n, int k ){
    int t1, t2;
    std::cout << "n: " << n << std::endl;
    std::cout << "k: " << k << std::endl;
    if (n == 0) {
        if (k == 0) return 1;
        else return 0;
    } else if ( k == 0 ) {
        return 0;
    } else {
        t1 = c( n - 1, k);
        t2 = c( n - 1, k - 1);
        return (n - 1) * t1 + t2;
    }
}



int main() {

    int n = 1;
    int k = 0;

    int result = c(n,k);

    std::cout << result << std::endl;
}