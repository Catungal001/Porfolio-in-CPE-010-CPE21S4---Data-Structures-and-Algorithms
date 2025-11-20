#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H

#include <algorithm> 


template <typename T>
void bubbleSort(T arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j] < arr[j + 1]) {  
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}


template <typename T>
int findSmallestPosition(T arr[], int start, int size) {
    int pos = start;
    for (int i = start + 1; i < size; i++) {
        if (arr[i] < arr[pos]) {
            pos = i;
        }
    }
    return pos;
}


template <typename T>
void selectionSort(T arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int smallestPos = findSmallestPosition(arr, i, size);
        std::swap(arr[i], arr[smallestPos]);
    }
}


template <typename T>
void insertionSort(T arr[], int size) {
    for (int i = 1; i < size; i++) {
        T key = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}


template <typename T>
void merge(T arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    
    T leftArr[100];  
    T rightArr[100];

   
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

   
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}


template <typename T>
void mergeSort(T arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

#endif