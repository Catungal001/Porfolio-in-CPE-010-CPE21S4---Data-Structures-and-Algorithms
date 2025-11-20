#include <iostream>
#include "nodes.h"
#include "searching_6.3B.h"

int main() {
    Node<int>* head = new_node(10);
    Node<int>* node2 = new_node(20);
    Node<int>* node3 = new_node(30);
    Node<int>* node4 = new_node(40);
    Node<int>* node5 = new_node(50);

    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    std::cout << "Linked list content: ";
    Node<int>* temp = head;
    while (temp != NULL) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << "\n";

    int key;
    std::cout << "Enter number to search: ";
    std::cin >> key;

    Node<int>* result = binarySearchLinkedList(head, key);

    if (result != NULL) {
        std::cout << "Searching is successful. Item " << key << " found in linked list.\n";
    } else {
        std::cout << "Searching is unsuccessful. Item " << key << " not found in linked list.\n";
    }

    return 0;
}