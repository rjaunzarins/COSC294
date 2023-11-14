#include <iostream>
#include "Rectangle.h"
#include "Square.h"


int main() {
    Rectangle rec1(12.4, 13.2);
    Rectangle rec2(rec1);

    Square sq1(15.9);
    Square sq2(sq1);

    rec1.print();
    rec2.print();
    sq1.print();
    sq2.print();

    if(rec1 == rec2) {
        std::cout << "Rec1 = Rec2\n";
    }
    if(sq1 == sq2) {
        std::cout << "Sq1 = Sq2\n";
    }

    Rectangle rec3 = rec2;
    rec3.print();

    Square sq3 = sq2;
    sq3.print();

}