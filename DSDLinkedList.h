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
        DSDLinkedList(){
            front = nullptr;
            end = nullptr;
            size = 0;
        };
        ~DSDLinkedList(){clear();};
        DSDLinkedList(const DSDLinkedList<T>&);
        DSDLinkedList<T>& operator=(const DSDLinkedList<T>&);
        bool empty();
        T& getElement(int);
        int getSize();
        void insertAtFront(T);
        void insertAtEnd(T);
        void insertAt(int, T);
        void remove(int);
        void clear();
        void print();
};

template <typename T>
DSDLinkedList<T>::DSDLinkedList(const DSDLinkedList<T>& list2){
    Node<T>* curr2 = list2.front;
    for(int i=0; i<list2.size; i++){
        Node<T>* temp = curr2;
        if(empty()){
            front = temp;
            end = temp;
            size++;
        }
        else{
            Node<T>* curr = end;
            curr->next = temp;
            temp->prev = curr;
            end = temp;
            size++;
        }
        curr2 = curr2->next;
    }
}
template <typename T>
DSDLinkedList<T>& DSDLinkedList<T>::operator=(const DSDLinkedList<T>& list2){
    if(this == &list2)
        return *this;
    Node<T>* curr2 = list2.front;
    for(int i=0; i<list2.size; i++){
        Node<T>* temp = curr2;
        if(empty()){
            front = temp;
            end = temp;
            size++;
        }
        else{
            Node<T>* curr = end;
            curr->next = temp;
            temp->prev = curr;
            end = temp;
            size++;
        }
        curr2 = curr2->next;
    }
    return *this;
}
template <typename T>
bool DSDLinkedList<T>::empty(){
    if (size ==0)
        return true;
    else
        return false;
}
template <typename T>
T& DSDLinkedList<T>::getElement(int loc){
    Node<T> *curr = front;
    for (int i = 0; (i < loc) && (curr->next != nullptr); i++) {
        curr = curr->next;
    }
    return curr->data;
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
        end = temp;
        size++;
    }
    else {
        Node<T>* curr = front;
        curr->prev = temp;
        temp->next = curr;
        end = curr;
        front = temp;
        size++;
    }
}
template <typename T>
void DSDLinkedList<T>::insertAtEnd(T elem){
    Node<T>* temp = new Node<T>(elem);
    if(empty())
        insertAtFront(elem);
    else{
        Node<T>* curr = end;
        curr->next = temp;
        temp->prev = curr;
        end = temp;
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
    /*if(front != nullptr && front->next != nullptr) {
        Node<T> *curr = front;
        Node<T> *rem = 0;
        for (int i = 0; i < size; i++) {
            rem = curr;
            curr = curr->next;
            delete rem;
        }
    }*/
    if (front != nullptr){
        Node<T> *curr = front;
        Node<T> *rem;
        while (curr != nullptr){
            rem = curr->next;
            delete curr;
            curr = rem;
        }
    }
    if (front == nullptr){
        delete front;
        delete end;
    }
    size = 0;
}
template <typename T>
void DSDLinkedList<T>::print(){
    Node<T>* curr = front;
    for(int i =0; i<size; i++){
        std::cout<< curr->data<<std::endl;
        curr = curr->next;
    }
}

#endif //INC_20F_AUTO_IDX_DSDLINKEDLIST_H
