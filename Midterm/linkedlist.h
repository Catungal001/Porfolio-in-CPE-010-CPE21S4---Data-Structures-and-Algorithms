#ifndef LINKEDLIST_H
#define LINKEDLIST_H


template <typename T>
struct Node {
    T data;
    Node* next;
};

/
template <typename T>
Node<T>* new_node(T val) {
    Node<T>* node = new Node<T>;
    node->data = val;
    node->next = nullptr;
    return node;
}


template <typename T>
bool linearS(Node<T>* head, T target) {
    Node<T>* current = head;
    while (current != nullptr) {
        if (current->data == target) {
            return true;
        }
        current = current->next;
    }
    return false;
}

#endif S