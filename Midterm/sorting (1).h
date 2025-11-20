#ifndef SORTING_H
#define SORTING_H

#include <iostream>
#include <algorithm> 


template <typename T>
void bubbleSort(T arr[], size_t arrSize) {
    for (size_t i = 0; i < arrSize - 1; i++) {
        for (size_t j = 0; j < arrSize - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}


template <typename T>
void printArray(T arr[], size_t arrSize) {
    for (size_t i = 0; i < arrSize; i++) {
        std::cout << arr[i] << " ";
        if ((i + 1) % 10 == 0) std::cout << std::endl;
    }
    std::cout << std::endl;
}

#endif
