#include <iostream>
using namespace std;

class PhanSo {

private:
	int tu;
	int mau;
public:
	PhanSo();
	PhanSo(int a, int b);
	PhanSo(int a);
	PhanSo operator+(PhanSo p);
	friend ostream& operator <<(ostream& out, PhanSo p);
	PhanSo& operator+=(PhanSo p);
	operator int();
	PhanSo& operator ++();
};


PhanSo::PhanSo() :tu(0), mau(1) {}
PhanSo::PhanSo(int a, int b) : tu(a), mau(b) {}
PhanSo::PhanSo(int a) : tu(a), mau(1) {}

PhanSo PhanSo::operator+(PhanSo p) {

	PhanSo Result;
	Result.tu = tu * p.mau + mau * p.tu;
	Result.mau = mau * p.mau;
	return Result;
}

ostream& operator <<(ostream& out, PhanSo p) {

	out << p.tu << "/" << p.mau << endl;
	return out;
}


PhanSo& PhanSo::operator+=(PhanSo p) {

	tu = tu * p.mau + p.tu * mau;
	mau = mau * p.mau;
	return *this;
}

PhanSo::operator int() {

	return tu / mau;
}

PhanSo& PhanSo::operator ++() {

	tu += mau;
	return *this;
}

int main() {
	PhanSo a(1, 3), c;
	int b = 8;
	c = a + (PhanSo)b;
	cout << "c = " << a << " + " << b << " = " << c << endl;
	cout << "++c: ";
	cout << "c = " << ++c << endl;
	cout << "a = " << a << " + " << c << endl;
	a += c;
	cout << "a = " << a << endl;
	b = a;
	cout << "b = " << b << endl;
	return 0;
}