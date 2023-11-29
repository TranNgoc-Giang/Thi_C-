#include <iostream>

class Shape {
public:
    virtual void Draw() {
        std::cout << "Vẽ một hình dạng." << std::endl;
    }
};

class Circle : public Shape {
public:
    void Draw() override {
        std::cout << "Vẽ một hình tròn." << std::endl;
    }
};

class Square : public Shape {
public:
    void Draw() override {
        std::cout << "Vẽ một hình vuông." << std::endl;
    }
};

int main() {
    Shape* shape1 = new Circle();
    Shape* shape2 = new Square();

    shape1->Draw(); // Vẽ một hình tròn.
    shape2->Draw(); // Vẽ một hình vuông.

    delete shape1;
    delete shape2;

    return 0;
}