#include <iostream>
using namespace std;



/*
	Kết quả in ra màn hình là:
		3 4 
	Chương trình khởi tạo 2 đối tượng B nhưng khi truyền vào hàm thì biến x là đối tượng A
	do được truyền vào kiểu tham trị
	a.f(3) gọi hàm f của class A
	b.f(3) gọi hàm f của class B do f được override từ lớp A sau đó gọi vào hàm f(3+1)
	của lớp A 
*/

class A {
public:
	virtual void f(int x) { cout << x << " "; }
};
class B : public A {
public:
	void f(int y) { A::f(y + 1); }
};
void doSomething(A a, B b) { a.f(3); b.f(3); }


void main() {
	B x, y;
	doSomething(x, y);
}