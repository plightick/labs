#ifndef LISTALGORITHM_HPP
#define LISTALGORITHM_HPP

#include "List.hpp"

template<typename T>
class ListAlgorithm {
public:
    static typename List<T>::Iterator find(const List<T>& list, const T& value);
    static void sort(List<T>& list);
};

#endif // LISTALGORITHM_HPP
