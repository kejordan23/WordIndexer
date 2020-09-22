//
// Created by Kylie Jordan on 9/18/20.
//

#ifndef INC_20F_AUTO_IDX_DSDLINKEDLIST_H
#define INC_20F_AUTO_IDX_DSDLINKEDLIST_H

#include <iostream>
#include <fstream>

using namespace std;

template <typename T>
class Node{
public:
    T data;
    Node<T>* next;
    Node<T>* prev;
    Node(T& val = T(), Node* n = nullptr, Node* d = nullptr): data(val), next(n), prev(d){};
    ~Node(){};
};

template <typename T>
class DSDLinkedList{
    private:
        Node<T>* front;
        Node<T>* end;
        int size;
    public:
        DSDLinkedList(): front(nullptr), end(nullptr), size(0){};
        ~DSDLinkedList(){clear(); delete front; delete end;};
        DSDLinkedList(const DSDLinkedList<T>&);
        DSDLinkedList<T>& operator=(const DSDLinkedList<T>&);
        bool empty();
        T& getElement(int);
        int getSize();
        void insertAtFront(T);
        void insertAt(int, T);
        void remove(int);
        void clear();
        void print();
};

template <typename T>
DSDLinkedList<T>::DSDLinkedList(const DSDLinkedList<T>& list2){
    Node<T>* curr = list2.front;
    for(int i=0; i<list2.size; i++){
        Node<T>* temp = curr;
        if(empty()){
            front = temp;
            end->prev = temp;
            size++;
        }
        else{
            end->prev->next = temp;
            end->prev = temp;
            size++;
        }
        curr = curr->next;
    }
}
template <typename T>
DSDLinkedList<T>& DSDLinkedList<T>::operator=(const DSDLinkedList<T>& list2){
    if(this == &list2)
        return *this;
    Node<T>* curr = list2.front;
    for(int i=0; i<list2.size; i++){
        Node<T>* temp = curr;
        if(empty()){
            front = temp;
            end->prev = temp;
            size++;
        }
        else{
            end->prev->next = temp;
            end->prev = temp;
            size++;
        }
        curr = curr->next;
    }
    return *this;
}
template <typename T>
bool DSDLinkedList<T>::empty(){
    return (front->next == nullptr);
}
template <typename T>
T& DSDLinkedList<T>::getElement(int){
    return data;
}
template <typename T>
int DSDLinkedList<T>::getSize(){
    return size;
}
template <typename T>
void DSDLinkedList<T>::insertAtFront(T val){
    Node<T>* temp = new Node<T>(val);
    if(empty()){
        front = temp;
        end->prev = temp;
        size++;
    }
    else {
        temp->next = front;
        front->prev = temp;
        front = temp;
        size++;
    }
}
template <typename T>
void DSDLinkedList<T>::insertAt(int loc, T val){
    if(empty()){
        insertAtfront(val);
    }
    else if (loc>0 && loc<size){
        Node<T> *temp = new Node<T>(val);
        Node<T> *curr = front;
        for (int i = 0; (i < loc) && (curr->next != nullptr); i++) {
            curr = curr->next;
        }
        temp->next = curr->next;
        curr->next->prev = temp;
        curr->next = temp;
        temp->prev = curr;
        size++;
    }
}
template <typename T>
void DSDLinkedList<T>::remove(int loc){
    Node<T> *curr = front;
    for (int i = 0; (i < loc) && (curr->next != nullptr); i++) {
        curr = curr->next;
    }
    if(curr->next == nullptr)
        end->prev = curr->prev;
    else
        curr->next->prev = curr->prev;
    if(curr->prev == nullptr)
        front->next = curr->next;
    else
        curr->prev->next = curr->next;
    delete curr;
}
template <typename T>
void DSDLinkedList<T>::clear(){
    for (int i = 0; i<size; i++) {
        Node<T> *curr = end->prev;
        end->prev = curr->prev;
        delete curr;
    }
}
template <typename T>
void DSDLinkedList<T>::print(){
    Node<T>* curr = front;
    while(curr->next != nullptr){
        std::cout<< curr->data<<std::endl;
        curr = curr->next;
    }
}

#endif //INC_20F_AUTO_IDX_DSDLINKEDLIST_H
