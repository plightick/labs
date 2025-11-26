#ifndef LISTITERATOR_HPP
#define LISTITERATOR_HPP

#include "Node.hpp"

template<typename T>
class ListIterator {
public:
    explicit ListIterator(Node<T>* nodePtr);

    T& operator*() const;
    ListIterator& operator++();
    bool operator!=(const ListIterator& other) const;

private:
    Node<T>* currentNode;
};

#include "ListIteratorImpl.hpp"

#endif // LISTITERATOR_HPP
