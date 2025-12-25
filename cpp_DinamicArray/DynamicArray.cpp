#include "DynamicArray.h"

#include <iosfwd>
#include <iostream>
using namespace std;


DynamicArray::DynamicArray()
{
	size = 0;
	capacity = 2;
	data = new int[capacity];
}

DynamicArray::DynamicArray(int capacity)
{
	size = 0;
	this->capacity = capacity;
	data = new int[capacity];
}

DynamicArray::DynamicArray(const DynamicArray& other)
{
	this -> size = other.size;
	this -> capacity = other.capacity;
	this->data = new int[this->capacity];
	for (int i = 0; i < size; i++) {
		data[i] = other.data[i];
	}

}
DynamicArray& DynamicArray::operator=(const DynamicArray& other) {
	// Kendi kendine atama kontrolü (arr1 = arr1 )
	if (this == &other) {
		return *this;
	}

	// Bellek sýzýntýsý önlemi
	delete[] data;

	//Diðer nesnenin özelliklerini al 
	this->size = other.size;
	this->capacity = other.capacity;

	//Yeni bellek alaný ayýr ve verileri kopyala 
	this->data = new int[capacity];
	for (int i = 0; i < size; i++) {
		this->data[i] = other.data[i];
	}

	return *this;
}

DynamicArray DynamicArray::operator+(const DynamicArray& other) {
	//Yeni dizinin toplam boyutunu hesapla
	int newSize = this->size + other.size;

	// 2. En az yeni boyut kadar kapasiteye sahip yeni bir nesne oluþtur
	DynamicArray result(newSize);

	// Ýlk dizinin (bu nesnenin) elemanlarýný kopyala
	for (int i = 0; i < this->size; i++) {
		result.push(this->data[i]);
	}

	// Ýkinci dizinin (other) elemanlarýný kopyala
	for (int i = 0; i < other.size; i++) {
		result.push(other.data[i]);
	}

	// Birleþtirilmiþ yeni diziyi döndür
	return result;
}
bool DynamicArray::operator==(const DynamicArray& other)  {
	
	if (this->size != other.size) {
		return false;
	}

	for (int i = 0; i < size; i++) {
		if (this->data[i] != other.data[i]) {
			return false;
		}
	}
	return true;
}
bool DynamicArray::operator!=(const DynamicArray& other) {
	return !(*this == other);
}

DynamicArray::~DynamicArray()
{
	delete[] data;
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
// 10  20  30
void DynamicArray::pop()
{
	if (size==0)
	{
		cout << "Dizide silinecek eleman kalmadi!"<<endl;
	}else
	{
		size--;
		data[size] = 0;
	}

}
int& DynamicArray::operator[](int index) {
	if (index < 0 || index >= size) {
		cout << "Hata: Gecersiz indeks erisimi!" << endl; 
		// Burada basitlik için ilk elemaný dönebiliriz veya hata fýrlatabiliriz.
		return data[0];
	}
	return data[index];
}

int DynamicArray::get(int index)
{
	if (index>=size || index<0)
	{
		cout << "Gecerli bir index giriniz!" << endl;
		return -1;
	}else
	{
		return data[index];
	}
}

void DynamicArray::set(int index, int value)
{
	if (index >= size || index < 0)
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
	return capacity;
}

bool DynamicArray::isEmpty()
{
	return size == 0;
}

void DynamicArray::clear()
{
	size = 0;
}

void DynamicArray::print()
{
	cout << "[";
	for (int i = 0;i < size; i++)
	{
		cout << data[i] << (i == size - 1 ? "" : ", ");
	}
	cout << "]" << endl;
	/*for (int i=0;i<size;i++)
	{
		cout << data[i]<<" ";
	}*/
}
ostream& operator<<(std::ostream& os, const DynamicArray& other)
{
	os << "[";
	for (int i = 0; i < other.size; i++) {
		os << other.data[i];
		if (i != other.size - 1) os << ", ";
	}
	os << "]";
	return os;
}





