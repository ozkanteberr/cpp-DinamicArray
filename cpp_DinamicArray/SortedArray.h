#pragma once
#include "DynamicArray.h"

class SortedArray : public DynamicArray
{
public:
    SortedArray();
    SortedArray(int capacity);
    SortedArray(const SortedArray& other);
    ~SortedArray() override;

    void push(int value) override;
    int binarySearch(int value);
};
