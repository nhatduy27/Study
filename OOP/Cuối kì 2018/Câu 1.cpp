#include <iostream>
#include <cstring>
using namespace std;




/*
a)
	Màn hình sẽ in ra :
		B text
		A default
b)
	=> Ban đầu chương trình sẽ khởi tạo đối tượng B mà gán m_s = "text" thông qua constructor của A, sau đó chương trình khai  báo con trỏ
	A giữ địa chỉ của đối tượng con là B thông qua constructor sao chép của B
	Gọi hàm foo các tham số A* obj1 đưa vào địa chỉ obj1, nhưng tham số A obj2 là đối tượng A do truyền bào kiểu tham trị
	Khi thực thi thì obj1 in ra B text do prepare được override lại ở lớp B

c)
	Thêm hàm hủy virtual ở lớp A để 
*/



class A {
private:
	char* m_s;
public:
	A() { m_s = _strdup("default"); }
	A(char* s) { m_s = s; }
	virtual void prepare() { cout << "A "; }
	void display() {
		prepare();
		cout << m_s << endl;
	}

	virtual ~A() {

		if (!m_s) delete m_s;
	}

};
class B : public A {
public:
	B(char* s) : A(s) { }
	B(const B& b) {}
	void prepare() { cout << "B "; }
};
void foo(A* obj1, A obj2) {
	obj1->display();
	obj2.display();
}
void main() {
	char* s = _strdup("text");
	B obj1(s);
	A* obj2 = new B(obj1);
	foo(&obj1, *obj2);


	delete obj2;
}