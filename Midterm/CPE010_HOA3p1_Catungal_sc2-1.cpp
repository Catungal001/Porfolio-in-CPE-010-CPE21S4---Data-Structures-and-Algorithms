#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    char data;
    vector<Node*> children;
    Node(char val) {
        data = val;
    }
};

void preOrder(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    for (int i = 0; i < root->children.size(); i++) {
        preOrder(root->children[i]);
    }
}

void postOrder(Node* root) {
    if (root == nullptr) return;
    for (int i = 0; i < root->children.size(); i++) {
        postOrder(root->children[i]);
    }
    cout << root->data << " ";
}


void inOrder(Node* root) {
    if (root == nullptr) return;
    if (root->children.size() > 0)
        inOrder(root->children[0]); 
    cout << root->data << " ";
    for (int i = 1; i < root->children.size(); i++) {
        inOrder(root->children[i]);
    }
}

int main() {
    Node* A = new Node('A');
    Node* B = new Node('B');
    Node* C = new Node('C');
    Node* D = new Node('D');
    Node* E = new Node('E');
    Node* F = new Node('F');
    Node* G = new Node('G');
    Node* H = new Node('H');
    Node* I = new Node('I');
    Node* J = new Node('J');
    Node* K = new Node('K');
    Node* L = new Node('L');
    Node* M = new Node('M');
    Node* N = new Node('N');
    Node* P = new Node('P');
    Node* Q = new Node('Q');

    A->children = {B, C, D, E, F, G};
    D->children = {H};
    E->children = {I, J};
    J->children = {P, Q};
    F->children = {K, L, M};
    G->children = {N};

    cout << "Pre-order: "; preOrder(A); cout << endl;
    cout << "Post-order: "; postOrder(A); cout << endl;
    cout << "In-order: "; inOrder(A); cout << endl;

    return 0;
}
