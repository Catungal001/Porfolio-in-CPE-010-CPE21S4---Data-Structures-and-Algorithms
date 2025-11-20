#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int key) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        cout << "Check index " << mid << " with value " << arr[mid] << endl;

        if (arr[mid] == key) {
            return mid;  
        }
        else if (arr[mid] < key) {
            cout << "Value is smaller than " << key << ", look right side" << endl;
            left = mid + 1;
        }
        else {
            cout << "Value is bigger than " << key << ", look left side" << endl;
            right = mid - 1;
        }
    }

    return -1;  
}

int main() {
    int sortedList[] = {3, 5, 6, 8, 11, 12, 14, 15, 17, 18};
    int size = 10;
    int key = 8;

    cout << "Start searching for " << key << " in the list." << endl;

    int result = binarySearch(sortedList, size, key);

    if (result != -1) {
        cout << "Found " << key << " at index " << result << "!" << endl;
    }
    else {
        cout << key << " is not in the list." << endl;
    }

    return 0;
}