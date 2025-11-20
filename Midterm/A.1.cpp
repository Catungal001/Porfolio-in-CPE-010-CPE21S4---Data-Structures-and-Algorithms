#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sorting.h"  

int main() {
    const int SIZE = 100;
    int arr[SIZE];

    
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    
    for (int i = 0; i < SIZE; i++) {
        arr[i] = std::rand() % 100 + 1;
    }

    std::cout << "Array before Bubble Sort:" << std::endl;
    printArray(arr, SIZE);

    
    bubbleSort(arr, SIZE);

    std::cout << "Array after Bubble Sort (ascending order):" << std::endl;
    printArray(arr, SIZE);

    return 0;
}
