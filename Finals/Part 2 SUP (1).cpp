#include <iostream>
#include <vector>
#include <thread>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] < R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        thread t1(mergeSort, ref(arr), left, mid);
        thread t2(mergeSort, ref(arr), mid + 1, right);

        t1.join();
        t2.join();

        merge(arr, left, mid, right);
    }
}

int main() {
    vector<int> numbers = {10, 3, 7, 1, 5, 2};

    cout << "Before sorting: ";
    for (int n : numbers)
        cout << n << " ";
    cout << endl;

    mergeSort(numbers, 0, numbers.size() - 1);

    cout << "After sorting: ";
    for (int n : numbers)
        cout << n << " ";
    cout << endl;

    return 0;
}
