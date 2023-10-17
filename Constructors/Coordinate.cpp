#include <iostream>

class Coordinate {
    public:
        Coordinate(int xVal = 0, int yVal = 0);
        Coordinate(const Coordinate& original);
        int getX() const { return x; };
        int getY() const { return y; };
        int getTotalCoordNum() const { return totalCoordNum; }
        void printCoordinates() const;
        bool equals(const Coordinate& coordinates2);

        // Addition overload
        friend const Coordinate operator +(const Coordinate& coor1, const Coordinate& coord2);
        // Subtraction overload
        friend const Coordinate operator -(const Coordinate& coord1, const Coordinate& coord2);
        // Equality Overload
        friend bool operator ==(const Coordinate& coord1, const Coordinate& coord2);
        // Not equals overload
        friend bool operator !=(const Coordinate& coord1, const Coordinate& coord2);
        // Negate Overload
        friend const Coordinate operator -(const Coordinate& coord1);
        // Insertion (output) Overload
        friend std::ostream& operator <<(std::ostream& output, const Coordinate& coord);
        // Extraction (input) Overload
        friend std::istream& operator >>(std::istream& input, Coordinate& coord);
    
    private:
        int x;
        int y;
        int coordNum;
        static int totalCoordNum;  
};

// For static totalCoordNum
int Coordinate::totalCoordNum = 0;


int main() {
    Coordinate a(10,10);
    Coordinate b(5,5);
    Coordinate c(b);
    Coordinate d = a + b;
    Coordinate e = b - a;
    Coordinate f = -e;
    Coordinate g;
    std::cout << "Enter coordinates: ";
    std::cin >> g;
    std::cout << "Total coordinates = " << a.getTotalCoordNum() << std::endl;
    a.printCoordinates();
    std::cout << a << "\n" << b << "\n" << c << "\n" << d << "\n" << e << "\n" << f << std::endl;
    std::cout << "a = b: " << a.equals(b); std::cout << std::endl;
    std::cout << "b = c: " << (b == c); std::cout << std::endl;
    std::cout << "Total coordinates = " << a.getTotalCoordNum() << std::endl;

    Coordinate h = {1, 2};
    Coordinate i{1,2};
}


Coordinate::Coordinate(int xVal, int yVal) : x(xVal), y(yVal), coordNum(++totalCoordNum) {}
Coordinate::Coordinate(const Coordinate& original) : x(original.x), y(original.y), coordNum(++totalCoordNum) {}

void Coordinate::printCoordinates() const {
    std::cout << "Coordinates: " << x << "," << y << " - Num: " << coordNum << std::endl;
}
bool Coordinate::equals(const Coordinate& coordinates2) {
    if(x == coordinates2.x) {
        if(y == coordinates2.y)
            return true;
    }
    return false;
}

//<< Overload
std::ostream& operator <<(std::ostream& output, const Coordinate& coord) {
    output << "(" << coord.x << "," << coord.y << ") - Num: " << coord.coordNum;
    return output;
}

//>> Overload
std::istream& operator >>(std::istream& input, Coordinate& coord) {
    input >> coord.x;
    input >> coord.y;
    return input;
}

//Addition Overload
const Coordinate operator +(const Coordinate& coord1, const Coordinate& coord2) {
    return Coordinate((coord1.x + coord2.x), (coord1.y + coord2.y));
}
//Subtract Overload
const Coordinate operator -(const Coordinate& coord1, const Coordinate& coord2) {
    return Coordinate((coord1.x - coord2.x), (coord1.y - coord2.y));
}
//Equals Overload
bool operator ==(const Coordinate& coord1, const Coordinate& coord2) {
    return ((coord1.x == coord2.x) && (coord1.y == coord2.y));
}
// Not Equal Overload
bool operator !=(const Coordinate& coord1, const Coordinate& coord2) {
    return ((coord1.x != coord2.x) && (coord1.y != coord2.y));
}
//Negate Overload
const Coordinate operator -(const Coordinate& coord1) {
    return Coordinate(-coord1.x, -coord1.y);
}
