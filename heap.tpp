#ifndef HEAP_TPP
#define HEAP_TPP

#include "heap.hpp"

template <typename T, typename Compare>
Heap<T, Compare>::Heap(const Compare& comparator)
    : _comparator {comparator} {}

template <typename T, typename Compare>
void Heap<T, Compare>::insert(const T& value)
{
    _heap.push_back(value);
    heapifyUp(_heap.size() - 1);
}

template <typename T, typename Compare>
T Heap<T, Compare>::extractTop()
{
    if (_heap.empty())
    {
        throw std::out_of_range("The heap is empty.");
    }

    T top = _heap[0];
    _heap[0] = _heap.back();
    _heap.pop_back();
    heapifyDown(0);

    return top;
}

template <typename T, typename Compare>
T Heap<T, Compare>::getTop() const
{
    if (_heap.empty())
    {
        throw std::out_of_range("The list is empty.");
    }

    return _heap[0];
}

template <typename T, typename Compare>
bool Heap<T, Compare>::empty() const
{
    return _heap.empty();
}

template <typename T, typename Compare>
size_t Heap<T, Compare>::size() const
{
    return _heap.size();
}

template <typename T, typename Compare>
void Heap<T, Compare>::print() const
{
    printTree(0, 0);
}

template <typename T, typename Compare>
void Heap<T, Compare>::printTree(size_t index, int depth) const
{
    if (index < _heap.size())
    {
        printTree(2 * index + 2, depth + 1); // Print right subtree
        for (int i = 0; i < depth; i++)
            std::cout << "    "; // Adjust spacing based on depth
        std::cout << _heap[index] << "\n"; // Print current node
        printTree(2 * index + 1, depth + 1); // Print left subtree
    }
}


template <typename T, typename Compare>
void Heap<T, Compare>::heapifyUp(size_t index)
{
    size_t parent = (index - 1) / 2;
    while (index > 0 && _comparator(_heap[index], _heap[parent]))
    {
        std::swap(_heap[index], _heap[parent]);
        index = parent;
        parent = (index - 1) / 2;
    }
}

template <typename T, typename Compare>
void Heap<T, Compare>::heapifyDown(size_t index)
{
    size_t leftChild = 2 * index + 1;
    size_t rightChild = 2 * index + 2;
    size_t smallest = index;

    if (leftChild < _heap.size() && _comparator(_heap[leftChild], _heap[smallest]))
    {
        smallest = leftChild;
    }

    if (rightChild < _heap.size() && _comparator(_heap[rightChild], _heap[smallest]))
    {
        smallest = rightChild;
    }

    if (smallest != index)
    {
        std::swap(_heap[index], _heap[smallest]);
        heapifyDown(smallest);
    }
}

template <typename T, typename Compare>
void Heap<T, Compare>::heapSort()
{
    for (int i = static_cast<int>(_heap.size()) / 2 - 1; i >= 0; --i)
    {
        heapifyDown(static_cast<size_t>(i));
    }

    for (int i = static_cast<int>(_heap.size()) - 1; i > 0; --i)
    {
        std::swap(_heap[0], _heap[static_cast<size_t>(i)]);

        heapifyDown(0);
    }
}


#endif // HEAP_TPP

