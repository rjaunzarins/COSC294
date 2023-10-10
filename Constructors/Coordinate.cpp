#include <iostream>

class Coordinate {
    public:
        Coordinate(int xVal = 0, int yVal = 0);
        Coordinate(const Coordinate& original);
        int getX() const;
        int getY() const ;
        void printCoordinates() const;
        bool equals(const Coordinate& coordinates2);
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
    a.printCoordinates();
    b.printCoordinates();
    c.printCoordinates();
    d.printCoordinates();
    e.printCoordinates();
    f.printCoordinates();
    std::cout << "a = b: " << a.equals(b); std::cout << std::endl;
    std::cout << "b = c: " << (b == c); std::cout << std::endl;
}


Coordinate::Coordinate(int xVal, int yVal) : x(xVal), y(yVal) { coordNum = ++totalCoordNum; }
Coordinate::Coordinate(const Coordinate& original) {
    this->x = original.x;
    this->y = original.y;
    coordNum = ++totalCoordNum;
}
int Coordinate::getX() const { return x; }
int Coordinate::getY() const { return y; };
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