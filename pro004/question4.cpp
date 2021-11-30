#include <iostream>
#include <cmath>

using namespace std;

class Poly {
public:
    Poly(int d, int *coeff);

    ~Poly();

    Poly operator+(Poly &poly);

    Poly operator*(const Poly &poly);

    Poly derivative();

    double operator()(double x);

    friend ostream &operator<<(ostream &stream, const Poly &poly);

private:
    int degree;
    int *coefficient = new int[degree + 1];
};

Poly::Poly(int d, int *coeff) : degree(d) {
    for (int i = 0; i <= degree; ++i) {
        coefficient[i] = coeff[i];
    }
}

Poly::~Poly() {
    delete[] coefficient;
}

Poly Poly::operator+(Poly &poly) {
    Poly temp = *this;

    if (temp.degree < poly.degree) {
        swap(temp.coefficient, poly.coefficient);
        swap(temp.degree, poly.degree);
    }

    int tempIndex = temp.degree;

    for (int i = poly.degree, j = temp.degree; i >= 0; --i, j--) {
        temp.coefficient[i] = poly.coefficient[i] + temp.coefficient[tempIndex--];
    }

    for (int i = 0; i <= tempIndex; ++i) {
        temp.coefficient[i] = temp.coefficient[i];
    }

    return temp;
}

Poly Poly::operator*(const Poly &poly) {
    const int newDegree = poly.degree + degree;
    int prod[newDegree + 1];

    for (int i = 0; i < poly.degree + degree + 1; i++) {
        prod[i] = 0;
    }

    for (int i = 0; i < degree + 1; i++) {
        for (int j = 0; j < poly.degree + 1; j++)
            prod[i + j] += coefficient[i] * poly.coefficient[j];
    }

    return Poly(poly.degree + degree, prod);
}


ostream &operator<<(ostream &stream, const Poly &poly) {
    int degree = poly.degree;

    for (int i = 0; i <= degree; ++i) {

        if (poly.coefficient[i] > 0) {
            if (i == 0) {
                stream << poly.coefficient[i] << "x^" << degree - i << " ";
                continue;
            } else if (i == degree) {
                stream << "+ " << poly.coefficient[i];
                continue;
            }
            stream << "+ " << poly.coefficient[i] << "x^" << degree - i << " ";

        } else if (poly.coefficient[i] == 0) {
            continue;

        } else {
            if (i == 0) {
                stream << "-" << abs(poly.coefficient[i]) << "x^" << degree - i << " ";
                continue;
            } else if (i == degree) {
                stream << "- " << abs(poly.coefficient[i]);
                continue;
            }
            stream << "- " << abs(poly.coefficient[i]) << "x^" << degree - i << " ";
        }

    }
    cout << endl;
    return stream;
}

Poly Poly::derivative() {
    const int newDegree = degree;
    int coeff[newDegree - 1];
    for (int i = 0; i < degree; ++i) {
        coeff[i] = coefficient[i] * (degree - i);
    }
    return Poly(degree - 1, coeff);
}

double Poly::operator()(double x){
    double result = 0;
    for (int i = 0; i <= degree; ++i) {
        result += pow(x, degree-i) * coefficient[i];
    }
    return result;
}

int main() {
    int co1[] = {1, 1};
    int co2[] = {1, -1};
    int co3[] = {2, 3, 4, 5};

    Poly poly1(1, co1);
    Poly poly2(1, co2);
    Poly poly3(3, co3);

    double poly1Result = poly1(1);
    double poly2Result = poly2(1);
    double poly3Result = poly3(1);

    cout << poly1 * poly2;
    cout << poly1 + poly2;

    cout << poly3.derivative();

    cout << poly1Result << "  " << poly2Result << "  " << poly3Result;
}
