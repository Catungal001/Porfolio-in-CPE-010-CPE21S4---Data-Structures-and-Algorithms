// main.cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "searching.h"

const int max_size = 50;

int main() {
    int dataset[max_size];
    
    srand(time(0));

    // Generate random values
    for (int i = 0; i < max_size; i++) {
        dataset[i] = rand() % 100; // Keep numbers small for easier testing
    }

    // Show dataset
    std::cout << "Dataset: \n";
    for (int i = 0; i < max_size; i++) {
        std::cout << dataset[i] << " ";
    }
    std::cout << "\n\n";

    // Search for a number
    int item;
    std::cout << "Enter number to search: ";
    std::cin >> item;

    int result = linearSearch(dataset, max_size, item);

    if (result != -1) {
        std::cout << "Searching is successful. Item found at index " << result << ".\n";
    } else {
        std::cout << "Searching is unsuccessful. Item not found.\n";
    }

    return 0;
}