#ifndef PHANSO_H
#define PHANSO_H

#include <iostream>

class PhanSo {
private:
    int tu;
    int mau;

public:
    PhanSo(int tu = 0, int mau = 1);
    PhanSo operator+(const PhanSo& other) const;
    PhanSo& operator++();
    PhanSo operator+=(const PhanSo& other);
    operator int() const;

    friend std::ostream& operator<<(std::ostream& os, const PhanSo& ps);
};

#endif
