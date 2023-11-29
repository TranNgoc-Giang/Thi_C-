#include <iostream>
#include <string>

using namespace std;

class ThongTinKhachHang {
public:
    string ten;
    string soCMND;
    string diaChi;

    ThongTinKhachHang(string ten, string soCMND, string diaChi)
        : ten(ten), soCMND(soCMND), diaChi(diaChi) {}
};

class ThongTinCuocPhi {
public:
    virtual double tinhCuocDienThoai(double thoiLuongCuocGoi) const = 0;
    virtual double tinhCuocInternet(double luongTruyCap) const = 0;
    virtual double tinhTongCuocPhi() const = 0;
    virtual void inThongTinHopDong() const = 0;
    virtual ~ThongTinCuocPhi() {}
};

class HopDongCoBan : public ThongTinCuocPhi {
private:
    double giaCuocGoi;
    double giaCuocInternet;
    double thoiLuongCuocGoi;
    double luongTruyCap;

public:
    HopDongCoBan(double giaCuocGoi, double giaCuocInternet, double thoiLuongCuocGoi, double luongTruyCap)
        : giaCuocGoi(giaCuocGoi), giaCuocInternet(giaCuocInternet), thoiLuongCuocGoi(thoiLuongCuocGoi), luongTruyCap(luongTruyCap) {}

    double tinhCuocDienThoai(double thoiLuongCuocGoi) const override {
        return thoiLuongCuocGoi * giaCuocGoi;
    }

    double tinhCuocInternet(double luongTruyCap) const override {
        return luongTruyCap * giaCuocInternet;
    }

    double tinhTongCuocPhi() const override {
        return tinhCuocDienThoai(thoiLuongCuocGoi) + tinhCuocInternet(luongTruyCap) + 0.1 * (tinhCuocDienThoai(thoiLuongCuocGoi) + tinhCuocInternet(luongTruyCap));
    }

    void inThongTinHopDong() const override {
        cout << "Thong Tin Hop Dong Co Ban:" << endl;
        cout << "Cuoc Dien Thoai: " << tinhCuocDienThoai(thoiLuongCuocGoi) << endl;
        cout << "Cuoc Internet: " << tinhCuocInternet(luongTruyCap) << endl;
        cout << "Tong Cuoc Phi (bao gom VAT): " << tinhTongCuocPhi() << endl;
    }
};

int main() {
    ThongTinKhachHang khachHang1("John Doe", "123456789", "123 Duong Mai Hac De");
    ThongTinCuocPhi* hopDongCoBan1 = new HopDongCoBan(0.5, 0.1, 100, 500);

    hopDongCoBan1->inThongTinHopDong();

    cout << "-------------------------" << endl;

    ThongTinKhachHang khachHang2("Jane Smith", "987654321", "456 Duong Quang Trung");
    ThongTinCuocPhi* hopDongCoBan2 = new HopDongCoBan(0.4, 0.2, 150, 800);

    hopDongCoBan2->inThongTinHopDong();

    delete hopDongCoBan1;
    delete hopDongCoBan2;

    return 0;
}