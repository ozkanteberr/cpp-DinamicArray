#include "SortedArray.h"
#include <iostream>


SortedArray::SortedArray() : DynamicArray() {}

SortedArray::SortedArray(int capacity) : DynamicArray(capacity) {}

// Elemaný sýralý þekilde ekle
void SortedArray::push(int value) 
{
    DynamicArray::push(value);
    // Yeni elemaný uygun konuma taþýyana kadar sola kaydýrýr.
    int i = getSize() - 1;
    while (i > 0 && (*this)[i - 1] > (*this)[i]) {
        int tmp = (*this)[i];
        (*this)[i] = (*this)[i - 1];
        (*this)[i - 1] = tmp;
        i--;
    }
}
// Binary search ile eleman ara
int SortedArray::binarySearch(int value)  

{
    //Kaç elemanlý
    int n = getSize();
    // Erken çýkýþ: Dizi boþsa veya deðer sýnýr dýþýndaysa -1 döner.
    if (n == 0) return -1;

    if (value < (*this)[0] || value >(*this)[n - 1]) return -1;

    int left = 0, right = n - 1;
    // Aramayý yarýya indirerek ilerler.
    do {
        int mid = left + (right - left) / 2;
        int midVal = (*this)[mid];

        if (midVal == value) return mid; // Hedef bulundu.

        if (midVal < value) left = mid + 1; // Sað yarýya odaklan
        else right = mid - 1; // Sol yarýya odaklan

    } while (left <= right);

    return -1;// Bulunamadý
}

