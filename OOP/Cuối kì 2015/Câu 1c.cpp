#include <iostream>
using namespace std;



/*
	Đảm bảo chỉ tạo một đối tượng A duy nhất
	Xóa khởi tạo A và hủy A tự động , viết hàm xóa A::a để người dùng có thể
	chủ động trong việc giải phóng vùng nhớ của con trỏ A::a đang trỏ tới
	- Không gán a = b vì sau khi xóa b đang trỏ đến vùng nhớ đã xóa


*/

class A {
public:
	static int* getInstance() {

		if (!a) {

			a = new int[3]; for (int i = 0; i < 3; i++) a[i] = i + 1;
		}
		return a;

	}
	static void destroyPointer() {

		if (a) delete[] a;
		a = NULL;
	}

private:
	static int* a;
	A() = delete;
	~A() = delete;
};
void init(int*& a) {

	int* b = A::getInstance();
	if (a) {
		A::destroyPointer();
		a = NULL;
	}
	//a = b;
}


int* A::a = NULL;

void main() {

	int* obj = A::getInstance();
	init(obj);

	A::destroyPointer();
}