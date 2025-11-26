#include "../headers/ListAlgorithm.hpp"
#include <utility>
#include <string>

using namespace std;
template<typename T>
typename List<T>::Iterator ListAlgorithm<T>::find(const List<T>& list, const T& value) {
    for (auto it = list.begin(); it != list.end(); ++it) {
        if (*it == value)
            return it;
    }
    return list.end();
}

template<typename T>
void ListAlgorithm<T>::sort(List<T>& list) {
    if (list.empty()) return;

    bool swapped;
    do {
        swapped = false;
        for (auto it = list.begin(); it != list.end(); ++it) {
            auto next = it;
            ++next;
            if (next != list.end() && *it > *next) {
                std::swap(*it, *next);
                swapped = true;
            }
        }
    } while (swapped);
}

template class ListAlgorithm<int>;
template class ListAlgorithm<double>;
template class ListAlgorithm<std::string>;
