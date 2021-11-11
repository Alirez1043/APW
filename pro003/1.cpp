#include <iostream>
#include <cmath>

using namespace std;

class Triangle {
public:
    Triangle(int _height, int _base) { set(_height, _base); } //constructor
    void set(int _height, int _base) {
        height = _height;
        base = _base;
    }

    int area() { return ((height * base) / 2); }

    int perimeter() { return (2 * (sqrt(((base / 2) * (base / 2)) + (height * height))) + base); }

private:
    int height;
    int base;
};

class Square {
public:
    Square() { set(1); } //default constructor
    void set(int _a) { a = _a; }

    int area() { return (a * a); }

    int perimeter() { return 4 * a; }

private:
    int a;
};

class Pentagon{
public:
    Pentagon (int h=7, int b=3):
        triangle(h-b, b){
        square.set(b);
    }

    float area(){ return triangle.area() + square.area();}

    float perimeter(){return triangle.perimeter() + square.perimeter() / 2;}

private:
    Triangle triangle;
    Square square;
};

int main() {
    Pentagon pentagon(5, 3);
    cout << "Pentagon area is: " << pentagon.area() << endl;
    cout << "Pentagon perimeter is: " << pentagon.perimeter() << endl;
}

