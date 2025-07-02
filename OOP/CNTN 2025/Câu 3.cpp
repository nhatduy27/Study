#include <iostream>
#include <vector>
#include <cmath>
using namespace std;



//class Interface
template <typename T>
class Filter {
public:
    virtual bool execute(T element, int index, vector<T> array) = 0;
};


//Các class thực thi chức năng

template <typename T>
class DivisibleFilter : public Filter<T> {
private:
    int N;
public:
    DivisibleFilter(int N) : N(N){}
    bool execute(T element, int index, vector<T> array);
};


template <typename T>
class OddIndexFilter : public Filter<T> {

public:
    bool execute(T element, int index, vector<T> array);
};


template <typename T>
class DiffAvgFilter : public Filter<T> {
private:
    double M;
public:
    DiffAvgFilter(double M) : M(M){}
    bool execute(T element, int index, vector<T> array);
};

////class sử dụng filters

template <typename T>
class Extractor {

    vector <Filter<T>*> filters;
public:

    void add(Filter<T>* p);
    vector<T> extract(vector<T> &arr);
};



//Triển khai các hàm

template <typename T>
bool DivisibleFilter<T>::execute(T element, int index, vector<T> array) {

    return element % N == 0;
}

template <typename T>
bool OddIndexFilter<T>::execute(T element, int index, vector<T> array) {

    return index % 2 != 0;
}

template <typename T>
bool DiffAvgFilter<T>::execute(T element, int index, vector<T> array) {
    if (array.empty()) return false;

    double sum = 0;
    for (int i = 0; i < array.size(); i++) {
        sum += array[i];
    }
    double avg = sum / array.size();

    double diff = abs(element - avg);
    double threshold = (M) * avg;

    return diff <= threshold;
}



template <typename T>
void Extractor<T>::add(Filter<T>* p) {

    filters.push_back(p);
}


template <typename T>
vector<T> Extractor<T>::extract(vector<T>& arr) {
    vector<T> result;

    for (int i = 0; i < arr.size(); i++) {
        bool check = true;

        for (int j = 0; j < filters.size(); j++) {
            if (!filters[j]->execute(arr[i], i, arr)) {
                check = false;
                break;
            }
        }

        if (check) {
            result.push_back(arr[i]);
        }
    }

    return result;
}


int main() {

    Extractor<int> ex;
    ex.add(new DivisibleFilter<int>(3));
    ex.add(new OddIndexFilter<int>());
    ex.add(new DiffAvgFilter<int>(0.2));

    std::vector<int> a = { 10, 3, 15, 6 , 2, 9, 4, 15, 5, 6 };
    std::vector<int> b = ex.extract(a);

    for (auto &e : b) {
        std::cout << e << " ";
    }
    // Kết quả mong đợi: 9 6 9
    return 0;
}



