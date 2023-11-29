class Singleton {
public:
    // Phương thức tĩnh để truy cập đối tượng Singleton
    static Singleton& getInstance() {
        static Singleton instance; // Thể hiện duy nhất của Singleton
        return instance;
    }

    // Các phương thức công khai khác của lớp Singleton

private:
    // Hạn chế việc tạo mới đối tượng Singleton từ bên ngoài lớp
    Singleton() {}

    // Hạn chế việc sao chép đối tượng Singleton từ bên ngoài lớp
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    // Các thành viên dữ liệu của lớp Singleton
};