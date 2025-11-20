#include <iostream>
using namespace std;


struct Node {
    char data;
    Node* firstChild;
    Node* nextSibling;
};

Node* createNode(char value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->firstChild = NULL;
    newNode->nextSibling = NULL;
    return newNode;
}

void display(Node* root, int level = 0) {
    if (root == NULL) return;

   
    for (int i = 0; i < level; i++) {
        cout << "  ";
    }
    cout << root->data << endl;

    
    display(root->firstChild, level + 1);

    
    display(root->nextSibling, level);
}

int main() {
    
    Node* A = createNode('A');

    
    Node* B = createNode('B');
    Node* C = createNode('C');
    Node* D = createNode('D');
    Node* E = createNode('E');
    Node* F = createNode('F');
    Node* G = createNode('G');

    A->firstChild = B;
    B->nextSibling = C;
    C->nextSibling = D;
    D->nextSibling = E;
    E->nextSibling = F;
    F->nextSibling = G;

    
    Node* H = createNode('H');
    D->firstChild = H;

    Node* I = createNode('I');
    Node* J = createNode('J');
    E->firstChild = I;
    I->nextSibling = J;
    
    Node* P = createNode('P');
    Node* Q = createNode('Q');
    J->firstChild = P;
    P->nextSibling = Q;

    Node* K = createNode('K');
    Node* L = createNode('L');
    Node* M = createNode('M');
    F->firstChild = K;
    K->nextSibling = L;
    L->nextSibling = M;

    Node* N = createNode('N');
    G->firstChild = N;

    cout << "Tree structure:" << endl;
    display(A);

    return 0;
}
