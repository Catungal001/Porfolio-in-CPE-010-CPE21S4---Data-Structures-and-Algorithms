#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <map>
using namespace std;

// simple edge structure
template <typename T>
struct Edge {
    int src;
    int dest;
    T weight;
};

// simple graph class
template <typename T>
class Graph {
public:
    Graph(int n) {
        V = n;
    }

    void addEdge(Edge<T> e) {
        if (e.src >= 1 && e.src <= V && e.dest >= 1 && e.dest <= V) {
            edges.push_back(e);
        } else {
            cout << "Vertex out of bounds!" << endl;
        }
    }

    // return outgoing edges from vertex v
    vector<Edge<T>> outgoing(int v) const {
        vector<Edge<T>> out;
        for (auto &e : edges) {
            if (e.src == v) out.push_back(e);
        }
        return out;
    }

    int vertices() const { return V; }

    // print adjacency list
    void printGraph() const {
        for (int i = 1; i <= V; i++) {
            cout << i << ": ";
            auto out = outgoing(i);
            for (auto &e : out) {
                cout << "{" << e.dest << "} ";
            }
            cout << endl;
        }
    }

private:
    int V; 
    vector<Edge<T>> edges;
};

// depth first search
template <typename T>
vector<int> DFS(const Graph<T> &G, int start) {
    stack<int> st;
    vector<int> order;
    set<int> visited;

    st.push(start);
    while (!st.empty()) {
        int curr = st.top();
        st.pop();

        if (visited.find(curr) == visited.end()) {
            visited.insert(curr);
            order.push_back(curr);

            // push all neighbors
            for (auto e : G.outgoing(curr)) {
                if (visited.find(e.dest) == visited.end()) {
                    st.push(e.dest);
                }
            }
        }
    }
    return order;
}

// create a reference graph
template <typename T>
Graph<T> makeGraph() {
    Graph<T> G(8);
    map<int, vector<int>> edges;
    edges[1] = {2, 5};
    edges[2] = {1, 5, 4};
    edges[3] = {4, 7};
    edges[4] = {2, 3, 5, 6, 8};
    edges[5] = {1, 2, 4, 8};
    edges[6] = {4, 7, 8};
    edges[7] = {3, 6};
    edges[8] = {4, 5, 6};

    for (auto &i : edges) {
        for (auto &j : i.second) {
            G.addEdge(Edge<T>{i.first, j, 0});
        }
    }
    return G;
}

int main() {
    Graph<int> G = makeGraph<int>();
    cout << "Graph adjacency list:" << endl;
    G.printGraph();

    cout << "\nDFS Order: " << endl;
    auto order = DFS(G, 1);
    for (auto v : order) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}
