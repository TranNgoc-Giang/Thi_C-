#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Lớp cơ sở cho máy lọc
class MayLocNuoc {
protected:
    float donGiaThue; // Đơn giá thuê
    float chiPhiSuDung;  // Chi phí nhiên liệu hoặc hóa chất
    float thoiGianHoatDong; // Thời gian hoạt động

public:
    MayLocNuoc(float gia, float chiPhi) : donGiaThue(gia), chiPhiSuDung(chiPhi), thoiGianHoatDong(0) {}

    virtual ~MayLocNuoc() {}

    virtual float tinhCongSuat() const = 0; // Hàm ảo pure virtual, cần được định nghĩa ở các lớp con
    virtual float tinhTongChiPhi() const = 0; // Hàm ảo pure virtual, cần được định nghĩa ở các lớp con

    void datThoiGianHoatDong(float thoiGian) {
        thoiGianHoatDong = thoiGian;
    }
};

// Lớp con MayLocLyTam kế thừa từ MayLocNuoc
class MayLocLyTam : public MayLocNuoc {
private:
    float luongXangTieuThu; // Lượng xăng sử dụng (lít/giờ)

public:
    MayLocLyTam(float gia, float xang) : MayLocNuoc(gia, 0), luongXangTieuThu(xang) {}

    // Định nghĩa hàm ảo từ lớp cơ sở
    float tinhCongSuat() const override {
        return donGiaThue * thoiGianHoatDong;
    }

    float tinhTongChiPhi() const override {
        return (donGiaThue + chiPhiSuDung) * thoiGianHoatDong;
    }
};

// Lớp con MayLocXucTac kế thừa từ MayLocNuoc
class MayLocXucTac : public MayLocNuoc {
private:
    float luongHoaChat; // Lượng hóa chất sử dụng (kg/giờ)

public:
    MayLocXucTac(float gia, float hoaChat) : MayLocNuoc(gia, hoaChat), luongHoaChat(hoaChat) {}

    // Định nghĩa hàm ảo từ lớp cơ sở
    float tinhCongSuat() const override {
        return donGiaThue * thoiGianHoatDong * (luongHoaChat / 100);
    }

    float tinhTongChiPhi() const override {
        return (donGiaThue + chiPhiSuDung) * thoiGianHoatDong;
    }
};

// Lớp quản lý các máy lọc
class QuanLyMayLocNuoc {
private:
    vector<MayLocNuoc*> danhSachMayLoc; // Danh sách máy lọc

public:
    ~QuanLyMayLocNuoc() {
        // Giải phóng bộ nhớ khi đối tượng QuanLyMayLocNuoc bị hủy
        for (MayLocNuoc* mayLoc : danhSachMayLoc) {
            delete mayLoc;
        }
    }

    void themMayLoc(MayLocNuoc* mayLoc) {
        danhSachMayLoc.push_back(mayLoc);
    }

    float tinhTongCongSuat() const {
        float tongCongSuat = 0;
        for (const MayLocNuoc* mayLoc : danhSachMayLoc) {
            tongCongSuat += mayLoc->tinhCongSuat();
        }
        return tongCongSuat;
    }

    float tinhTongChiPhi() const {
        float tongChiPhi = 0;
        for (const MayLocNuoc* mayLoc : danhSachMayLoc) {
            tongChiPhi += mayLoc->tinhTongChiPhi();
        }
        return tongChiPhi;
    }
};

int main() {
    QuanLyMayLocNuoc quanLy;

    // Thêm các máy lọc vào danh sách
    MayLocLyTam* mayLocLyTam = new MayLocLyTam(50000, 5);
    mayLocLyTam->datThoiGianHoatDong(2);
    quanLy.themMayLoc(mayLocLyTam);

    MayLocXucTac* mayLocXucTac = new MayLocXucTac(80000, 2);
    mayLocXucTac->datThoiGianHoatDong(3);
    quanLy.themMayLoc(mayLocXucTac);

    // Tính toán và xuất kết quả
    cout << "Tong Cong Suat: " << quanLy.tinhTongCongSuat() << " m3" << endl;
    cout << "Tong Chi Phi: " << quanLy.tinhTongChiPhi() << " VND" << endl;

    return 0;
}
