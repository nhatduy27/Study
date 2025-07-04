
#include <iostream>
using namespace std;


/*
	Vấn đề trong đoạn code này là đối tượng b thuộc lớp A được khai báo trong hàm init. Đối tượng 
	obj từ hàm main được truyền tham chiếu vào trong hàm init.Sau khi thoát khỏi hàm thì b sẽ 
	được giải phóng nhưng sau khi ra khỏi hàm obj được xóa 1 lần nữa gây lỗi
*/

class A {
public:
	A() { a = new int[3]; for (int i = 0; i < 3; i++) a[i] = i + 1; }
	~A() { delete[] a; }
private:
	int* a;
};
void init(A& a) {
	A b;
	a = b;
}
void main() {
	A obj;
	init(obj);
}



/*
	Cách giải quyết tạo con trỏ thay vì đối tượng

class A {
public:
	A() { a = new int[3]; for (int i = 0; i < 3; i++) a[i] = i + 1; }
	~A() { delete[] a; }
private:
	int* a;
};
void init(A *&a) {

	A *b =new A;
	if (a) delete a;
	a = b;
}
void main() {
	A *obj =new A;
	init(obj);

	delete obj;
}

*/