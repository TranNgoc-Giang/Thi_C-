#include <iostream>
#include <string>
using namespace std;

class Bike {
public:
    std::string brand; // Hiệu xe

    Bike(const std::string& brandName) : brand(brandName) {}

    void move(int t1) {
        cout << brand << ":" << t1 * 12 << " ";
    }
};

class EBike : public Bike {
public:
    EBike(const std::string& brandName) : Bike(brandName) {}

    void move(int t2) {
        Bike::move(t2 * 2);
    }
};

void display(Bike& a, Bike& b) {
    a.move(2);
    b.move(2);
}

int main() {
    EBike b1("EBike1");
    EBike b2("EBike2");
    display(b1, b2);

    return 0;
}