#include <iostream>

unsigned int f( unsigned int n, unsigned int m ) {
	if ( n == 1 ) {
		if ( m == 0 ) return n;
		else if ( m == 1 ) return m;
		else return 1;
	} else if ( m == 0 ) {
		return 0;
	} else {
		int t = f( n, m - 2 );
        std::cout << "t: " << t;
		int u = f( n - 1, m - 1 );
        std::cout << " u: " << u << std::endl;
		return t * u;
	}
}

int main() {
    int n = 2;
    int m = 2;
    int x = f(n, m);
    std::cout << x << std::endl;
}