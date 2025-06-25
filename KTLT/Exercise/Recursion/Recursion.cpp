#include <iostream>
#include <cmath>
using namespace std;

long long sumSequence(long long n) {

	if (n == 1) return 1;
	return n + sumSequence(n - 1);
}


long long factorial(long long n) {

	if (n == 1) return 1;
	return n * factorial(n - 1);
}

long long power(long long x, long long n) {

	if (n == 1) return x;
	return x * power(x, n - 1);
}

int countDigits(int n) {

	if (n == 0) return 0;
	return 1 + countDigits(n / 10);
}


int countOddDigits(int n) {

	if (n == 0) return 0;

	if (n % 2) return 1 + countOddDigits(n / 10);
	return countOddDigits(n / 10);
}


bool isEvenDigits(int n) {

	if (n == 0) return true;
	if (n % 2) return false;
	return isEvenDigits(n / 2);
}


int GCD(int a, int b) {

	if (!b) return a;
	return GCD(b, a % b);
}


void reverse(int n, int &result) {

	if (!n) return;

	result = result * 10 + (n % 10);
	return reverse(n / 10, result);
}

int reverseNumber(int n) {

	int result = 0;
	reverse(n, result);

	return result;
}


void binaryValue(int n) {

	if (n == 0) return;
	binaryValue(n / 2);
	cout << n % 2;
}


long long fibonacci(long long n) {


	if (n == 0) return 0;
	if (n == 1) return 1;
	return fibonacci(n - 1) + fibonacci(n - 2);
}

bool isPalindrome(const char* s, int left, int right) {

	if (left >= right) return true;
	if (s[left] != s[right]) return false;
	return isPalindrome(s, left + 1, right - 1);
}


void backtracking(const char* s, char* temp, bool *check, int i, int n) {

	if (i == n) {

		cout << temp << endl;
		return;
	}

	for (int j = 0; j < n; j++) {

		if (!check[j]) {

			temp[i] = s[j];
			check[j] = true;
			backtracking(s, temp, check, i + 1, n);
			check[j] = false;
		}
	}


}


void stringPermutation(const char* s, int n) {

	char* temp = new char[n + 1];
	bool* check = new bool[n]();
	for (int i = 0; i < n; i++) {

		check[i] = false;
	}
	temp[n] = '\0';
	backtracking(s, temp, check, 0, n);

}


int binarySearch(int* a, int left, int right, int key) {

	if (!a) return -1;
	if (left > right) return -1;

	int mid = (left + right) / 2;
	if (a[mid] == key) return mid;
	if (a[mid] < key) return binarySearch(a, mid + 1, right, key);
	return binarySearch(a, left, mid - 1, key);

}

int main() {

}