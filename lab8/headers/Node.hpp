#ifndef NODE_HPP
#define NODE_HPP

template<typename T>
struct Node {
    T value;
    Node<T>* next;

    explicit Node(const T& v) : value(v), next(nullptr) {}
};

#endif
