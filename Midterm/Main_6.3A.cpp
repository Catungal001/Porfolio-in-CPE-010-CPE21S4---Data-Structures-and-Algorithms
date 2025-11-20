#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "searching_6.3A.h"

const int max_size = 50;

int main() {
    int dataset[max_size];
    srand(time(0));

    for (int i = 0; i < max_size; i++) {
        dataset[i] = rand() % 100;
    }

    std::sort(dataset, dataset + max_size);

    std::cout << "Sorted dataset: \n";
    for (int i = 0; i < max_size; i++) {
        std::cout << dataset[i] << " ";
        if ((i + 1) % 10 == 0) std::cout << "\n";
    }
    std::cout << "\n";

    int item;
    std::cout << "Enter number to search: ";
    std::cin >> item;

    int result = binarySearch(dataset, max_size, item);

    if (result != -1) {
        std::cout << "Searching is successful. Item found at index " << result << ".\n";
    } else {
        std::cout << "Searching is unsuccessful. Item not found.\n";
    }

    return 0;
}