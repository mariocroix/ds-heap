#ifndef HEAP_HPP
#define HEAP_HPP

#include <iostream>
#include <functional>
#include <stdexcept>

template <typename T, typename Compare = std::less<T>>
class Heap
{
public:
    Heap(const Compare& = Compare());
    void insert(const T&);
    T extractTop();
    T getTop() const;
    bool empty() const;
    size_t size() const;
    void print() const;
    void heapSort();

private:
    std::vector<T> _heap;
    Compare _comparator;

    void heapifyUp(size_t);
    void heapifyDown(size_t);
    void printTree(size_t, int) const;
};

#include "heap.tpp"

#endif // HEAP_HPP