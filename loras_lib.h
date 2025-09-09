#ifndef LINKED_LORAS_LIST
#define LINKED_LORAS_LIST

#include <iostream>

namespace loras {

    template<typename T>
    class node {
    public:
        T content;
        node<T>* next;
        node<T>* prev;

        node(){}
        node(T content) :
            content(content),
            prev(nullptr),
            next(nullptr)
        {}
    };

    template<typename T>
    class linked_list {
        size_t size;
        node<T>* front;
        node<T>* back;
    public:
        linked_list();
        linked_list(int n);
        linked_list(int n, T val);
        ~linked_list();

        void push_back(T val);
        void push_front(T val);

        // debug
        void cout();
    };

};

#endif