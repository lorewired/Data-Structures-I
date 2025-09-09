#include "loras_lib.h"

using namespace loras;

template<typename T>
linked_list<T>::linked_list() {
    this->back = this->front = new node<T>;
    this->size = 0;
}

template<typename T>
linked_list<T>::linked_list(int n) {
    this->front = new node<T>;
    node<T>* tmp = this->front;

    for (int i = 1; i < n; i++) {
        tmp->next = new node<T>;
        tmp->next->prev = tmp;
        this->back = tmp->next;
    }

    this->size = n;
}

template<typename T>
linked_list<T>::linked_list(int n, T val) {
    this->back = this->front = new node<T>(val);
    node<T>* tmp = this->front;

    for (int i = 1; i < n; i++) {
        tmp->next = new node<T>(val);
        
        tmp->next->prev = tmp;

        this->back = tmp->next;
        tmp = tmp->next;
    }
    
    this->size = n;
}

template<typename T>
linked_list<T>::~linked_list() {
    node<T>* cur = this->front->next;
    for (int i = 0; i < this->size; i++, cur = cur->next) {
        delete cur->prev;
    }
    delete cur;
}

template<typename T>
void linked_list<T>::push_back(T val) {
    this->back->next = new node<T>(val);
    this->back = this->back->next;
    this->size++;
}

template<typename T>
void linked_list<T>::push_front(T val) {
    node<T>* tmp = new node<T>(val);

    tmp->next = this->front;
    tmp->next->prev = tmp;
    this->front = tmp;
    
    this->size++;
}

template<typename T>
void linked_list<T>::cout() {
    node<T>* cur = this->front;
    for (int i = 0; i < this->size; i++) {
        std::cout << cur->content << ' ';
        cur = cur->next;
    } std::cout << '\n';
}