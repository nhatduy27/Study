#include <iostream>
using namespace std; 



struct Node {

	int key;
	Node * pNext;
};

struct List {

	Node * pHead;
	Node * pTail;
};

Node* createNode(int data) {

	Node* newNode = new Node;
	newNode->key = data;
	newNode->pNext = NULL;

	return newNode;
}


List* createList(Node* pNode) {

	List* newList = new List;
	newList->pHead = pNode;
	newList->pTail = pNode;

	return newList;
}


bool addHead(List*& L, int data) {

	Node* newNode = createNode(data);
	if (!newNode) return false;
	if (!L) {

		L = createList(newNode);
		return true;
	}

	newNode->pNext = L->pHead;
	L->pHead = newNode;
	return true;
}


bool addTail(List*& L, int data) {

	Node* newNode = createNode(data);
	if (!newNode) return false;
	if (!L) {

		L = createList(newNode);
		return true;
	}

	L->pTail->pNext = newNode;
	L->pTail = newNode;
	return true;
}

bool addPos(List*& L, int val, int pos) {

	Node* newNode = createNode(val);
	if (!newNode || !L) return false;

	Node* prev = NULL;
	Node* temp = L->pHead;
	int count = 0;

	while (temp && (count < pos)) {

		count++;
		prev = temp;
		temp = temp->pNext;
	}

	if (count < pos) return false;

	if (prev) {

		newNode->pNext = temp;
		prev->pNext = newNode;
	}
	else {

		newNode->pNext = L->pHead;
		L->pHead = newNode;
	}

	if (prev == L->pTail) L->pTail = newNode;
	return true;

}


bool addBefore(List*& L, int data, int val) {

	if (!L) return false;

	Node* prev = NULL;
	Node* temp = L->pHead;

	while (temp) {

		if (temp->key == val) {

			Node* newNode = createNode(data);
			if (prev) {

				newNode->pNext = temp;
				prev->pNext = newNode;
			}
			else {

				newNode->pNext = L->pHead;
				L->pHead = newNode;
			}

		}

		prev = temp;
		temp = temp->pNext;
	}
	return true;
}


bool addAfter(List*& L, int data, int val) {

	if (!L) return false;

	Node* temp = L->pHead;

	while (temp) {

		if (temp->key == val) {

			Node* newNode = createNode(data);
			Node* next = temp->pNext;

			if (temp->pNext) {

				newNode->pNext = next;
				temp->pNext = newNode;
			}
			else {

				temp->pNext = newNode;
				L->pTail = newNode;
			}

			temp = next;
		}
		else {

			temp = temp->pNext;
		}
	}
	return true;
}



void removeHead(List*& L) {

	if (!L) return;

	Node* temp = L->pHead;
	L->pHead = L->pHead->pNext;
	delete temp;

	if (!L->pHead) L->pTail = NULL;
}

void removeTail(List*& L) {

	if (!L) return;

	Node* prev = NULL;
	Node* temp = L->pHead;

	while (temp != L->pTail) {

		prev = temp;
		temp = temp->pNext;
	}

	Node* deleteNode = temp;
	temp = temp->pNext;
	delete deleteNode;

	if (!prev) L->pHead = NULL;

}


void removePos(List*& L, int pos) {

	if (!L || pos < 0) return;

	Node* prev = NULL;
	Node* temp = L->pHead;
	int count = 0;

	while (temp && count < pos) {

		count++;
		prev = temp;
		temp = temp->pNext;
	}

	if ((count < pos) || !temp) return;

	if (prev) {

		Node* next = temp->pNext;
		prev->pNext = next;
	}

	else {

		L->pHead = L->pHead->pNext;
	}

	if (temp == L->pTail) {

		L->pTail = prev;
	}
	delete temp;

}

void removeAll(List*& L) {

	if (!L) return;

	while (L->pHead) {

		Node* temp = L->pHead;
		L->pHead = L->pHead->pNext;

		delete temp;
		
	}
	L->pHead = L->pTail = NULL;
}


void removeBefore(List* L, int val) {

	if (!L) return;

	Node* prev = NULL;
	Node* temp = L->pHead;

	while (temp && temp->pNext) {

		if (temp->pNext->key == val) {

			Node* next = temp->pNext;
			if (prev) prev->pNext = next;
			else L->pHead = next;

			delete temp;
			temp = next;
		}
		else {

			prev = temp;
			temp = temp->pNext;
		}
	}
}


void removeAfter(List* L, int val) {

	if (!L) return;

	Node* temp = L->pHead;

	while (temp && temp->pNext) {

		if (temp->key == val) {

			Node* next = temp->pNext;
			temp->pNext = next->pNext;

			if (next == L->pTail) L->pTail = temp;

			delete next;

		}
		temp = temp->pNext;
	}
}





void printList(List *L) {

	Node *temp = L->pHead;
	while (temp) {

		cout << temp->key << " ";
		temp = temp->pNext;
	}
	cout << endl;
}


int countElements(List* L) {

	int count = 0;

	Node* temp = L->pHead;
	while (temp) {

		count++;
		temp = temp->pNext;
	}
	return count;
}

List* reverseList(List* L) {

	if (!L) return NULL;

	List* newL = NULL;
	Node* temp = L->pHead;

	while (temp) {

		addHead(newL, temp->key);
		temp = temp->pNext;
	}

	return newL;

}

void removeDuplicate(List*& L) {

	if (!L) return;
	Node* temp = L->pHead;

	while (temp) {

		Node* prev = temp;
		Node* temp2 = temp->pNext;

		while (temp2) {

			if (temp2->key == temp->key) {

				Node* next = temp2->pNext;
				prev->pNext = next;

				if (!next) L->pTail = prev;
				delete temp2;
				temp2 = next;
			}
			else {

				prev = temp2;
				temp2 = temp2->pNext;
			}

		}
		temp = temp->pNext;
 	}
}



bool removeElement(List*& L, int val) {

	if (!L) return false;

	Node* prev = NULL;
	Node* temp = L->pHead;

	while (temp) {

		if (temp->key == val) {

			Node* next = temp->pNext;
			if (prev) prev->pNext = next;
			else L->pHead = next;

			if (!next) L->pTail = prev;
			delete temp;
			temp = next;
		}
		else {

			prev = temp;
			temp = temp->pNext;
		}
	}
	return true;
}


int main() {

	List* L = NULL;


	


	return 0;
}