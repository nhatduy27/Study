#include <iostream>
using namespace std;



class Fraction {
private:
    int tu;
    int mau;
public:
    Fraction() : tu(0), mau(1) {}
    Fraction(int tu, int mau) : tu(tu), mau(mau){}
    friend ostream& operator << (ostream& out, Fraction p) {
        out << p.tu << "/" << p.mau;
        return out;
    }

    int getTu() { return tu; }
    int getMau() { return mau; }


};

class PrimeFracIterator {

private:
    Fraction* a;
    int length;
    int index;
public:
    PrimeFracIterator() : a(NULL), length(0), index(0) {}
    PrimeFracIterator(Fraction a[], int length)
        : a(a), length(length), index(0) {
        
        if ((index < length) &&
            (!SoNguyenTo(a[index].getTu()) || !SoNguyenTo(a[index].getMau()))) {
            index++;
        }
    
    }

    bool SoNguyenTo(int x) {

        int count = 0;
        for (int i = 1; i <= x; i++) {

            if (x % i == 0) count++;
        }
        return count == 2;
    }

    operator bool() {
        return index < length;
    }

    Fraction& operator*() {

        return a[index];
    }

    void operator ++() {

        index++;
        if ((index < length) && 
            (!SoNguyenTo(a[index].getTu()) || !SoNguyenTo(a[index].getMau()))) {
            index++;
        }
    }

};




int main() {
    Fraction a[] = { {1, 2}, {2, 3}, {4, 2}, {3, 5} };
    int n = sizeof(a) / sizeof(a[0]);

    PrimeFracIterator i(a, n);
    while (i) {
        std::cout << *i << " ";
        ++i;
    }

    return 0;
}