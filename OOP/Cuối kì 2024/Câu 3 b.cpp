#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Bank {

public:
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


class Account {
protected:
	vector<Bank*> banks;
public:
	Account() { banks.clear(); }
	virtual void add(Bank* p) = 0;

	float tinhTongGiaTri() {

		for (int i = 0; i < banks.size(); i++) {

			cout << i + 1 << ". " << banks[i]->type() << banks[i]->tinhGiaTri() << endl;
		}
	}

	void printList() {

		for (int i = 0; i < banks.size(); i++) {

			cout << i + 1 << ". " << banks[i]->type();
			banks[i]->printInfo();
		}
	}

	virtual void tinhTongTheoLoai() {}
};

class Normal : public Account {
private:
	int numberAccount;
public:
	Normal() :Account(), numberAccount(0) {}
	void add(Bank* p) {

		if (numberAccount < 10) {

			banks.push_back(p);
			numberAccount++;
		}
	}
};

class VIP : public Account {
public:
	void add(Bank* p) {

		banks.push_back(p);
	}
	void tinhTongTheoLoai() {

		float nganHang = 0;
		float chungKhoang = 0;
		float tienSo = 0;

		for (int i = 0; i < banks.size(); i++) {

			if (banks[i]->type() == "NganHang") {

				nganHang += banks[i]->tinhGiaTri();
			}
			else if (banks[i]->type() == "ChungKhoang") {

				chungKhoang += banks[i]->tinhGiaTri();
			}
			else {
				tienSo += banks[i]->tinhGiaTri();
			}
		}

		cout << "NganHang: " << nganHang << endl;
		cout << "ChungKhoang: " << chungKhoang << endl;
		cout << "TienSo: " << tienSo << endl;
	}
};

int main() {
	// Tạo các đối tượng Bank
	Bank* nganHang1 = new NganHang("Vietcombank", 5000000);
	Bank* nganHang2 = new NganHang("Techcombank", 3000000);
	Bank* chungKhoang1 = new ChungKhoang("VIC", 100, 100000);
	Bank* chungKhoang2 = new ChungKhoang("VHM", 200, 80000);
	Bank* tienSo1 = new TienSo("USD", 5000, 23000);
	Bank* tienSo2 = new TienSo("EUR", 3000, 27000);

	// Tạo tài khoản Normal
	Normal normalAccount;
	normalAccount.add(nganHang1);
	normalAccount.add(chungKhoang1);
	normalAccount.add(tienSo1);

	cout << "Normal Account Information:" << endl;
	normalAccount.printList();
	cout << "Total Value:" << endl;
	normalAccount.tinhTongGiaTri();
	cout << endl;

	// Tạo tài khoản VIP
	VIP vipAccount;
	vipAccount.add(nganHang1);
	vipAccount.add(nganHang2);
	vipAccount.add(chungKhoang1);
	vipAccount.add(chungKhoang2);
	vipAccount.add(tienSo1);
	vipAccount.add(tienSo2);

	cout << "VIP Account Information:" << endl;
	vipAccount.printList();
	cout << "Total Value:" << endl;
	vipAccount.tinhTongGiaTri();
	cout << "Total Value by Type:" << endl;
	vipAccount.tinhTongTheoLoai();

	// Giải phóng bộ nhớ
	delete nganHang1;
	delete nganHang2;
	delete chungKhoang1;
	delete chungKhoang2;
	delete tienSo1;
	delete tienSo2;

	return 0;
}



