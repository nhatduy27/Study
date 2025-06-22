//Đề thi Kỹ Thuật Lập Trình 22TNT1TN 2022-2023 (HCMUS)

#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;


//--------------------------------------CÂU 1-----------------------------------------------

void updateResult(char*& result, int& len, int val) {

	char* newResult = new char[len + 2];
	for (int i = len - 1; i >= 0; i--) {

		newResult[i + 1] = result[i];
	}

	newResult[0] = val + '0';
	newResult[len + 1] = '\0';

	if (result) delete[]result;
	result = newResult;
	len++;

}


char* bitToString(int N) {

	if (N < 0) return NULL;
	char* result = NULL; //mảng chứa kết quả
	int len = 0; //độ dài cua mảng kết quả 

	do { //Thực hiện trước khi kiểm tra điều kiện để xử lí trường hợp N = 0

		int remainder = N % 2;
		updateResult(result, len, remainder);
		N /= 2;
	} while (N > 0);

	return result;
}



//--------------------------------------CÂU 2-----------------------------------------------


struct Node {

	int data;
	Node* next;
};

struct List {

	Node* head;
};



bool isSymmetric(List& L) {

	Node* temp = L.head;
	if (!L.head) return false;

	int RightNode = 0; //đếm số lượng Node
	while (temp) {

		RightNode++;
		temp = temp->next;
	}

	int leftNode = 1;
	temp = L.head; //gán lại temp = head

	while (leftNode < RightNode) {

		Node* temp2 = temp; //biến tạm để truy xuất data của Node đối xứng với temp
		int tempCount = leftNode; //biến đếm tạm

		while (tempCount < RightNode) {

			tempCount++;
			temp2 = temp2->next;
		}

		if (temp->data != temp2->data) return false; //trả về false nếu khác

		leftNode++;
		RightNode--;
		temp = temp->next;

		delete temp2;
	}

	return true;
}


//--------------------------------------CÂU 3-----------------------------------------------

//Đặt biến cục bộ
int* result = NULL;
int min_distance = INT_MAX;


void backtracking(int price[], int n, int k, int* hasPrice, int index) {

	if (index == n) {

		int* sum = new int[k]();
		for (int i = 0; i < n; i++) {

			sum[hasPrice[i]] += price[i];
		}

		int maxValue = sum[0];
		int minValue = sum[0];

		for (int i = 1; i < k; i++) {

			maxValue = max(maxValue, sum[i]);
			minValue = min(minValue, sum[i]);
		}

		int curDistance = maxValue - minValue;
		if (curDistance < min_distance) {

			if (result) delete[]result;

			result = new int[n]();

			for (int i = 0; i < n; i++) {

				result[i] = hasPrice[i];
			}

			min_distance = curDistance;
		}	
		delete[]sum;
		return;
	}

	for (int i = 0; i < k; i++) {

		hasPrice[index] = i;
		backtracking(price, n, k, hasPrice, index + 1);
	}
}

void print(int price[], int n, int k) {

	int* hasPrice = new int[n]();
	int index = 0;

	backtracking(price, n, k, hasPrice, 0);

	for (int i = 0; i < k; i++) {

		cout << "{ ";
		for (int j = 0; j < n; j++) {

			if (result[j] == i) cout << price[j] << " ";
		}
		cout << "}" << endl;
	}

	delete[]hasPrice;
	delete[]result;
}


//--------------------------------------CÂU 4-----------------------------------------------

//a)

long long fileSizeToDecimal(char fileSizeField[12]) {

	long long result = 0;
	int power = 1;

	for (int i = 10; i >= 0; i--) {

		if (fileSizeField[i] == '\0') {

			break;
		}

		int value = fileSizeField[i] - '0';
		result += value * power;
		power *= 8; 

	}

	return result;
}

//b)


const int BLOCK_SIZE = 512;
const int FILE_NAME_START = 0;
const int FILE_NAME_SIZE = 100;
const int FILE_SIZE_START = 124;
const int FILE_SIZE_SIZE = 12;


bool read(FILE* fp, char*&name, long long &fileSize, int start) {

	name = new char[FILE_NAME_SIZE + 1];
	name[FILE_NAME_SIZE] = '\0';
	fseek(fp, start + FILE_NAME_START, SEEK_SET);
	fread(name, 1, FILE_NAME_SIZE, fp);

	if (name[0] == '\0') return false;

	char* fileSizeChar = new char[FILE_SIZE_SIZE + 1];
	fileSizeChar[FILE_SIZE_SIZE] = '\0';
	fseek(fp, start + FILE_SIZE_START, SEEK_SET);
	fread(fileSizeChar, 1, FILE_SIZE_SIZE, fp);

	fileSize = fileSizeToDecimal(fileSizeChar);
	delete[]fileSizeChar;

	long long skip = (BLOCK_SIZE - (fileSize % BLOCK_SIZE)) % BLOCK_SIZE;
	fseek(fp, start + BLOCK_SIZE + fileSize + skip, SEEK_SET);

	return true;

}


void printFiles(const char* tarFile) {

	if (!tarFile) return;

	FILE* fp = NULL;
	int er = fopen_s(&fp, tarFile, "rb");
	if (!fp || er) return;

	char* name = NULL;
	long long size = 0;

	int start = 0;

	while (read(fp, name, size, start)) {

		cout << "Name: " << name << " ,Size = " << size << endl;
		start = ftell(fp);
		delete[]name;

	}
}



int main() {


	//Test câu 1
	cout << "Cau 1" << endl;
	int N = 10;
	char* result = bitToString(N);
	cout << result << endl;


	//Test câu 2

	cout << "Cau 2" << endl;

	List myList;
	Node* n1 = new Node{ 1, NULL };
	Node* n2 = new Node{ 3, NULL };
	Node* n3 = new Node{ 3, NULL };
	Node* n4 = new Node{ 5, NULL };

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	myList.head = n1;

	cout << "Doi xung: " << isSymmetric(myList) << endl;

	//Test câu 3

	cout << "Cau 3" << endl;
	int price[] = { 3,6,15,16,21 };
	int n = 5;
	int k = 2;
	print(price, n, k);

	cout << endl;

	//Test câu 
	cout << "Cau 4" << endl;
	printFiles("test.tar");


	return 0;
}

