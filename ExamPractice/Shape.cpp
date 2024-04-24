#include <iostream>

class Shape {
    public:
        virtual double area() const = 0;    //Pure virtual
        virtual void display() const { std::cout << "This is a shape." << "\n"; }
        virtual ~Shape() {}
};

class Circle : public Shape {
    public:
        Circle(double r) : radius(r) {}
        double area() const override {
            return 3.14 * radius * radius;
        }
        void display() const override {
            std::cout << "Circle - radius: " << radius << "\n"; 
        }
    private:
        double radius;
};

class Rectangle : public Shape {
    public:
        Rectangle(double l, double w) : length(l), width(w) {}
        double area() const override {
            return length * width;
        }
        void display() const override {
            std::cout << "Rectangle - Length: " << length << " Width: " << width << "\n";
        }
        double getLength() const { return length; }
        double getWidth() const { return width; }
    private:
        double length;
        double width;
};

class Square : public Rectangle {
    public: 
        Square(double side) : Rectangle(side, side) {}
        void display() const override {
            std::cout << "Square - Side: " << Rectangle::getLength() << "\n";
        }
};

int main() {

    Circle c(12.2);
    Rectangle r(13.3,14.4);
    Square s(11.1);

    Shape* s1 = &c;
    Shape* s2 = &r;
    Shape* s3 = &s;

    std::unique_ptr<Shape> s1 = std::make_unique<Circle>(2.2);
    Shape* currentShape = s1;
    currentShape->display();


    s1->display();
    std::cout << "Area: " << s1->area() << "\n";

    s2->display();
    std::cout << "Area: " << s2->area() << "\n";
    r.display();
    std::cout << "Area: " << r.area() << "\n";

    s3->display();
    std::cout << "Area: " << s3->area() << "\n";
}