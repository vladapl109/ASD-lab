#include <iostream>

struct DynamicArray{
    int* values ;
    int length = 0;
    int capacity = 0;
    
    DynamicArray(int);

    void coutValues();

};
