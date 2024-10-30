#include <iostream>
#include <cmath>
#include <cassert>

struct BoundingBoxDimensions {
    double height = 0.;
    double width = 0.;
};

class Shape {
protected:
    BoundingBoxDimensions hisBox;
    std::string type;
public:
    virtual std::string * getType() = 0;
    virtual void printParams(Shape* thisShape) = 0; 
    virtual double square() = 0; 
    virtual BoundingBoxDimensions * dimensions() = 0;  
};

class Circle : virtual public Shape {
    double radius = 0.;
public:
    Circle(double inRadius) : radius(inRadius) {
        assert(inRadius > 0.);
        type = "circle";
        hisBox.height = inRadius;
        hisBox.width = inRadius;
    }
    virtual std::string * getType() {
        return &type;
    }
    virtual double square() {
        return 3.1415 * pow(radius,2);
    }
    virtual BoundingBoxDimensions* dimensions() {
        return &hisBox;
    }
    virtual void printParams(Shape* thisShape) {
        std::cout << "\nType : " << *getType() << std::endl;
        std::cout << "Square : " << square() << std::endl;
        std::cout << "Width : " << dimensions()->width << std::endl;
        std::cout << "Height : " << dimensions()->height << std::endl;
    }
};

class Rectangle : virtual public Shape {
    double width = 0.;
    double height = 0.;
public:
    Rectangle(double inWidth, double inHeight) : width(inWidth),height(inHeight) {
        assert(inWidth > 0.);
        assert(inHeight > 0.);
        type = "rectangle";
        hisBox.width = inWidth;
        hisBox.height = inHeight;
    }
    virtual std::string * getType() {
        return &type;
    }
    virtual double square() {
        return width * height;
    }
    virtual BoundingBoxDimensions* dimensions() {
        return &hisBox;
    }
    virtual void printParams(Shape* thisShape) {
        std::cout << "\nType : " << *getType() << std::endl;
        std::cout << "Square : " << square() << std::endl;
        std::cout << "Width : " << dimensions()->width << std::endl;
        std::cout << "Height : " << dimensions()->height << std::endl;
    }
};

class Triangle : virtual public Shape {
    double a = 0.;
    double b = 0.;
    double c = 0.;
    double p = 0.;
public:
    Triangle(double inA, double inB, double inC) : a(inA),b(inB),c(inC) {
        assert(inA > 0.);
        assert(inB > 0.);
        assert(inC > 0.);
        type = "triangle";
        p = (inA + inB + inC) / 2;
        double temp = (inA * inB * inC / (4 * sqrt(p * (p - inA) * (p - inB) * (p - inC))) * 2.);
        hisBox.height = temp;
        hisBox.width = temp;
    }
    virtual std::string * getType() {
        return &type;
    }
    virtual double square() {
        return sqrt(p*(p-a)*(p-b)*(p-c));
    }
    virtual BoundingBoxDimensions* dimensions() {
        return &hisBox;
    }
    virtual void printParams(Shape* thisShape) {
        std::cout << "\nType : " << *getType() << std::endl;
        std::cout << "Square : " << square() << std::endl;
        std::cout << "Width : " << dimensions()->width << std::endl;
        std::cout << "Height : " << dimensions()->height << std::endl;
    }
};

int main() {
    Shape** shapes = new Shape * [3];
    shapes[0] = new Circle(5.);
    shapes[1] = new Rectangle(5.,5.);
    shapes[2] = new Triangle(3,4,5);
    for (int i = 0; i < 3; ++i) {
        shapes[i]->printParams(shapes[i]);
    }
    delete [] shapes;
}
