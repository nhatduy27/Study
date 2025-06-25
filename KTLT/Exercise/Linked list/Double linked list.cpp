#include <iostream>
using namespace std;


struct DNode {

	int key;
	DNode * pNext;
	DNode * pPrev;
};

struct DList {

	DNode * pHead;
	DNode * pTail;
};



DNode* createNode(int data) {

	DNode* newNode = new DNode;
	newNode->key = data;
	newNode->pNext = newNode->pPrev = NULL;

	return newNode;
}

DList* createList(DNode* pNode) {

	DList* newList = new DList;
	newList->pHead = newList->pTail = pNode;

	return newList;
}


bool addHead(DList*& L, int data) {

	DNode* newNode = createNode(data);
	if (!newNode) return false;
	if (!L) {

		L = createList(newNode);
		return true;
	}

	newNode->pNext = L->pHead;
	L->pHead->pPrev = newNode;
	L->pHead = newNode;

	return true;
}



bool addTail(DList*& L, int data) {

	DNode* newNode = createNode(data);
	if (!newNode) return false;

	if (!L) {

		L = createList(newNode);
		return true;
	}

	L->pTail->pNext = newNode;
	newNode->pPrev = L->pTail;
	L->pTail = newNode;
	return true;
}

bool addPos(DList*& L, int val, int pos) {

	DNode* newNode = createNode(val);
	if (!L || !newNode) return false;

	DNode* prev = NULL;
	DNode* temp = L->pHead;
	int count = 0;

	while (temp && (count < pos)) {

		count++;
		prev = temp;
		temp = temp->pNext;
	}

	if (!temp && (count < pos)) return false;

	if (prev) {

		newNode->pNext = temp;
		if (temp) temp->pPrev = newNode;
		else L->pTail = newNode;
		newNode->pPrev = prev;
		prev->pNext = newNode;
	}
	else {

		newNode->pNext = temp;
		temp->pPrev = newNode;
		L->pHead = newNode;
	}

	
}



bool addBefore(DList*& L, int data, int val) {


	if (!L) return false;

	DNode* prev = NULL;
	DNode* temp = L->pHead;

	while (temp) {

		if (temp->key == val) {

			DNode* newNode = createNode(data);
			newNode->pNext = temp;
			temp->pPrev = newNode;
			newNode->pPrev = prev;

			if (prev) prev->pNext = newNode;
			else L->pHead = newNode;
		}

		prev = temp;
		temp = temp->pNext;

	}
	return true;
}


bool addAfter(DList*& L, int data, int val) {

	if (!L) return false;

	DNode* temp = L->pHead;

	while (temp) {

		if (temp->key == val) {

			DNode* newNode = createNode(data);
			DNode* next = temp->pNext;

			temp->pNext = newNode;
			newNode->pPrev = temp;
			newNode->pNext = next;

			if (next) next->pPrev = newNode;
			else L->pTail = newNode;

			temp = next;
		}

		else {

			temp = temp->pNext;
		}
	}
	return true;
}


void removeHead(DList*& L) {

	if (!L) return;

	DNode* temp = L->pHead;
	L->pHead = L->pHead->pNext;
	L->pHead->pPrev = NULL;

	temp->pNext = NULL;

	delete temp;
}


void removeTail(DList*& L) {

	if (!L) return;

	DNode* temp = L->pTail;
	L->pTail = L->pTail->pPrev;
	L->pTail->pNext = NULL;

	temp->pPrev = NULL;
	delete temp;

}


void removePos(DList*& L, int pos) {

	if (!L) return;

	DNode* temp = L->pHead;
	int count = 0;

	while (temp && (count < pos )) {

		count++;
		temp = temp->pNext;
	}

	if (!temp || (count < pos)) return;

	DNode* prev = temp->pPrev;
	DNode* next = temp->pNext;

	if (prev) prev->pNext = next;
	else L->pHead = next;
	if (next) next->pPrev = prev;
	else L->pTail = prev;

	delete temp;
}


void removeAll(DList*& L) {

	if (!L) return;

	while (L->pHead) {

		DNode* temp = L->pHead;
		L->pHead = L->pHead->pNext;
		L->pHead->pPrev = NULL;

		delete temp;
	}

	L->pHead = L->pTail = NULL;

}


void removeBefore(DList* L, int val) {

	if (!L) return;

	DNode* temp = L->pHead;
	DNode* next = L->pHead->pNext;

	while (temp && next) {

		if (next->key == val) {

			DNode* prev = temp->pPrev;
			if (prev) prev->pNext = next;
			else L->pHead = next;

			next->pPrev = prev;
			delete temp;

		}

		temp = next;
		next = next->pNext;
	}

}

void removeAfter(DList* L, int val) {

	if (!L) return;
	
	DNode* temp = L->pHead->pNext;
	DNode* prev = L->pHead;

	while (temp) {

		if (prev->key == val) {

			DNode* next = temp->pNext;
			prev->pNext = next;	
			if (next) next->pPrev = prev;
			else L->pTail = prev;

			delete temp;

			prev = next;
			if (next) temp = next->pNext;
			else temp = NULL;
			
		}
		else {

			prev = temp;
			temp = temp->pNext;
		}
	}
}

int countElements(DList* L) {

	if (!L) return 0;
	int count = 0;

	DNode* temp = L->pHead;
	while (temp) {

		count++;
		temp = temp->pNext;
	}

	return count;
}

DList* reverseList(DList* L) {

	if (!L) return NULL;

	DList* newL = NULL;
	DNode* temp = L->pHead;
	while (temp) {

		addHead(newL, temp->key);
		temp = temp->pNext;
	}

	return newL;

}


void printList(DList* L) {

	DNode* temp = L->pHead;
	while (temp)
	{
		cout << temp->key << " ";
		temp = temp->pNext;
	}
	cout << endl;
	temp = L->pTail;
	while (temp) {

		cout << temp->key << " ";
		temp = temp->pPrev;
	}

}

void removeDuplicate(DList*& L) {

	if (!L) return;

	DNode* temp = L->pHead;

	while (temp) {

		DNode* temp2 = temp->pNext;
		while (temp2) {

			if (temp2->key == temp->key) {

				DNode* prev = temp2->pPrev;
				DNode* next = temp2->pNext;

				prev->pNext = next;
				if (next) next->pPrev = prev;
				else L->pTail = prev;
				
				temp2 = next;
			}
			else {

				temp2 = temp2->pNext;
			}

		}
		temp = temp->pNext;

	}

}

bool removeElement(DList*& L, int val) {

	if (!L) return false;

	DNode* temp = L->pHead;
	while (temp) {

		if (temp->key == val) {

			DNode* prev = temp->pPrev;
			DNode* next = temp->pNext;

			if (prev) prev->pNext = next;
			else L->pHead = next;
			if (next) next->pPrev = prev;
			else L->pTail = prev;

			delete temp;

			temp = next;
		}
		else {

			temp = temp->pNext;
		}
	}
}


int main() {



}