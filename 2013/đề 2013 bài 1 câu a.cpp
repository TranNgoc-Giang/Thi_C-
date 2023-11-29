#include <iostream>

class SoPhuc {
private:
    int a, b; // a + b√7

public:
    // Constructor
    SoPhuc(int a = 0, int b = 0) : a(a), b(b) {}

    // Phép cộng
    SoPhuc operator+(const SoPhuc& other) const {
        return SoPhuc(a + other.a, b + other.b);
    }

    // Phép trừ
    SoPhuc operator-(const SoPhuc& other) const {
        return SoPhuc(a - other.a, b - other.b);
    }

    // Phép đổi dấu
    SoPhuc operator-() const {
        return SoPhuc(-a, -b);
    }

    // Phép nhân
    SoPhuc operator*(const SoPhuc& other) const {
        return SoPhuc(a * other.a + 7 * b * other.b, a * other.b + b * other.a);
    }

    friend std::ostream& operator<<(std::ostream& os, const SoPhuc& so) {
        os << so.a << " + " << so.b << "√7";
        return os;
    }
};

int main() {
    SoPhuc so1(2, 3);
    SoPhuc so2(1, -2);

    // Phép cộng
    SoPhuc tong = so1 + so2;
    std::cout << "Tong: " << tong << std::endl;

    // Phép trừ
    SoPhuc hieu = so1 - so2;
    std::cout << "Hieu: " << hieu << std::endl;

    // Phép đổi dấu
    SoPhuc doiDau = -so1;
    std::cout << "Doi dau cua so1: " << doiDau << std::endl;

    // Phép nhân
    SoPhuc tich = so1 * so2;
    std::cout << "Tich: " << tich << std::endl;

    return 0;
}
