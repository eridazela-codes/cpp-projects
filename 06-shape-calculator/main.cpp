#include <iostream>
using namespace std;

// Base class (abstract)
class Shape {
public:
    // Virtual functions - can be overridden by child classes
    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual string getName() const = 0;

    // Virtual destructor - important for proper cleanup with inheritance
    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) {
        radius = r;
    }

    double getArea() const override {
        return 3.14159 * radius * radius;
    }

    double getPerimeter() const override {
        return 2 * 3.14159 * radius;
    }

    string getName() const override {
        return "Circle";
    }
};

class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) {
        width = w;
        height = h;
    }

    double getArea() const override {
        return width * height;
    }

    double getPerimeter() const override {
        return 2 * (width + height);
    }

    string getName() const override {
        return "Rectangle";
    }
};

class Triangle : public Shape {
private:
    double sideA, sideB, sideC;
    double base, height;

public:
    Triangle(double a, double b, double c, double base_, double height_) {
        sideA = a;
        sideB = b;
        sideC = c;
        base = base_;
        height = height_;
    }

    double getArea() const override {
        return 0.5 * base * height;
    }

    double getPerimeter() const override {
        return sideA + sideB + sideC;
    }

    string getName() const override {
        return "Triangle";
    }
};

// This function works with ANY shape - this is polymorphism in action
void printShapeInfo(const Shape& shape) {
    cout << "\n=== " << shape.getName() << " ===" << endl;
    cout << "Area: " << shape.getArea() << endl;
    cout << "Perimeter: " << shape.getPerimeter() << endl;
}

int main() {
    Circle circle(5.0);
    Rectangle rectangle(4.0, 6.0);
    Triangle triangle(3.0, 4.0, 5.0, 4.0, 3.0);

    printShapeInfo(circle);
    printShapeInfo(rectangle);
    printShapeInfo(triangle);

    // Polymorphism with pointers - storing different shapes in one array
    Shape* shapes[3];
    shapes[0] = &circle;
    shapes[1] = &rectangle;
    shapes[2] = &triangle;

    cout << "\n=== Looping through all shapes polymorphically ===" << endl;
    for (int i = 0; i < 3; i++) {
        printShapeInfo(*shapes[i]);
    }

    return 0;
}