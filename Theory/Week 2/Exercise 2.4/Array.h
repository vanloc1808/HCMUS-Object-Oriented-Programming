#pragma once

class Array {
private:
	int* arr;

	int size;
public:
	void init();

	bool input();

	void output();

	int getSize();

	int getElement(int index);

	void assignElement(int index, int newValue);

	int findElement(int toFind);

	void sortArray(bool (*cmp)(int, int));

	void freeArray();
};
