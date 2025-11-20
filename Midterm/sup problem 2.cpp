#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createList(int arr[], int size) {
    if (size == 0) return nullptr;
    Node* head = new Node{arr[0], nullptr};
    Node* current = head;
    for (int i = 1; i < size; i++) {
        current->next = new Node{arr[i], nullptr};
        current = current->next;
    }
    return head;
}

// Count occurrences in array
int countOccurrencesArray(int arr[], int size, int key, int &comparisons) {
    comparisons = 0;
    int count = 0;
    for (int i = 0; i < size; i++) {
        comparisons++;
        if (arr[i] == key) count++;
    }
    return count;
}

// Count occurrences in linked list
int countOccurrencesList(Node* head, int key, int &comparisons) {
    comparisons = 0;
    int count = 0;
    Node* current = head;
    while (current) {
        comparisons++;
        if (current->data == key) count++;
        current = current->next;
    }
    return count;
}

int main() {
    int arr[] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 18;
    int comparisonsArray, comparisonsList;

    Node* head = createList(arr, size);

    int countArr = countOccurrencesArray(arr, size, key, comparisonsArray);
    int countList = countOccurrencesList(head, key, comparisonsList);

    cout << "Array: Key " << key << " occurs " << countArr << " times with " << comparisonsArray << " comparisons.\n";
    cout << "Linked List: Key " << key << " occurs " << countList << " times with " << comparisonsList << " comparisons.\n";

    // Clean up linked list
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}