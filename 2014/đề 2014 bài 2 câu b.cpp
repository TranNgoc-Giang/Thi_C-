#include <iostream>
using namespace std;

class IFace {
public:
	virtual void show() = 0;
	virtual IFace* clone() = 0;
	virtual ~IFace() {
	}
};

class Face : public IFace {
private:
	string shape;

protected:
	string getShape() {
		return shape;
	}

public:
	Face(string sh) : shape(sh) {
	}

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

public:
	EyedFace(string sh, int e) : Face(sh), eyes(e) {}

	void show() {
		Face::show();
		cout << "Eyes: " << eyes << endl;
	}

	IFace* clone() {
		return new EyedFace(getShape(), eyes);
	}
};

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
	return 0;
}