#include <iostream>
#include <vector>
using namespace std;



class Sap {

protected:
	const static float DON_GIA_THUE;
	static int numberOfSap;
	int STT;
	float area;
	float DOANH_THU;
public:
	Sap() : STT(0), area(0), DOANH_THU(0.0) {}
	Sap(float area, float DOANH_THU) :  area(area), DOANH_THU (DOANH_THU) {

		numberOfSap++;
		STT = numberOfSap;
	}
	int getSTT() { return STT; }
	virtual float tinhTienThue() = 0;
};



class SapThucPham : public Sap {
private:
	const static float THUE_THUC_PHAM;
public:

	SapThucPham() : Sap() {}
	SapThucPham(float area, float DOANH_THU) : Sap(area, DOANH_THU) {}
	float tinhTienThue() {

		float result = DON_GIA_THUE * area + DOANH_THU * THUE_THUC_PHAM;
		return result;
	}
};

class SapQuanAo : public Sap {
private:
	const static float THUE_QUAN_AO;
public:
	SapQuanAo() : Sap() {}
	SapQuanAo(float area, float DOANH_THU) : Sap(area, DOANH_THU) {}
	float tinhTienThue() {

		float result = DON_GIA_THUE * area + DOANH_THU * THUE_QUAN_AO;
		return result;
	}
};


class SapTrangSuc : public Sap {
private:
	static float THUE_TRANG_SUC;
public:
	SapTrangSuc() : Sap() {}
	SapTrangSuc(float area, float DOANH_THU) : Sap(area, DOANH_THU) {
	
		if (DOANH_THU < 100) {

			THUE_TRANG_SUC = 0.2;
		}
		else {

			THUE_TRANG_SUC = 0.3;
		}
	}

	float tinhTienThue() {

		float result = DON_GIA_THUE * area + DOANH_THU * THUE_TRANG_SUC;
		return result;
	}
};




class Market {

private:
	vector<Sap*> saps;
public:
	Market() { saps.clear(); }
	void add(Sap* p) { saps.push_back(p); }
	void tinhTongTien() {

		for (int i = 0; i < saps.size(); i++) {

			cout << "Sap " << saps[i]->getSTT() << ": " << saps[i]->tinhTienThue();
			cout << endl;
		}
	}

};

int Sap::numberOfSap = 0;
const float Sap::DON_GIA_THUE = 40;
const float SapThucPham::THUE_THUC_PHAM = 0.05;
const float SapQuanAo::THUE_QUAN_AO = 0.1;
float SapTrangSuc::THUE_TRANG_SUC = 0;

int main() {


	Sap* A = new SapQuanAo(10, 10);
	Sap* B = new SapThucPham(20, 20);
	Sap* C = new SapTrangSuc(30, 30);
	Market p;
	p.add(A); p.add(B); p.add(C);

	p.tinhTongTien();

	return 0;

}