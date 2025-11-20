#include <iostream>
using namespace std;

// Recursive binary search function
int recursiveBinarySearch(int arr[], int left, int right, int key) {
    if (left > right) {
        // Base case: key not found
        return -1;
    }

    int mid = (left + right) / 2;
    cout << "Check index " << mid << " with value " << arr[mid] << endl;

    if (arr[mid] == key) {
        return mid;  // Found the key
    }
    else if (arr[mid] < key) {
        cout << "Value is smaller than " << key << ", look right side" << endl;
        return recursiveBinarySearch(arr, mid + 1, right, key);  // Search right half
    }
    else {
        cout << "Value is bigger than " << key << ", look left side" << endl;
        return recursiveBinarySearch(arr, left, mid - 1, key);   // Search left half
    }
}

int main() {
    int sortedList[] = {3, 5, 6, 8, 11, 12, 14, 15, 17, 18};
    int size = 10;
    int key = 8;

    cout << "Start recursive binary search for " << key << " in the list." << endl;

    int result = recursiveBinarySearch(sortedList, 0, size - 1, key);

    if (result != -1) {
        cout << "Found " << key << " at index " << result << "!" << endl;
    }
    else {
        cout << key << " is not in the list." << endl;
    }

    return 0;
}