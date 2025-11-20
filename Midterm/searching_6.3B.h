#ifndef SEARCHING_H
#define SEARCHING_H

template <typename T>
Node<T>* binarySearchLinkedList(Node<T>* head, T key) {
    Node<T>* low = head;
    Node<T>* high = nullptr;
    Node<T>* mid = nullptr;

    while (low != nullptr) {
        mid = low;
        high = low->next;
        
        // Check if mid is the correct match
        if (mid != nullptr && mid->data == key) {
            return mid;
        }

        if (mid->data < key) {
            low = mid->next;
        } else {
            high = mid;
        }
    }
    
    return nullptr; // Item not found
}

#endif