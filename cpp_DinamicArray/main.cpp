#include<iostream>

#include "DynamicArray.h"

using namespace std;



int main()
{
	DynamicArray arr1;
	arr1.push(10);
	arr1.push(20);
	arr1.push(30);
	arr1.set(1, 25);
	arr1.set(3,45);
	arr1.print();
}