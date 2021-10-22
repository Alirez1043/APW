#include <iostream>
#include <cmath>

using namespace std;

class Square {
public:
    Square() { set(1); } //default constructor
    void set(int _a) { a = _a; }

    int area() { return (a * a); }

    int perimeter() { return 4 * a; }

private:
    int a;
};

int main() {

    Square *p = new Square();
    p->set(10);
    cout << "Area of this square is: " << p->area();
    delete p;
}

