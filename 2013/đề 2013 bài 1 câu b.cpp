#include <iostream>
using namespace std;
class SoPhuc {
private:
    int a, b; // a + b√7

public:
    // Constructor
    SoPhuc(int a = 0, int b = 0) : a(a), b(b) {}

    // Các phép toán
    SoPhuc operator+(const SoPhuc& other) const {
        return { a + other.a, b + other.b };
    }

    SoPhuc operator-(const SoPhuc& other) const {
        return { a - other.a, b - other.b };
    }

    SoPhuc operator-() const {
        return { -a, -b };
    }

    SoPhuc operator*(const SoPhuc& other) const {
        return { a * other.a + 7 * b * other.b, a * other.b + b * other.a };
    }

    friend std::ostream& operator<<(std::ostream& os, const SoPhuc& so) {
        return os << so.a << " + " << so.b << "√7";
    }
};

int main() {
    SoPhuc so1(2, 3);
    SoPhuc so2(1, -2);

    // Các phép toán
    std::cout << "Tong: " << so1 + so2 << std::endl;
    std::cout << "Hieu: " << so1 - so2 << std::endl;
    std::cout << "Doi dau cua so1: " << -so1 << std::endl;
    std::cout << "Tich: " << so1 * so2 << std::endl;

    return 0;
}