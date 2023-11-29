#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class BigInteger {
public:
    BigInteger() : value("0") {}
    BigInteger(const string& str) : value(str) {}

    friend istream& operator>>(istream& is, BigInteger& num) {
        string str;
        is >> str;
        num.value = str;
        return is;
    }

    friend ostream& operator<<(ostream& os, const BigInteger& num) {
        os << num.value;
        return os;
    }

    bool operator==(const BigInteger& other) const {
        return value == other.value;
    }

private:
    string value;
};

int main() {
    BigInteger n1("1234567891011");
    BigInteger n2;

    cout << "Input an integer = ";
    cin >> n2;

    if (n1 == n2)
        cout << "Equal.\n";
    else
        cout << "Not equal.\n";

    return 0;
}