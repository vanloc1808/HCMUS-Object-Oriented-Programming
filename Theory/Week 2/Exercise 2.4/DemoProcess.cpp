#include <iostream>
#include "Array.h"
#include "DemoProcess.h"

using namespace std;

void showMenu() {
	cout << "Here is the menu of the program.\n";
	cout << "1. Get the size of an array.\n";
	cout << "2. Get the element at a random postion.\n";
	cout << "3. Assign a new value to an element at a random position.\n";
	cout << "4. Find a number in array.\n";
	cout << "5. Sort in ascending order.\n";
	cout << "6. Sort in descending order.\n";
}

void getSizeProcess() {
	Array arr;
	
	arr.init();
	arr.input();

	int size = arr.getSize();

	cout << "The array size is: " << size << "\n";

	arr.freeArray();
}

void getElementProcess() {
	Array arr;

	arr.init();
	arr.input();

	int size = arr.getSize();
	int idx = -1;
	
	cout << "Enter the position: ";
	cin >> idx;

	//Check if the index is valid.
	if (idx < 0 || idx >= size) {
		cout << "Invalid position.\n";
	}
	else {
		int res = arr.getElement(idx);

		cout << "The element at postion " << idx << " is " << res << '\n';
	}
	
	arr.freeArray();
}

void newValueProcess() {
	Array arr;

	arr.init();
	arr.input();

	int size = arr.getSize();
	int idx = -1;

	cout << "Enter the position: ";
	cin >> idx;

	//Check if the index is valid.
	if (idx < 0 || idx >= size) {
		cout << "Invalid position.\n";
	}
	else {
		int newValue = 0;
		
		cout << "Enter new value: ";
		cin >> newValue;

		arr.assignElement(idx, newValue);

		cout << "After changing:\n";
		arr.output();
		cout << "\n";
	}

	arr.freeArray();
}

void findProcess() {
	Array arr;

	arr.init();
	arr.input();

	int toFind = 0;
	cout << "Enter the number to find: ";
	cin >> toFind;

	int res = arr.findElement(toFind);
	if (res == -1) {
		cout << "The number " << toFind << " cannot be found.\n";
	}
	else {
		cout << "The number " << toFind << " is found at position " << res << "\n";
	}

	arr.freeArray();
}

//The following two functions is used as parameter while sorting the array.
bool isGreater(int x, int y) {
	return x > y;
}

bool isLess(int x, int y) {
	return x < y;
}

void sortAsc() {
	Array arr;

	arr.init();
	arr.input();

	arr.sortArray(isLess);

	cout << "After sorting: \n";
	arr.output();
	cout << "\n";

	arr.freeArray();
}

void sortDes() {
	Array arr;

	arr.init();
	arr.input();

	arr.sortArray(isGreater);

	cout << "After sorting: \n";
	arr.output();
	cout << "\n";

	arr.freeArray();
}