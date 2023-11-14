#ifndef SQUARE_H
#define SQUARE_H
#include "Rectangle.h"

class Square : public Rectangle {
    public:
        Square(); 
        Square (double length);
        Square(const Square& s);
        Square(const Square&& s);
        virtual ~Square() = default;    //Should this be virtual?
        void setLength(double length) override;
        void setWidth(double width) override;
        void print() const override; 
    private:
        int count;
        static int totalCount;
};

#endif