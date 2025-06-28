#include <iostream>
using namespace std;


/*

Câu 2a :
	- Tính đa hình là tính chất cho phép một đối tượng có thể có nhiều hình thái khác nhau tùy theo ngữ cảnh, tùy
	thuộc vào loại đối tượng con đang sử dụng
	- Tầm quan trọng của đa hình trong lập trình 
	+ Tăng tính linh hoạt
	+ Tái sử dụng mã hiệu quả
	+ Dễ mở rộng bảo trì
	+ Hỗ trợ thiết kế tổng quát
	+ Giúp các lớp con có thể sử dụng lại tính chất của lớp cha khi có nhiều điểm chung

	Ví dụ mình họa: lớp Animal là lớp cha, lớp con Dog cũng là 1 loài động vật nên có thể kế thừa và override lại
	hàm makeSound, ỏ class Dog chỉ có thể override khi có từ khóa virtual ở phương thức makeSound ở lớp cha
*/

class Animal {

public:
	virtual void makeSound() {

		cout << "Sound" << endl;
	}
};

class Dog : public Animal {
public:
	void makeSound() {

		cout << "Gau gau" << endl;
	}

};


/*
Câu 2b:
	Lớp trừu tượng là lớp có mục đích là tạo lớp bộ khung có sẵn cho các lớp con, đồng thời quy định các phương thức 
	cần có của các đối tượng. Lớp trừu tượng là lớp có ít nhất 1 hàm thuần ảo được khai báo bằng từ khóa "virtual" và "=0"

*/

class Animal {

public:
	virtual void makeSound() = 0;
};

class Dog : public Animal {
public:
	void makeSound() {

		cout << "Gau gau" << endl;
	}
};

class Cat : public Animal {
public:
	void makeSound() {

		cout << "Meo Meo" << endl;
	}
};

