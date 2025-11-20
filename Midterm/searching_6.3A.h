#ifndef SEARCHING_H
#define SEARCHING_H

int binarySearch(int arr[], int size, int item) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == item) {
            return mid;
        }

        if (arr[mid] < item) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1; // Item not found
}

#endif