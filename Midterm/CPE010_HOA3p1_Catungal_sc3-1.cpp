#include <iostream>
#include <vector>
using namespace std;


struct Node {
    string data;
    vector<Node*> children;
};

bool preOrderFind(Node* node, string key) {
    if (node == nullptr) return false;
    if (node->data == key) {
        cout << key << " was found!" << endl;
        return true;
    }
    for (Node* child : node->children) {
        if (preOrderFind(child, key)) return true;
    }
    return false;
}


bool postOrderFind(Node* node, string key) {
    if (node == nullptr) return false;
    for (Node* child : node->children) {
        if (postOrderFind(child, key)) return true;
    }
    if (node->data == key) {
        cout << key << " was found!" << endl;
        return true;
    }
    return false;
}

bool inOrderFind(Node* node, string key) {
    if (node == nullptr) return false;
    int n = node->children.size();
    for (int i = 0; i < n / 2; i++) {
        if (inOrderFind(node->children[i], key)) return true;
    }
    if (node->data == key) {
        cout << key << " was found!" << endl;
        return true;
    }
    for (int i = n / 2; i < n; i++) {
        if (inOrderFind(node->children[i], key)) return true;
    }
    return false;
}

void findData(string choice, Node* root, string key) {
    if (choice == "pre") preOrderFind(root, key);
    else if (choice == "post") postOrderFind(root, key);
    else if (choice == "in") inOrderFind(root, key);
}

int main() {
   
    Node* A = new Node{"A"};
    Node* B = new Node{"B"};
    Node* C = new Node{"C"};
    Node* D = new Node{"D"};
    A->children = {B, C, D};

    findData("pre", A, "C");  
    findData("post", A, "D"); 
    findData("in", A, "B");   

    return 0;
}
