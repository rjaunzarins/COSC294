#include <iostream>
using namespace std;

class Instrument {
    public:
        void makeSound() {
            cout << "Instrument playing...\n";
        }
        virtual void makeOtherSound() {
            cout << "Instrument playing other sound...\n";
        }
};

class Accordion : public Instrument {
    public:
        virtual void makeSound() {
            cout << "Accordion playing...\n";
        }
        void makeOtherSound() {
            cout << "Accordion playing other sound...\n";
        }
};

int main() {
    Instrument i1;
    i1.makeSound();                     //Instrument playing...
    i1.makeOtherSound();                //Instrument playing other sound...
    
    Instrument *i2 = new Instrument;    
    i2->makeSound();                    //Instrument playing...
    i2->makeOtherSound();               //Instrument playing other sound...
    
    Instrument *i3 = new Accordion;     
    i3->makeSound();                    //Instrument playing...
    i3->makeOtherSound();               //Accordion playing other sound...
    
    Accordion a1;
    a1.makeSound();                     //Accordion playing...
    a1.makeOtherSound();                //Accordion playing other sound...
    
    Accordion *a2 = new Accordion;
    a2->makeSound();                    //Accordion playing...
    a2->makeOtherSound();               //Accordion playing other sound...
    
}