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
        friend std::ostream& operator <<(std::ostream& output, const Coordinate& coord);
    private:
        int x;
        int y;
        int coordNum;
        static int totalCoordNum;  
};
//Addition Overload
const Coordinate operator +(const Coordinate& coord1, const Coordinate& coord2);
//Subtract Overload
const Coordinate operator -(const Coordinate& coord1, const Coordinate& coord2);
//Equals Overload
bool operator ==(const Coordinate& coord1, const Coordinate& coord2);
//Negate Overload
const Coordinate operator -(const Coordinate& coord1);

int Coordinate::totalCoordNum = 0;

int main() {
    Coordinate a(10,10);
    Coordinate b(5,5);
    Coordinate c(b);
    Coordinate d = a + b;
    Coordinate e = b - a;
    Coordinate f = -e;
    std::cout << "Total coordinates = " << a.getTotalCoordNum() << std::endl;
    a.printCoordinates();
    std::cout << a << "\n" << b << "\n" << c << "\n" << d << "\n" << e << "\n" << f << std::endl;
    std::cout << "a = b: " << a.equals(b); std::cout << std::endl;
    std::cout << "b = c: " << (b == c); std::cout << std::endl;
    std::cout << "Total coordinates = " << a.getTotalCoordNum() << std::endl;
}


Coordinate::Coordinate(int xVal, int yVal) : x(xVal), y(yVal) { coordNum = ++totalCoordNum; }
Coordinate::Coordinate(const Coordinate& original) {
    this->x = original.x;
    this->y = original.y;
    coordNum = ++totalCoordNum;
}

void Coordinate::printCoordinates() const {
    std::cout << "Coordinates: " << x << "," << y << " - Num: " << coordNum << std::endl;
}
bool Coordinate::equals(const Coordinate& coordinates2) {
    if(this->x == coordinates2.x) {
        if(this->y == coordinates2.y)
            return true;
    }
    return false;
}

//<< Overload
std::ostream& operator <<(std::ostream& output, const Coordinate& coord) {
    output << "(" << coord.x << "," << coord.y << ") - Num: " << coord.coordNum;
    return output;
}

//Addition Overload
const Coordinate operator +(const Coordinate& coord1, const Coordinate& coord2) {
    return Coordinate((coord1.getX() + coord2.getX()), (coord1.getY() + coord2.getY()));
}
//Subtract Overload
const Coordinate operator -(const Coordinate& coord1, const Coordinate& coord2) {
    return Coordinate((coord1.getX() - coord2.getX()), (coord1.getY() - coord2.getY()));
}
//Equals Overload
bool operator ==(const Coordinate& coord1, const Coordinate& coord2) {
    if((coord1.getX() == coord2.getX()) && (coord1.getY() == coord2.getY()))
            return true;
    return false;
}
//Negate Overload
const Coordinate operator -(const Coordinate& coord1) {
    return Coordinate(-coord1.getX(), -coord1.getY());
}
