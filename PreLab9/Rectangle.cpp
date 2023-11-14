#include <iostream>
#include "Rectangle.h"

int Rectangle::totalCount = 0;

Rectangle::Rectangle() : length(0.), width(0.) {
    validateRectangle();
    totalCount++;
    count = totalCount;
}

Rectangle::Rectangle(double length, double width) : length(length), width(width) {
    validateRectangle();
    totalCount++;
    count = totalCount;
}

Rectangle::Rectangle(const Rectangle& r) : length(r.length), width(r.width) { 
    totalCount++;
    count = totalCount;
}

void Rectangle::validateRectangle() {
    if(this->length < 0) {
        this->length = 0.0;
    }
    if(this->width < 0) {
        this->width = 0.0;
    }
}

void Rectangle::setLength(double length) {
    this->length = length;
}

void Rectangle::setWidth(double width) {
    this->width = width;
}

double Rectangle::getArea() const {
    return length * width;
}

double Rectangle::getPerimeter() const { 
    return (length * 2) + (width * 2); 
}

void Rectangle::print() const {
    std::cout << "- Rectangle " << count << " -\n";
    std::cout << "Length: " << length << "\n";
    std::cout << "Width: " << width << "\n";
}

const Rectangle& Rectangle::operator =(const Rectangle& r) {
    if(length != r.length) {
        length = r.length;
    }
    if(width != r.width) {
        width = r.width;
    }
    return *this;
}

bool Rectangle::operator ==(const Rectangle& r) const {
    if(length == r.length && width == r.width) {
        return true;
    }
    return false;
}