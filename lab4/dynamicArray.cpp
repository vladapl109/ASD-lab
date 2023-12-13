#include "dynamicArray.h"
 
    DynamicArray::DynamicArray(int capacity){ //объявление конструктора для класса DynamicArray
        this->values = new int[capacity]; //Выделение динамической памяти для массива values размером capacity
        this->capacity = capacity; //Значение переменной capacity, переданное в конструктор, присваивается переменной capacity класса
    }

    void DynamicArray::coutValues(){ //Объявление метода coutValues класса DynamicArray. void указывает на то, что метод не возвращает значения
        for(int i = 0; i<this->length; i++){ //проходит по всем элементам массива values
            std::cout<<this->values[i]<<" ";
        }
        std::cout<<std::endl<<this->capacity<<std::endl;
    }
