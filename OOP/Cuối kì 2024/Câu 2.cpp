#include <iostream>
#include <string>
using namespace std;


struct Node {
	int key;
	Node* pNext;
};

Node* createNode(int x) {

	Node* newNode = new Node;
	newNode->key = x;
	newNode->pNext = NULL;

	return newNode;
}


class IStack {
public:
	virtual void push(int x) = 0;
	virtual int pop() = 0;
	virtual int size() = 0;
	virtual void clear() = 0;
};



class StackByLinkedList : public IStack {

private:
	Node* pHead;
public:

	StackByLinkedList() : pHead(NULL) {}

	void push(int x) {

		Node* newNode = createNode(x);
		if (!pHead) {

			pHead = newNode;
			return;
		}

		Node* temp = pHead;
		while (temp->pNext) temp = temp->pNext;
		temp->pNext = newNode;
	}

	int pop() {

		if (!pHead) throw string("NULL");
		Node* temp = pHead;
		Node* prev = NULL;
		while (temp->pNext) {

			prev = temp;
			temp = temp->pNext;
		}
		int result = temp->key;
		if (prev) prev->pNext = NULL;
		else pHead = NULL;

		delete temp;
		return result;
	}


	int size() {

		int result = 0;
		Node* temp = pHead;
		while (temp) {
			result++;
			temp = temp->pNext;
		}

		return result;
	}

	void clear() {

		while (pHead)
		{
			Node* temp = pHead;
			pHead = pHead->pNext;
			delete temp;
		}

		pHead = NULL;
	}

	void print() {

		if (!pHead) return;
		Node* temp = pHead;
		while (temp) {

			cout << temp->key << " ";
			temp = temp->pNext;
		}
		cout << endl;
	}

};


int main() {

	StackByLinkedList p;
	try {
		int value = p.pop();
		cout << value;
	}
	catch(string s){
		cout << "Error: " << s << endl;
	}
	p.print();

	return 0;

}