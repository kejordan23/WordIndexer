// Project 2: Auto Indexer
// Author: Kylie Jordan
//
// DSVector.h
//
// This header file declares and defines the DSVector class constructors and functions.

#ifndef INC_20F_AUTO_IDX_DSVECTOR_H
#define INC_20F_AUTO_IDX_DSVECTOR_H

#include <iostream>
#include <fstream>
#include "DSString.h"

//templated DSVector class has a templated data pointer, a size, and a capacity
template <typename T>
class DSVector{
    private:
        T* data;
        int size;
        int capacity;

    public:
        DSVector();
        DSVector(int);
        DSVector(const DSVector<T>&);
        ~DSVector();

        DSVector<T>& operator= (const DSVector&);
        T& operator[](int);

        int getCapacity();
        int getSize();
        bool empty();
        T& getElement(int);
        void insert(int, T);
        void push_back(T&);
        void remove(int);
        void print();

};
//constructor, copy constructors, and destructor
template <typename T>
DSVector<T>::DSVector(){
    data = new T[50];
    size = 0;
    capacity = 50;
}
template <typename T>
DSVector<T>::DSVector(int space){
    data = new T[space];
    size = 0;
    capacity = space;
}
template <typename T>
DSVector<T>::DSVector(const DSVector<T>& vec){
    data = new T[vec.size];
    this->size = vec.size;
    for (int i=0; i<vec.size; i++){
        data[i] = vec.data[i];
    }
}
template <typename T>
DSVector<T>::~DSVector(){
    delete [] data;
}

//overloaded assignment and subscript operators
template <typename T>
DSVector<T>& DSVector<T>::operator= (const DSVector& vec){
    T* temp = new T[vec.size];
    for (int i=0; i<vec.size; i++)
        temp[i] = vec.data[i];
    delete [] data;
    this->data = temp;
    this->size = vec.size;
    return *this;
}
template <typename T>
T& DSVector<T>::operator[](int loc){
    if(loc < capacity && loc >= 0)
        return data[loc];
    else {
        return data[size - 1];
        std::cout<< "location is too large"<<std::endl;
    }
}

template <typename T>
int DSVector<T>::getCapacity(){
    return capacity;
}
template <typename T>
int DSVector<T>::getSize(){
    return size;
}
template <typename T>
bool DSVector<T>::empty(){
    if(size == 0)
        return true;
    else
        return false;
}
template <typename T>
T& DSVector<T>::getElement(int loc){
    if (loc < size){
        return data[loc];
    }
    else
        return data[size-1];
}
template <typename T>
void DSVector<T>::insert(int loc, T elem){          //inserts an element at a given index
    if (loc == capacity){
        push_back(elem);
    }
    else if (loc < capacity && loc > 0){
        data[loc] = elem;
        size++;
    }
    else if (loc > capacity){
        std::cout<< "location is too large"<<std::endl;
    }
}
template <typename T>
void DSVector<T>::push_back(T& elem){           //inserts the element at the end of the vector
    if (size == capacity){                      //checks to see if the vector has reached capacity
        T* temp = new T[capacity+1];
        for (int i=0; i<capacity; i++){
            temp[i] = data[i];
        }

        delete [] data;                         //frees memory to create more space in the vector
        capacity ++;
        data = temp;
    }
    data[size] = elem;
    size++;
}
template <typename T>
void DSVector<T>::remove(int loc){              //removes an element from a given index
    if (loc == (size-1))
        size--;
    else if (loc >=0 && loc<size){
        for(int i=loc; i<(size-1); i++)
            data[i] = data[i+1];
        size--;
    }
}
template <typename T>
void DSVector<T>::print(){
    for (int i=0; i<size; i++)
        std::cout<<data[i]<<std::endl;
}

#endif //INC_20F_AUTO_IDX_DSVECTOR_H
