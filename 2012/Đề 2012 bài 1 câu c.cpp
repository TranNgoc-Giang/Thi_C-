#include "PhanSo.h"

PhanSo::PhanSo(int tu, int mau) {
    this->tu = tu;
    this->mau = mau;
}

PhanSo PhanSo::operator+(const PhanSo& other) const {
    int newTu = this->tu * other.mau + this->mau * other.tu;
    int newMau = this->mau * other.mau;
    return PhanSo(newTu, newMau);
}

PhanSo& PhanSo::operator++() {
    this->tu += this->mau;
    return *this;
}

PhanSo PhanSo::operator+=(const PhanSo& other) {
    *this = *this + other;
    return *this;
}

PhanSo::operator int() const {
    return tu / mau;
}

std::ostream& operator<<(std::ostream& os, const PhanSo& ps) {
    os << ps.tu << "/" << ps.mau;
    return os;
}
