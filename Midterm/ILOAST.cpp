#include <iostream>
#include <cstdlib>
#include <ctime>


const int max_size = 50;

int main() {
    int dataset[max_size];

    // Seed the random number generator
    std::srand(std::time(0));

    // Generate random values and store them in the dataset
    for (int i = 0; i < max_size; ++i) {
        dataset[i] = std::rand();
    }

    // Output the generated dataset
    std::cout << "Generated dataset (" << max_size << " values):\n";
    for (int i = 0; i < max_size; ++i) {
        std::cout << dataset[i] << " ";
    }

    std::cout << std::endl;
    return 0;
}