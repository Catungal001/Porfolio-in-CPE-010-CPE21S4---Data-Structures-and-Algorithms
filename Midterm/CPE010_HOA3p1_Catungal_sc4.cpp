#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    string data;
    vector<Node*> children;

    Node(string val) {
        data = val;
    }
};

void preOrder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    for (auto child : root->children)
        preOrder(child);
}

void postOrder(Node* root) {
    if (!root) return;
    for (auto child : root->children)
        postOrder(child);
    cout << root->data << " ";
}

void findData(Node* root, string key, string choice) {
    if (!root) return;

    if (choice == "pre") {
        if (root->data == key) {
            cout << key << " was found!" << endl;
            return;
        }
        for (auto child : root->children)
            findData(child, key, choice);
    }
    else if (choice == "post") {
        for (auto child : root->children)
            findData(child, key, choice);
        if (root->data == key)
            cout << key << " was found!" << endl;
    }
}

int main() {
    
    Node* A = new Node("A");
    Node* B = new Node("B");
    Node* C = new Node("C");
    Node* D = new Node("D");
    Node* E = new Node("E");
    Node* F = new Node("F");
    Node* G = new Node("G");
    Node* H = new Node("H");
    Node* I = new Node("I");
    Node* J = new Node("J");
    Node* K = new Node("K");
    Node* L = new Node("L");
    Node* M = new Node("M");
    Node* N = new Node("N");
    Node* O = new Node("O");

    
    A->children = {B, C, D, E, F, G};
    D->children = {H};
    E->children = {I, J};
    F->children = {K, L, M};
    G->children = {N, O}; 

    
    findData(A, "O", "pre");   
    findData(A, "O", "post");  

    return 0;
}
