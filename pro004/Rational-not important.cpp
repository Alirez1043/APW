#include <iostream>
#include <cmath>

using namespace std;

class Rational {
public:
    Rational(long long n, long long d = 1);

    static Rational splitNumberAndFraction(double num);

    Rational operator+(const Rational &other) const;
    Rational operator+(double other) const;

    Rational operator-(const Rational &other) const;
    Rational operator-(double other) const;

    Rational operator*(const Rational &other) const;
    Rational operator*(double other) const;

    Rational operator/(const Rational &other) const;
    Rational operator/(double other) const;

    Rational &operator+=(const Rational &other);

    Rational &operator-=(const Rational &other);

    Rational &operator*=(const Rational &other);

    Rational &operator/=(const Rational &other);

    bool operator==(const Rational &other) const;

    friend ostream &operator<<(ostream &stream, const Rational &rational);

    long long getNumer() const { return numerator;}
    long long getdenomr()const { return denominator;}
private:
    long long numerator;
    long long denominator;
};

Rational::Rational(long long n, long long d){
    numerator = n;
    if (d != 0){
        denominator = d;
    }else{
        throw invalid_argument("Invalid denominator.");
    }
}

Rational Rational::operator+(const Rational &other) const{
    return Rational{
            numerator * other.denominator + other.numerator * denominator,
            denominator * other.denominator
    };
}

Rational Rational::operator-(const Rational &other) const{
    return Rational{
            numerator * other.denominator - other.numerator * denominator,
            denominator * other.denominator
    };
}

Rational Rational::operator*(const Rational &other) const{
    return Rational(numerator * other.numerator, denominator * other.denominator);
}

Rational Rational::operator/(const Rational &other) const{
    return Rational(numerator * other.denominator, denominator * other.numerator);
}

Rational &Rational::operator+=(const Rational &other) {
    numerator = (*this + other).numerator;
    denominator = (*this + other).denominator;
    return *this;
}

Rational &Rational::operator-=(const Rational &other) {
    numerator = (*this - other).numerator;
    denominator = (*this - other).denominator;
    return *this;
}

Rational &Rational::operator*=(const Rational &other) {
    numerator *= other.numerator;
    denominator *= other.denominator;
    return *this;
}

Rational &Rational::operator/=(const Rational &other) {
    numerator *= other.denominator;
    denominator *= other.numerator;
    return *this;
}

bool Rational::operator==(const Rational &other) const{
    return numerator == other.numerator && denominator == other.denominator;
}

ostream &operator<<(ostream &stream, const Rational &rational) {
    stream <<  float(rational.numerator)/rational.denominator << endl;
    return stream;
}

Rational Rational::operator+(double other) const {
    return (Rational::splitNumberAndFraction(other) + *this);
}

Rational operator+(double other, const Rational &rational){
    return Rational::splitNumberAndFraction(other) + rational;
}

Rational Rational::operator-(double other) const {
    return (*this - Rational::splitNumberAndFraction(other));
}

Rational operator-(double other, const Rational &rational){
    return Rational::splitNumberAndFraction(other) - rational;
}

Rational Rational::operator*(double other) const {
    return Rational::splitNumberAndFraction(other) * (*this);
}

Rational operator*(double other, const Rational &rational){
    return Rational::splitNumberAndFraction(other) * rational;
}

Rational Rational::operator/(double other) const {
    return (*this) / Rational::splitNumberAndFraction(other);
}

Rational operator/(double other, const Rational &rational){
    return Rational::splitNumberAndFraction(other) / rational;
}

Rational Rational::splitNumberAndFraction(double num) {
    string strNum = to_string(num);
    long long integral = static_cast<long long>(num);
    string strFraction = strNum.substr(strNum.find('.')+1);
    long long fractional = stoi(strFraction);

    return Rational{
            long(integral * pow(10, strFraction.length()) + fractional),
            long(pow(10, strFraction.length()))
    };
}

int main() {
    Rational a(1,2), c(3);
    double d = 3;
    Rational b(1,2);
    cout << a << c << endl;

    cout << a+c << d + a + d << endl;
    cout << a-c << d - a * d << endl;
    cout << a*c << d * a / c << endl;
    cout << (b == a) << endl;
    cout << a/c << ( a+= c) << endl;
    cout << (b == a);
}

