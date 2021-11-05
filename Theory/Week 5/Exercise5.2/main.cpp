#include <iostream>
using namespace std;

struct NODE {
	int data;
	NODE* pNext;
};
struct LIST {
	NODE* pHead;
	NODE* pTail;
};

void init(LIST& l) {
	l.pHead = l.pTail = NULL;
}
NODE* getNode(int x) {
	NODE* p = new NODE;
	if (p == NULL) {
		cout << "Het bo nho roi ban eiii";
		return NULL;
	}
	else {
		p->data = x;
		p->pNext = NULL;
	}
	return p;
}
void addTail(LIST& l, NODE* p) {
	if (l.pHead == NULL) { //=> List dang trong rong
		l.pHead = l.pTail = p;
	}
	else {
		l.pTail->pNext = p;
		l.pTail = p;
	}
}
void inputList(LIST& l) {
	init(l);
	int x;
	do {
		do {
			cout << "Nhap du lieu = ";
			cin >> x;
		} while (x <= 0 && x != -1);
		if (x == -1) break;
		NODE* p = getNode(x);
		addTail(l, p);

	} while (1);
}
void outputList(LIST& l) {
	for (NODE* p = l.pHead; p != NULL; p = p->pNext) {
		cout << p->data << " ";
	}
	cout << endl;
}
int len(LIST l) {
	int k = 0;
	for (NODE* p = l.pHead; p != NULL; p = p->pNext) {
		k++;
	}
	return k;
}
void mergeTwoLists(LIST lA, LIST lB, LIST& lC) {
	int a = len(lA);
	int b = len(lB);
	NODE* p = lA.pHead;
	while (p != NULL) {
		addTail(lC, p);
		p = p->pNext;
	}
	p = lB.pHead;
	while (p != NULL) {
		addTail(lC, p);
		p = p->pNext;
	}
}
void dividesCintoAchanBle(LIST lC, LIST& lA, LIST& lB) {
	NODE* p = lC.pHead;
	while (p != NULL) {
		if ((p->data) % 2 == 0) addTail(lA, p);
		else addTail(lB, p);

		p = p->pNext;

	}

	if (lA.pHead) addTail(lA, p);
	if (lB.pHead) addTail(lB, p);
}
void giaiPhong(LIST& l) {
	NODE* p;
	while (l.pHead != NULL) {
		p = l.pHead;
		l.pHead = l.pHead->pNext;
		delete p;
	}
}

int main() {
	cout << "*****yeu cau 1*****\n";

	cout << "\n*****yeu cau 2*****\n";
	LIST lA, lB;
	cout << "\n===Nhap danh sach Data A gom cac So Nguyen Duong===\n";
	inputList(lA);
	cout << "\n===Nhap danh sach Data B gom cac So Nguyen Duong===\n";
	inputList(lB);
	cout << "\n===Danh sach Data A gom cac So Nguyen Duong vua nhap===\n";
	outputList(lA);
	cout << "===Danh sach Data B gom cac So Nguyen Duong vua nhap===\n";
	outputList(lB);


	cout << "\n*****yeu cau 3*****\n";
	LIST lC;
	init(lC);
	mergeTwoLists(lA, lB, lC);
	cout << "Danh sach C duoc merge la: \n";
	outputList(lC);
	init(lA); //DS chan
	init(lB); //DS le
	dividesCintoAchanBle(lC, lA, lB);
	//	giaiPhong(lC);
		//Xuat danh sach
	cout << "===Danh sach Data A gom cac So CHAN Nguyen Duong===\n";
	outputList(lA);
	cout << "===Danh sach Data B gom cac So  LE  Nguyen Duong===\n";
	outputList(lB);

	//	giaiPhong(lA);
	//	giaiPhong(lB);
	return 0;
}
