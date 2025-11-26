#ifndef LIST_HPP
#define LIST_HPP

#include "Node.hpp"
#include "ListIterator.hpp"

template<typename T>
class List {
public:
    List();
    ~List();

    void pushBack(const T& value);
    bool empty() const;

    using Iterator = ListIterator<T>;

    Iterator begin() const;
    Iterator end() const;

private:
    Node<T>* head;
    Node<T>* tail;

    void clear();
};

#include "ListImpl.hpp"

#endif