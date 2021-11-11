#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class BigInt{
public:
    explicit BigInt (string number);
    explicit BigInt (int number);

    bool operator==(const BigInt &other) const;
    BigInt operator+(const BigInt &other) const;
    BigInt &operator+=(const BigInt &other);
    BigInt operator+(const int other) const;

    friend ostream  &operator<<(ostream &stream, const BigInt &bigInt);

private:
    string value;
};

ostream &operator<<(ostream &stream, const BigInt &bigInt) {
    stream << bigInt.value << endl;
    return stream;
}

BigInt::BigInt(int number) {
    value = to_string(number);
}

BigInt::BigInt(string number) {
    value = number;
}

bool BigInt::operator==(const BigInt &other) const {
    return value == other.value;
}

BigInt BigInt::operator+(const BigInt &other) const{
    string thisValue = value;
    string otherValue = other.value;
    if (thisValue.length() > otherValue.length()){
        swap(thisValue, otherValue);
    }

    string temp = "";
    int thisSize = thisValue.size();
    int otherSize = otherValue.size();

    reverse(thisValue.begin(), thisValue.end());
    reverse(otherValue.begin(), otherValue.end());

    int carry = 0;
    for (int i = 0; i < thisSize; ++i) {
        int sum = ((thisValue[i]-'0')+(otherValue[i]-'0')+carry);
        temp.push_back(sum%10 + '0');
        carry = sum/10;
    }

    for (int i = thisSize; i < otherSize; ++i) {
        int sum = ((otherValue[i]- '0')+carry);
        temp.push_back(sum%10+ '0');
        carry = sum/10;
    }

    if (carry){
        temp.push_back(carry+'0');
    }

    reverse(temp.begin(), temp.end());

    return BigInt(temp);
}

BigInt &BigInt::operator+=(const BigInt &other) {
    value = (*this + other).value;
    return *this;
}

BigInt BigInt::operator+(const int other) const {
    return BigInt(other) + (*this);
}

BigInt operator+(const int &other, const BigInt &bigInt){
    return BigInt(other) + bigInt;
}

int main(){
    BigInt a ("1000000000001");
    BigInt b (1239);
    BigInt c =  9 + a + 9;

    cout << a << b << c << endl;

    BigInt d =  (b+= a);
    if (b == d)
        cout <<  d << endl;
}
