#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <node.hpp>

template <typename T>
class LinkedList {
private:

    Node<T>* head = nullptr;
    size_t size = 0;

public:
    LinkedList() = default;
    ~LinkedList();

    LinkedList(const LinkedList&) = delete;
    LinkedList& operator=(const LinkedList&) = delete;

    void pushFront(const T& value);
    void popFront();
    void print() const;
    void clear();
    std::size_t getSize() const;
};

#endif