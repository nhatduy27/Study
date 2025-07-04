#include <iostream>
#include <vector>
using namespace std;



//Dùng Strategy Design Pattern

class Price {
private:
	float price;
	float intelligence;
	float strength;
public:
	Price(float price, float intelligence,float strength) 
		:price(price), intelligence(intelligence), strength(strength) {}

	float getPrice() { return price; }
	float getIntelligence() { return intelligence; }
	float getStrength() { return strength; }
	void SubtractPrice(float x) { price -= x; }
	void SubtractStrength(float x) { strength -= x; }


};

class Gate {

public:
	Gate(){}
	virtual bool execute(Price &p) = 0;
};



class BusinessGate : public Gate {
private:
	float price;
	int numbers;
public:
	BusinessGate(float price, int numbers) : price(price), numbers(numbers) {}

	bool execute(Price& p) {

		float totalPrice = price * numbers;
		p.SubtractPrice(totalPrice);
		if (p.getPrice() >= 0) {


			return true;
		}
		return false;
	}

};


class AcademicGate : public Gate {

private:
	float intelligence;
public:
	AcademicGate(int intelligence) : intelligence(intelligence) {}

	bool execute(Price& p) {

		return this->intelligence <= p.getIntelligence();
	}

};



class PowerGate : public Gate {

private:
	float power;
public:
	PowerGate(int power) : power(power) {}
	bool execute(Price& p) {

		p.SubtractStrength(power);
		if (p.getStrength() >= 0) return true;
		return false;
	}
};



class Castle {

private:
	vector<Gate*> gates;
public:
	Castle() { gates.clear(); }
	void add(Gate* p) { gates.push_back(p); }

	bool checking(Price &p) {

		for (int i = 0; i < gates.size(); i++) {

			if (!gates[i]->execute(p)) {

				return false;
			}
		}


		cout << "Hoang tu giai cuu thanh cong" << endl;
		cout << "Money: " << p.getPrice() << endl;
		cout << "Intelligence: " << p.getIntelligence() << endl;
		cout << "Strength: " << p.getStrength() << endl;

	}
};


int main() {

	Castle p;
	Gate* A = new BusinessGate(10.0, 10);
	Gate *  B = new AcademicGate(100);
	Gate* C = new PowerGate(150);

	p.add(A);
	p.add(B);
	p.add(C);

	Price D(101, 100, 160);
	p.checking(D);


	return 0;
}

