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
	string getShape();
public:
	Face(string sh) : shape(sh) {
	}
	virtual void show() {
		cout << "Shape: " << shape << endl;
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

	EyedFace* clone() {
		return new EyedFace(getShape(), eyes);
	}
};