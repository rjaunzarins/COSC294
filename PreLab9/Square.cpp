#include "Rectangle.h"
#include "Square.h"
#include <iostream>

int Square::totalCount = 0;

Square::Square() : Rectangle(0.,0.) {
    totalCount++;
    count = totalCount;
}

Square::Square(double length) : Rectangle(length, length) {
    totalCount++;
    count = totalCount;
}

Square::Square(const Square& s) : Rectangle(s) {
    totalCount++;
    count = totalCount;
}

void Square::setLength(double length) {
    Rectangle::setLength(length);
    Rectangle::setWidth(length);
}

void Square::setWidth(double width) {
    setLength(width);
}

void Square::print() const {
    std::cout << "- Square " << count << " -\n";
    std::cout << "Length: " << getLength() << "\n";
}