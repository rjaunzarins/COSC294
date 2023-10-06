#include <iostream>

class Wheel {
    public:
        Wheel(int rim = 0, int tire = 0);
        std::string getRimType();
        std::string getTireType();
        void printRim();
    private:
        int rimType;
        int tireType;
        void validateWheel();
};

class Car {
    public:
        Car(double priceValue = 0., std::string manufactName = "null", std::string modelName = "null", int rim = 0, int tire = 0);
        double getPrice();
        std::string getManufact();
        std::string getModel();
        void printCar();
    private:
        double price;
        std::string manufact;
        std::string model;
        Wheel wheels;
};


void setPrecision();

int main() {
        Car car1(100000.00, "Ford", "Fiesta", 2, 2);
        setPrecision();
        car1.printCar();
        Car car2;
        car2.printCar();
        Car car3(42543.56, "Madza", "3", 1, 1);
        car3.printCar();
}


void setPrecision() {
    std::cout.setf(std::ios::fixed);
    std::cout.setf(std::ios::showpoint);
    std::cout.precision(2);
}


// After : youre saying set field (price) as this (priceValue) argument passed to parameter
Car::Car(double priceValue, std::string manufactName, std::string modelName, int rim, int tire) 
                            : price(priceValue), manufact(manufactName), model(modelName), wheels(rim, tire) {}

double Car::getPrice() {
    return price;
}

std::string Car::getManufact() {
    return manufact;
}

std::string Car::getModel() {
    return model;
}

void Car::printCar() {
    std::cout << "Manufacturer: " << manufact << std::endl;
    std::cout << "Model: " << model << std::endl;
    std::cout << "Price: " << price << std::endl;
    wheels.printRim();
    std::cout << std::endl;
}



//--------Wheel
Wheel::Wheel(int rim, int tire) : rimType(rim), tireType(tire) {
    validateWheel();
}

void Wheel::validateWheel() {
    if(rimType < 0 || rimType > 2) {
        std::cout << "Invalid rim type." << std::endl;
        std::exit(1);
    }
    if(tireType < 0 || tireType > 2) {
        std::cout << "Invalid tire type." << std::endl;
        std::exit(1);
    }
}

std::string Wheel::getRimType() {
    switch(rimType) {
        case 0:
            return "null";
        case 1:
            return "Steel";
        case 2:
            return "Aluminum";
        default:
            return "Invalid rim type";
    }
}

std::string Wheel::getTireType() {
    switch(tireType) {
        case 0:
            return "null";
        case 1:
            return "Road";
        case 2:
            return "Track";
        default:
            return "Invalid tire type.";
    }
}

void Wheel::printRim() {
    std::cout << "Rims: " << getRimType() << std::endl;
    std::cout << "Wheels: " << getTireType() << std::endl;
}

