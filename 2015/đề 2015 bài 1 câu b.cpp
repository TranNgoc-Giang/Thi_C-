class A {
public:
    A() {
        a = new int[3];
        for (int i = 0; i < 3; i++)
            a[i] = i + 1;
    }

    // Phương thức gán (assignment operator)
    A& operator=(const A& other) {
        if (this != &other) {
            delete[] a;
            a = new int[3];
            for (int i = 0; i < 3; i++)
                a[i] = other.a[i];
        }
        return *this;
    }

    ~A() {
        delete[] a;
    }

private:
    int* a;
};

void init(A& a) {
    A* b = new A();
    a = *b;
    delete b;
}

int main() {
    A obj;
    init(obj);
    return 0;
}