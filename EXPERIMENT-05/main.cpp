#include <iostream>
using namespace std;
 
class Shape {
public:
    virtual float area() = 0;  // Pure virtual function
    virtual ~Shape() = default;
};
 
class Circle : public Shape {
    float r;
 
public:
    Circle(float radius) {
        r = radius;
    }
 
    float area() override {
        return 3.14f * r * r;
    }
};
 
class Rectangle : public Shape {
    float l, b;
 
public:
    Rectangle(float length, float breadth) {
        l = length;
        b = breadth;
    }
 
    float area() override {
        return l * b;
    }
};
 
class Triangle : public Shape {
    float b, h;
 
public:
    Triangle(float base, float height) {
        b = base;
        h = height;
    }
 
    float area() override {
        return 0.5f * b * h;
    }
};
 
int main() {
    Circle c(3.0f);
    Rectangle r(4.0f, 5.0f);
    Triangle t(3.0f, 6.0f);
 
    Shape* s1 = &c;
    Shape* s2 = &r;
    Shape* s3 = &t;
 
    cout << "Circle Area: " << s1->area() << endl;
    cout << "Rectangle Area: " << s2->area() << endl;
    cout << "Triangle Area: " << s3->area() << endl;
 
    return 0;
}

 
