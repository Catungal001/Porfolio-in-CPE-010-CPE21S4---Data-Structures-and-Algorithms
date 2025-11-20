#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sorting.h"
using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[100];
    srand(time(0));

    for (int i = 0; i < 100; i++) {
        arr[i] = rand() % 100;
    }

    cout << "Original Array:\n";
    printArray(arr, 20);  

    int arr1[100], arr2[100], arr3[100];
    for (int i = 0; i < 100; i++) {
        arr1[i] = arr[i];
        arr2[i] = arr[i];
        arr3[i] = arr[i];
    }

    shellSort(arr1, 100);
    cout << "\nSorted using Shell Sort:\n";
    printArray(arr1, 20);

    mergeSort(arr2, 0, 99);
    cout << "\nSorted using Merge Sort:\n";
    printArray(arr2, 20);

    quickSort(arr3, 0, 99);
    cout << "\nSorted using Quick Sort:\n";
    printArray(arr3, 20);

    return 0;
}
