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
    Pentagon (float h=7, float b=3):
        triangle(h-b, b){
        square.set(b);
    }

    float area(){ return triangle.area() + square.area();}

    float perimeter(){return triangle.perimeter() + square.perimeter() / 2;}

private:
    Triangle triangle;
    Square square;
};

class ThreeDPentagon{
public:
    ThreeDPentagon(int h, int b, int L):
        pentagon(h, b), L(L){}

    float volume(){ return pentagon.area() * L;}

private:
    int L;
    Pentagon pentagon;
};

int main() {

    ThreeDPentagon pentagon3D(5,3,4);
    cout << "Volume of the 3D pentagon is: " << pentagon3D.volume();
}

