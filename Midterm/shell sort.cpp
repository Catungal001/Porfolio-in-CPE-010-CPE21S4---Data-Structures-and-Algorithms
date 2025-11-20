#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sorting.h"   

using namespace std;

int main() {
    const int SIZE = 100;
    int arr[SIZE];

    
    srand(time(0));
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100; 
    }

    cout << "Original Array:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << " ";
    }
    cout << endl << endl;

    
    shellSort(arr, SIZE);

    cout << "Sorted using Shell Sort:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
