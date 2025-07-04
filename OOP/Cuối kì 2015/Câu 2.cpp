
#include <iostream>
#include <string>
using namespace std;


class BigInteger {

private:
	string number;
public:
	BigInteger() : number("0") {}
	BigInteger(string s) : number(s) {}

	friend istream& operator >> (istream& in, BigInteger& p) {

		in >> p.number;
		return in;
	}


	bool operator ==(const BigInteger& p) {

		int len1 = number.length();
		int len2 = p.number.length();

		if (len1 != len2) return false;

		for (int i = 0; i < len1; i++) {

			if (number[i] != p.number[i]) return false;
		}
		return true;
	}
};



void main() {
	BigInteger n1("1234567891011"); // Khởi tạo từ chuỗi.
	BigInteger n2; // Khởi tạo mặc định = 0.
	cout << "Input an integer = ";
	cin >> n2;
	if (n1 == n2) // So sánh bằng nhau.
		cout << "Equal.\n";
	else
		cout << "Not equal.\n";
}