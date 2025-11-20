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

int searchArray(int arr[], int size, int key, int &count) {
    count = 0;
    for (int i = 0; i < size; i++) {
        count++;
        if (arr[i] == key) return i;
    }
    return -1;
}

int searchList(Node* head, int key, int &count) {
    count = 0;
    int index = 0;
    Node* current = head;
    while (current) {
        count++;
        if (current->data == key) return index;
        current = current->next;
        index++;
    }
    return -1;
}

int main() {
    int arr[] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 18;
    int comparisonsArray, comparisonsList;

    Node* head = createList(arr, size);

    int posArray = searchArray(arr, size, key, comparisonsArray);
    int posList = searchList(head, key, comparisonsList);

    if (posArray != -1)
        cout << "Array: Found " << key << " at index " << posArray << " after " << comparisonsArray << " comparisons.\n";
    else
        cout << "Array: " << key << " not found after " << comparisonsArray << " comparisons.\n";

    if (posList != -1)
        cout << "Linked List: Found " << key << " at node " << posList << " after " << comparisonsList << " comparisons.\n";
    else
        cout << "Linked List: " << key << " not found after " << comparisonsList << " comparisons.\n";

    // Clean up linked list
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}