#pragma once
//#include <iosfwd>
#include <ostream>
#include <ostream>

class DynamicArray
{
private:
	int* data;
	int  size;
	int  capacity;

public:
	DynamicArray();
	DynamicArray(int capacity);
	DynamicArray(const DynamicArray& other);
	virtual ~DynamicArray();


	virtual void push(int value);
	void pop();
	int get(int index);
	void set(int index, int value);
	int getSize();
	int getCapacity();
	bool isEmpty();
	void clear();
	void print();

	int& operator[](int index);
	DynamicArray operator+(const DynamicArray& other);
	DynamicArray& operator=(const DynamicArray& other);
	bool operator==(const DynamicArray& other);
	bool operator!=(const DynamicArray& other);
	friend std::ostream& operator<<(std::ostream& os, const DynamicArray& other);
};
