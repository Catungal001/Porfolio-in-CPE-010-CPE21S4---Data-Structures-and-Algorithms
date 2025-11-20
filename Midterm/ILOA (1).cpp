#include <iostream>
#include <vector>
#include <list>
using namespace std;


class GraphMatrix {
private:
    int vertices;
    vector<vector<int>> adjMatrix;

public:
    GraphMatrix(int v) {
        vertices = v;
        adjMatrix.resize(v, vector<int>(v, 0));
    }

    void addEdge(int u, int v, bool directed = false) {
        adjMatrix[u][v] = 1;
        if (!directed) {
            adjMatrix[v][u] = 1; 
        }
    }

    void displayMatrix() {
        cout << "Adjacency Matrix:" << endl;
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

class GraphList {
private:
    int vertices;
    vector<list<int>> adjList;

public:
    GraphList(int v) {
        vertices = v;
        adjList.resize(v);
    }

    void addEdge(int u, int v, bool directed = false) {
        adjList[u].push_back(v);
        if (!directed) {
            adjList[v].push_back(u);
        }
    }

    void displayList() {
        cout << "Adjacency List:" << endl;
        for (int i = 0; i < vertices; i++) {
            cout << i << " -> ";
            for (int v : adjList[i]) {
                cout << v << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    
    int V = 5;

    cout << "UNDIRECTED GRAPH:" << endl;
    GraphMatrix g1(V);
    g1.addEdge(0, 1);
    g1.addEdge(0, 2);
    g1.addEdge(0, 3);
    g1.addEdge(1, 4);
    g1.addEdge(2, 3);
    g1.addEdge(3, 4);
    g1.displayMatrix();
    cout << endl;

    GraphList g2(V);
    g2.addEdge(0, 1);
    g2.addEdge(0, 2);
    g2.addEdge(0, 3);
    g2.addEdge(1, 4);
    g2.addEdge(2, 3);
    g2.addEdge(3, 4);
    g2.displayList();
    cout << endl;

    cout << "DIRECTED GRAPH:" << endl;
    GraphMatrix g3(V);
    g3.addEdge(0, 1, true);
    g3.addEdge(0, 2, true);
    g3.addEdge(0, 3, true);
    g3.addEdge(1, 4, true);
    g3.addEdge(2, 3, true);
    g3.addEdge(3, 4, true);
    g3.displayMatrix();
    cout << endl;

    GraphList g4(V);
    g4.addEdge(0, 1, true);
    g4.addEdge(0, 2, true);
    g4.addEdge(0, 3, true);
    g4.addEdge(1, 4, true);
    g4.addEdge(2, 3, true);
    g4.addEdge(3, 4, true);
    g4.displayList();
    cout << endl;

    return 0;
}
