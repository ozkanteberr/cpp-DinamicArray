#include "UniqueArray.h"

// Constructor'lar
UniqueArray::UniqueArray() : DynamicArray() {}

UniqueArray::UniqueArray(int capacity) : DynamicArray(capacity) {}

// Dizide belirtiler deðer var mý?
bool UniqueArray::contains(int value)
{
    // Tüm elemanlarý gezerek eþleþme arar.
    for (int i = 0; i < getSize(); i++) {
        if ((*this)[i] == value)
            return true; //bulursa true döner
    }
    return false; //yoksa false
}

// Eleman dizide yoksa ekleme iþlemini gerçekleþtirir.
void UniqueArray::push(int value) {
    // Eleman zaten varsa ekleme

    if (contains(value)) {
        return; // Fonksiyondan çýk, ekleme yapma
    }

    // Benzersiz elemaný temel sýnýfýn push metoduyla sona ekler. 
    DynamicArray::push(value);
}
