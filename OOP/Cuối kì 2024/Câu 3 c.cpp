#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Bank {

public:
	virtual void add(Bank* p) {}
	virtual float tinhGiaTri() = 0;
	virtual string type() = 0;
	virtual void printInfo() = 0;
};


class NganHang : public Bank {

private:
	string name;
	float soDu;
public:
	NganHang() : name(""), soDu(0) {}
	NganHang(string name, float soDu) : name(name) , soDu(soDu) {}
	float tinhGiaTri() {

		return soDu;
	}
	string type() {

		return "NganHang";
	}
	void printInfo() {

		cout << "name: " << name << ", soDu: " << soDu << endl;
	}
};


class ChungKhoang : public Bank {

private:
	string maCoPhieu;
	int soLuong;
	float giaCoPhieu;
public:
	ChungKhoang() : maCoPhieu(""), soLuong(0), giaCoPhieu(0) {}
	ChungKhoang(string maCoPhieu, int soLuong, float giaCoPhieu)
		: maCoPhieu(maCoPhieu) , soLuong(soLuong), giaCoPhieu(giaCoPhieu) {}

	float tinhGiaTri() {

		return soLuong * giaCoPhieu;
	}
	string type() {

		return "ChungKhoang";
	}
	void printInfo() {

		cout << "maCoPhieu: " << maCoPhieu << ", soLuong: " << soLuong << ", giaCoPhieu: "
			<< giaCoPhieu << endl;
	}
};


class TienSo : public Bank {

private:
	string maTienSo;
	float soDu;
	float tiGia;
public:
	TienSo() : maTienSo("0"), soDu(0), tiGia(0) {}
	TienSo(string maTienSo, float soDu, float tiGia) 
		:maTienSo(maTienSo) , soDu(soDu), tiGia(tiGia) {}

	float tinhGiaTri() {

		return soDu * tiGia;
	}
	string type() {

		return "TienSo";
	}
	void printInfo() {

		cout << "maTienSo: " << maTienSo << ", soDu: " << soDu << ", tiGia: "
			<< tiGia << endl;
	}
}; 


class HuTaiChinh : public Bank {
private:
	vector<Bank*> banks;
public:
	HuTaiChinh() { banks.clear(); }
	void add(Bank* p) {

		banks.push_back(p);
	}
	float tinhGiaTri() {

		for (int i = 0; i < banks.size(); i++) {

			cout << i + 1 << ". " << banks[i]->type() << ": " << banks[i]->tinhGiaTri() << endl;
		}
	}
	string type() {

		return "HuTaiChinh";
	}
	virtual void printInfo() {

		for (int i = 0; i < banks.size(); i++) {

			cout << banks[i]->type() << endl;
			banks[i]->printInfo();
		}
	}
};


int main() {
	// Tạo các tài sản riêng lẻ
	Bank* nganHang1 = new NganHang("Vietcombank", 5000000);
	Bank* chungKhoan1 = new ChungKhoang("VIC", 1000, 100.5);
	Bank* tienSo1 = new TienSo("USD", 2000, 23000);

	// Tạo HŨ TÀI CHÍNH CON và thêm các tài sản vào
	HuTaiChinh* huTaiChinhCon = new HuTaiChinh();
	huTaiChinhCon->add(nganHang1);
	huTaiChinhCon->add(chungKhoan1);
	huTaiChinhCon->add(tienSo1);

	// Tạo thêm một số tài sản khác
	Bank* nganHang2 = new NganHang("Techcombank", 3000000);
	Bank* chungKhoan2 = new ChungKhoang("FPT", 500, 150.75);

	// Tạo HŨ TÀI CHÍNH CHA và thêm các tài sản + HŨ CON vào
	HuTaiChinh* huTaiChinhCha = new HuTaiChinh();
	huTaiChinhCha->add(nganHang2);
	huTaiChinhCha->add(chungKhoan2);
	huTaiChinhCha->add(huTaiChinhCon); // Thêm cả HŨ CON vào HŨ CHA

	cout << "=== THONG TIN HU TAI CHINH CHA ===" << endl;
	huTaiChinhCha->printInfo();

	cout << "\n=== TINH GIA TRI HU TAI CHINH CHA ===" << endl;
	huTaiChinhCha->tinhGiaTri();

	// Giải phóng bộ nhớ
	delete nganHang1;
	delete chungKhoan1;
	delete tienSo1;
	delete nganHang2;
	delete chungKhoan2;
	delete huTaiChinhCon;
	delete huTaiChinhCha;

	return 0;
}