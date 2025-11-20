#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm> 
#include "sorting_algorithms.h"

const int SIZE = 100;

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
        if ((i + 1) % 20 == 0)
            std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    std::srand(std::time(0));

    int originalArray[SIZE];

    
    for (int i = 0; i < SIZE; i++) {
        originalArray[i] = std::rand() % 1000;
    }

    std::cout << "Table 7-1: Original Unsorted Array:\n";
    printArray(originalArray, SIZE);

    
    int bubbleArray[SIZE];
    std::copy(originalArray, originalArray + SIZE, bubbleArray);
    bubbleSort(bubbleArray, SIZE);
    std::cout << "Array after Bubble Sort (Descending):\n";
    printArray(bubbleArray, SIZE);

    
    int selectionArray[SIZE];
    std::copy(originalArray, originalArray + SIZE, selectionArray);
    selectionSort(selectionArray, SIZE);
    std::cout << "Array after Selection Sort (Ascending):\n";
    printArray(selectionArray, SIZE);

    
    int insertionArray[SIZE];
    std::copy(originalArray, originalArray + SIZE, insertionArray);
    insertionSort(insertionArray, SIZE);
    std::cout << "Array after Insertion Sort (Ascending):\n";
    printArray(insertionArray, SIZE);

    
    int mergeArray[SIZE];
    std::copy(originalArray, originalArray + SIZE, mergeArray);
    mergeSort(mergeArray, 0, SIZE - 1);
    std::cout << "Array after Merge Sort (Ascending):\n";
    printArray(mergeArray, SIZE);

    return 0;
}