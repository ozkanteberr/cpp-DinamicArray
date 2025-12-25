#include <iostream>
#include "DynamicArray.h"
#include "SortedArray.h"
#include "UniqueArray.h"

using namespace std;

int main() {
    cout << "=== DynamicArray Testi ===" << endl;

    // 1. DynamicArray testi
    DynamicArray arr1;
    arr1.push(10);
    arr1.push(20);
    arr1.push(30);
    cout << "arr1: ";
    arr1.print();

    // 2. Ýndeksleme operatörü
    arr1[1] = 25;
    cout << "arr1[1] = " << arr1[1] << endl;

    // 3. Birleþtirme operatörü
    DynamicArray arr2;
    arr2.push(40);
    arr2.push(50);
    DynamicArray arr3 = arr1 + arr2;
    cout << "arr1 + arr2 = ";
    arr3.print();

    // 4. Eþitlik kontrolü
    DynamicArray arr4;
    arr4.push(10);
    arr4.push(25);
    arr4.push(30);
    cout << "arr1 == arr4: " << (arr1 == arr4 ? "Evet" : "Hayýr") << endl;

    // 5. Çýktý operatörü
    cout << "arr1 (stream): " << arr1 << endl;

    cout << "\n=== SortedArray Testi ===" << endl;

    // 6. SortedArray testi
    SortedArray sorted;
    sorted.push(50);
    sorted.push(10);
    sorted.push(30);
    sorted.push(20);
    cout << "sorted: ";
    sorted.print();

    int index = sorted.binarySearch(30);
    cout << "30 bulundu, indeks: " << index << endl;

    index = sorted.binarySearch(100);
    cout << "100 aranýyor: " << (index == -1 ? "Bulunamadý" : "Bulundu") << endl;

    cout << "\n=== UniqueArray Testi ===" << endl;

    // 7. UniqueArray testi
    UniqueArray unique;
    unique.push(10);
    unique.push(20);
    unique.push(10);  // Bu eklenmemeli
    unique.push(30);
    cout << "unique: ";
    unique.print();

    cout << "20 var mý? " << (unique.contains(20) ? "Evet" : "Hayýr") << endl;
    cout << "100 var mý? " << (unique.contains(100) ? "Evet" : "Hayýr") << endl;

    cout << "\n=== Bellek Yönetimi Testi ===" << endl;

    // 8. Copy constructor testi
    DynamicArray arr5 = arr1;
    cout << "arr5 (arr1'in kopyasý): ";
    arr5.print();
    arr5[0] = 999;
    cout << "arr5[0] deðiþtirildi: ";
    arr5.print();
    cout << "arr1 (deðiþmemeli): ";
    arr1.print();

    // 9. Pop ve clear testi
    cout << "\narr1.pop() çaðrýlýyor..." << endl;
    arr1.pop();
    arr1.print();

    cout << "arr1.clear() çaðrýlýyor..." << endl;
    arr1.clear();
    cout << "arr1 boþ mu? " << (arr1.isEmpty() ? "Evet" : "Hayýr") << endl;

    cout << "\n=== Tüm testler baþarýyla tamamlandý! ===" << endl;
    return 0;
}