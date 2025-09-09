#ifndef LORAS_LIST_HPP
#define LORAS_LIST_HPP

#include <iostream>

template<typename T>
class loras_list {
    T* v;

    size_t cap = 1; // capacidade do vetor
    size_t n = 0; // seria o N(quantidade de elementos na lista)

    void realloc_check();
    
    bool out_of_bounds_check(int index);
    void is_clear_check();
    
    void error_message(std::string msg);
    void decrement_size();
public:
    loras_list(int n);
    loras_list();

    size_t size() const;
    size_t capacity() const;
    
    bool empty();
    void clear();

    void push_back(T e);
    void push_front(T e);
    void push_at(int index, T e);
    void set(int index, T e);
    
    T erase_front();
    T erase_back();
    T erase_at(int index);

    T at(int index);
    T front(int index);
    T back(int index);

    // debug
    void cout();

    ~loras_list();
};

#endif