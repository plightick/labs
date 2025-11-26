#ifndef LISTIMPL_HPP
#define LISTIMPL_HPP

#include "List.hpp"

template<typename T>
List<T>::List() : head(nullptr), tail(nullptr) {}

template<typename T>
List<T>::~List() {
    clear();
}

template<typename T>
void List<T>::pushBack(const T& value) {
    auto* newNode = new Node<T>(value);
    if (empty()) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

template<typename T>
bool List<T>::empty() const {
    return head == nullptr;
}

template<typename T>
void List<T>::clear() {
    while (head != nullptr) {
        Node<T>* tempNode = head;
        head = head->next;
        delete tempNode;
    }
    tail = nullptr;
}

template<typename T>
typename List<T>::Iterator List<T>::begin() const {
    return Iterator(head);
}

template<typename T>
typename List<T>::Iterator List<T>::end() const {
    return Iterator(nullptr);
}

#endif // LISTIMPL_HPP
