#include <iostream>
using namespace std;

class IFace {
public:
	virtual void show() = 0;
	virtual IFace* clone() = 0;
	virtual ~IFace() {}
};

class Face : public IFace {
private:
	string shape;

protected:
	string getShape() {
		return shape;
	}

public:
	Face(string sh) : shape(sh) {}

	virtual void show() {
		cout << "Shape: " << shape << endl;
	}

	virtual IFace* clone() {
		return new Face(shape);
	}
};

class EyedFace : public Face {
private:
	int eyes;
	static int count; // Số lượng đối tượng EyedFace đã được tạo

public:
	EyedFace(string sh, int e) : Face(sh), eyes(e) {
		count++;
	}

	~EyedFace() {
		count--;
	}

	void show() {
		Face::show();
		cout << "Eyes: " << eyes << endl;
	}

	IFace* clone() {
		return new EyedFace(getShape(), eyes);
	}

	static int getCount() {
		return count;
	}
};

int EyedFace::count = 0; // Khởi tạo giá trị cho biến static count

void testFace(IFace* fc) {
	IFace* a[3] = { fc, fc->clone(), fc->clone() };
	for (int i = 0; i < 3; i++) {
		a[i]->show();
	}
	cout << "The same 3 lines ? ";
}

int main() {
	IFace* fc = new EyedFace("Rectangle", 2);
	testFace(fc);
	delete fc;

	cout << "Number of EyedFace objects in memory: " << EyedFace::getCount() << endl;

	return 0;
}