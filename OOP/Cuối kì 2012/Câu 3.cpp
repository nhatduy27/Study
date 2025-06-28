

/*
a)
	- Từ khóa "virtual" cho phép các lớp con có thể ghi đè phương thức này. Khi gọi hàm
	thông qua con trỏ của lớp lớp cha thì chương trình sẽ gọi đúng phương thức này ở
	lớp con
	- Việc gán bằng "=0" cùng với từ khóa "virtual" thực hiện việc khai báo hàm thuần ảo.
	Hàm thuần ảo là hàm không có boby và bắt buôc các lớp con phải thực hiện cài đặt lại
	hàm này. Nếu 1 lớp có lớp thuần ảo thì lớp này gọi là abstract class và lớp này sẽ
	không thể khai báo đối tượng trực tiếp, các lớp con cũng sẽ là abstract nếu như không
	cài đặt lại đầy đủ các hàm thuần ảo ở lớp cha
b)
	Cài đặt Lớp Cos

c)
	Cài đặt các hàm đạo hàm theo đề bài
d)
	Chỉnh sửa lớp Sin để chỉ tạo duy nhất một đói tượng lớp Sin

*/





#include <math.h>
#include <stdio.h>
class Function {
public:
	virtual double Value(double x) = 0;
	virtual double Derive(double x) = 0;
};


//Lớp Sin được sửa lại theo mẫu Singleton
class Sin :public Function {
private:
	static Function* p;
	Sin() {}
public:
	double Value(double x) {
		return sin(x);
	}
	double Derive(double x) {
		return cos(x);
	}

	static Function* getInstance();

};

double DeriveProduct(Function* f, Function* g, double x)
{
	if (f != NULL && g != NULL) {
		return f->Derive(x) * g->Value(x) + f->Value(x) * g->Derive(x);
	}
	return 0;
}


double DeriveSum(Function* f, Function* g, double x)
{
	if (f != NULL && g != NULL) {
		return f->Derive(x) + g->Derive(x);
	}
	return 0;
}


//Lớp Cos ở câu b

class Cos : public Function {

public:
	double Value(double x) {
		return cos(x);
	}
	double Derive(double x) {
		return -sin(x);
	}
};

// Cài đặt các hàm câu c

double DaoHamThuong(Function* f, Function* g, double x) {

	if (f != NULL && g != NULL && g->Value(x) != 0) {
		return ((f->Derive(x) * g->Value(x) - f->Value(x) * g->Derive(x)) / (g->Value(x) * g->Value(x)));
	}
	return 0;
}


//câu d

Function* Sin::getInstance() {

	if (p == NULL) {

		p = new Sin();
	}
	return p;
}


double DaoHamHop(Function* f, Function* g, double x) {

	if (f != NULL && g != NULL) {

		return f->Derive(g->Value(x)) * g->Derive(x);
	}
	return 0;
}

Function* Sin::p = NULL;


void main() {
	double x = 3.14 / 6; // PI/6
	//Sin* s = new Sin();    
	Function* s = Sin::getInstance(); // sử dụng Singleton thay vì new Sin()
	double y = DeriveProduct(s, s, x);
	printf("sin(x) = %f; sin'(x) = %f\n", s->Value(x), s->Derive(x));
	printf("y = %f\n", y);
}


