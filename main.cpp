#include "heap.hpp"

int main()
{
    // Create a max heap of integers
    Heap<int, std::less<int>> maxHeap;

    // Insert elements into the heap
    maxHeap.insert(4);
    maxHeap.insert(10);
    maxHeap.insert(3);
    maxHeap.insert(5);
    maxHeap.insert(1);

    // Print the heap as a tree
    std::cout << "Heap as Tree:\n";
    maxHeap.print();

    // Sort the heap using heapSort
    maxHeap.heapSort();

    // Print the sorted elements
    std::cout << "\nSorted Array: ";
    while (!maxHeap.empty())
    {
        std::cout << maxHeap.extractTop() << " ";
    }
    std::cout << "\n";

    return 0;
}
