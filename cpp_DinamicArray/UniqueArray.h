#pragma once
#include "DynamicArray.h"

class UniqueArray : public DynamicArray {
public:
    UniqueArray();
    UniqueArray(int capacity);
    

    void push(int value) override;

    bool contains(int value) ;
};