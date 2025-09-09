#include "loras_list.h"

template<typename T>
loras_list<T>::loras_list(int n) {
    this->v = new T[n];
    this->cap = n;
}

template<typename T>
loras_list<T>::loras_list() {
    this->v = new T[1];
}

template<typename T>
void loras_list<T>::realloc_check() {
    if (this->n < this->cap)
        return;

    this->cap = this->cap * 1.1f + 1;

    T* tmp = new T[this->cap];

    for (size_t i = 0; i < this->n; i++) {
        tmp[i] = this->v[i];
    }

    delete[] this->v;
    this->v = tmp;
}

template<typename T>
void loras_list<T>::push_front(T e) {
    this->realloc_check();
    
    for (int i = n-1; i >= 0; i--)
        this->v[i+1] = this->v[i];

    this->v[0] = e;
    this->n++;
}

template<typename T>
void loras_list<T>::push_back(T e) {
    this->realloc_check();
    this->v[this->n++] = e;
}

template<typename T>
void loras_list<T>::push_at(int index, T e) {
    this->out_of_bounds_check(index);
    this->realloc_check();
    
    for (int i = this->n-1; i >= index; i--)
    this->v[i+1] = this->v[i];
    
    this->v[index] = e;
    this->n++;
}

template<typename T>
T loras_list<T>::erase_front() {
    this->is_clear_check();

    T tmp = this->v[0];
    
    for (int i = 1; i < this->n; i++) {
        this->v[i-1] = this->v[i];
    }

    this->decrement_size();
    return tmp;
}

template<typename T>
T loras_list<T>::erase_back() {
    this->is_clear_check();

    T tmp = this->v[n-1];
    this->decrement_size();

    return tmp;
}

template<typename T>
T loras_list<T>::erase_at(int index) {
    bool ok = this->out_of_bounds_check(index);
    if (!ok) return this->v[this->n];

    T tmp = this->v[index];

    for (int i = index; i < this->n-1; i++) {
        this->v[i] = this->v[i+1];
    }
    
    this->decrement_size();
    return tmp;
}

template<typename T>
void loras_list<T>::error_message(std::string msg) {
    std::cout << msg << '\n';
}

template<typename T>
void loras_list<T>::decrement_size() {
    this->n = this->n - 1 < 0 ? 0 : this->n-1;
}

template<typename T>
void loras_list<T>::is_clear_check() {
    if (this->empty())
        this->error_message("a lista esta vazia");
}

template<typename T>
bool loras_list<T>::out_of_bounds_check(int index) {
    if (index < 0 || index >= this->n) {
        error_message("posicao invalida");
        return true;
    }
    return false;
}

template<typename T>
void loras_list<T>::set(int index, T e) {
    this->out_of_bounds_check(index);
    this->v[index] = e;
}

template<typename T>
T loras_list<T>::at(int index) {
    this->out_of_bounds_check(index);
    return this->v[index];
}

template<typename T>
T loras_list<T>::front(int index) {
    this->is_clear_check();
    return this->v[0];
}

template<typename T>
T loras_list<T>::back(int index) {
    this->is_clear_check();
    return this->v[this->n-1];
}

template<typename T>
void loras_list<T>::clear() {
    this->n = 0;
    this->cap = 1;
    delete[] this->v;
    this->v = new T[1];
}

template<typename T>
bool loras_list<T>::empty() {
    return !this->n;
}

template<typename T>
size_t loras_list<T>::size() const {
    return this->n;
}

template<typename T>
size_t loras_list<T>::capacity() const {
    return this->cap;   
}

template<typename T>
loras_list<T>::~loras_list() {
    delete[] this->v;
}

template<typename T>
void loras_list<T>::cout() {
    for (int i = 0; i < this->n; i++) {
        std::cout << this->v[i] << ' ';
    } std::cout << '\n';
}