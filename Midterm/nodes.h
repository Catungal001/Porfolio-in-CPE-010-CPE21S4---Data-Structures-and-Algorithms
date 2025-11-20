#ifndef NODES_H
#define NODES_H

template <typename T>
struct Node {
    T data;
    Node* next;

    Node(T data) : data(data), next(nullptr) {}
};

template <typename T>
Node<T>* new_node(T data) {
    return new Node<T>(data);
}

#endif
