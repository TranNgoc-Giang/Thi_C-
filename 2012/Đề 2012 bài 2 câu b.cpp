#include <iostream>

class Shape {
public:
    virtual void Draw() = 0; // Phương thức trừu tượng

    void DisplayArea() {
        std::cout << "Diện tích: " << CalculateArea() << std::endl;
    }

protected:
    virtual double CalculateArea() = 0; // Phương thức trừu tượng

};

class Circle : public Shape {
public:
    void Draw() override {
        std::cout << "Vẽ một hình tròn." << std::endl;
    }

    double CalculateArea() override {
        // Triển khai tính diện tích hình tròn
        return 3.14 * radius * radius;
    }

private:
    double radius = 5.0;
};

class Rectangle : public Shape {
public:
    void Draw() override {
        std::cout << "Vẽ một hình chữ nhật." << std::endl;
    }

    double CalculateArea() override {
        // Triển khai tính diện tích hình chữ nhật
        return length * width;
    }

private:
    double length = 4.0;
    double width = 6.0;
};

int main() {
    Circle circle;
    circle.Draw(); // Vẽ một hình tròn.
    circle.DisplayArea(); // Diện tích: 78.5

    Rectangle rectangle;
    rectangle.Draw(); // Vẽ một hình chữ nhật.
    rectangle.DisplayArea(); // Diện tích: 24

    return 0;
}