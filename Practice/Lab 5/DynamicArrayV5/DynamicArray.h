#ifndef _DYNAMICARRAY_H
#define _DYNAMICARRAY_H

class DynamicArray {
private:
    const int INITIAL_SIZE = 128;

private:
    int* _a;
    int _len;
    int _max;

public:
    DynamicArray();

    DynamicArray(int sz);

    DynamicArray(const DynamicArray& arr);

    ~DynamicArray();

    DynamicArray& operator=(const DynamicArray& arr);

    void pushBack(int value);
    
    int getAt(int index);

    std::string toString();
};

#endif