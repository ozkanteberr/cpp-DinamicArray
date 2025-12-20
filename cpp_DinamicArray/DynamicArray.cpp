#include "DynamicArray.h"

#include <iosfwd>
#include <iostream>
using namespace std;


DynamicArray::DynamicArray()
{
	capacity = 2;
	data = new int[capacity];
}

DynamicArray::DynamicArray(int capacity)
{
	this->capacity = capacity;
	data = new int[capacity];
}

DynamicArray::DynamicArray(const DynamicArray& deepCopy)
{

}

DynamicArray::~DynamicArray()
{
	delete data;
}

void DynamicArray::push(int value){
	if (size>=capacity)
	{
		capacity = capacity * 2;
		int* newData = new int[capacity];

		for (int i=0;i<size;i++)
		{
			newData[i] = data[i];
		}
		delete[] data;
		data = newData;
	}
	data[size] = value;
	size++;
}

void DynamicArray::pop()
{
	if (size==0)
	{
		cout << "Dizide silinecek eleman kalmadi!"<<endl;
	}else
	{
		data[size] = 0;
		size--;
	}

}

int DynamicArray::get(int index)
{
	if (index>size || index<0)
	{
		cout << "Gecerli bir index giriniz!" << endl;
		return NULL;
	}else
	{
		return data[index];
	}
}

void DynamicArray::set(int index, int value)
{
	if (index > size || index < 0)
	{
		cout << "Bu index numarasi gecerli degil!" << endl;
	}else
	{
		data[index] = value;
	}
}

int DynamicArray::getSize()
{
	return size;
}

int DynamicArray::getCapacity()
{
	return 0;
}

bool DynamicArray::isEmpty()
{
	return true;
}

void DynamicArray::clear()
{
	
}

void DynamicArray::print()
{
	for (int i=0;i<size;i++)
	{
		cout << data[i]<<" ";
	}
}

//ostream& DynamicArray::operator<<(ostream& os, const DynamicArray& other)
//{
//	return os;
//}





