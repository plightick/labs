#ifndef LISTITERATORIMPL_HPP
#define LISTITERATORIMPL_HPP

#include "ListIterator.hpp"

template<typename T>
ListIterator<T>::ListIterator(Node<T>* nodePtr) : currentNode(nodePtr) {}

template<typename T>
T& ListIterator<T>::operator*() const {
    return currentNode->value;
}

template<typename T>
ListIterator<T>& ListIterator<T>::operator++() {
    if (currentNode != nullptr)
        currentNode = currentNode->next;
    return *this;
}

template<typename T>
bool ListIterator<T>::operator!=(const ListIterator& other) const {
    return currentNode != other.currentNode;
}

#endif 
