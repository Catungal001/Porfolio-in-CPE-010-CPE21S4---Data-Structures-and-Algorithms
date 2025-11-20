#include <iostream>
#include "linkedlist.h"

int main() {
    Node<char>* name1 = new_node('K');
    Node<char>* name2 = new_node('e');
    Node<char>* name3 = new_node('r');
    Node<char>* name4 = new_node('w');
    Node<char>* name5 = new_node('i');
    Node<char>* name6 = new_node('n');

    name1->next = name2;
    name2->next = name3;
    name3->next = name4;
    name4->next = name5;
    name5->next = name6;
    name6->next = nullptr;

    std::cout << "Linked list (Your name): ";
    Node<char>* temp = name1;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << "\n";

    char findChar;
    std::cout << "Enter a character to search in your name: ";
    std::cin >> findChar;

    if (linearS(name1, findChar)) {
        std::cout << "Searching is successful. '" << findChar << "' is in the list.\n";
    } else {
        std::cout << "Searching is unsuccessful. '" << findChar << "' not found.\n";
    }

    return 0;
}