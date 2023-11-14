#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle {
    public:
        Rectangle();
        Rectangle(double length, double width);
        Rectangle(const Rectangle& r);
        virtual ~Rectangle() = default; // virtual because of virtual functions
        virtual void setLength(double length);
        virtual void setWidth(double width);
        double getLength() const { return length; }
        double getWidth() const { return width; }
        double getArea() const;
        double getPerimeter() const; 
        virtual void print() const;
        const Rectangle& operator =(const Rectangle& r);     
        bool operator ==(const Rectangle& r) const;
    private:
        void validateRectangle();
        double length;
        double width;
        int count;
        static int totalCount;
};

#endif