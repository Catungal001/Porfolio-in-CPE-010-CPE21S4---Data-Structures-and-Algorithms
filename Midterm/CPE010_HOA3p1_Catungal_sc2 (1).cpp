#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;


template <typename T>
struct Edge {
    int src;
    int dest;
    T weight;
};


template <typename T>
class Graph {
public:
    Graph(int n) {
        V = n;
    }

    void addEdge(int u, int v, T w) {
        if (u >= 1 && u <= V && v >= 1 && v <= V) {
            edges.push_back({u, v, w});
        } else {
            cout << "Invalid vertex" << endl;
        }
    }

    vector<Edge<T>> getEdgesFrom(int v) const {
        vector<Edge<T>> result;
        for (auto &e : edges) {
            if (e.src == v) result.push_back(e);
        }
        return result;
    }

    int vertices() const { return V; }

    
    void printGraph() const {
        for (int i = 1; i <= V; i++) {
            cout << i << ": ";
            auto adj = getEdgesFrom(i);
            for (auto &e : adj) {
                cout << "{" << e.dest << ": " << e.weight << "} ";
            }
            cout << endl;
        }
    }

private:
    int V;
    vector<Edge<T>> edges;
};


template <typename T>
Graph<T> makeGraph() {
    Graph<T> G(8);

    map<int, vector<pair<int, T>>> data;
    data[1] = {{2, 2}, {5, 3}};
    data[2] = {{1, 2}, {5, 5}, {4, 1}};
    data[3] = {{4, 2}, {7, 3}};
    data[4] = {{2, 1}, {3, 2}, {5, 2}, {6, 4}, {8, 5}};
    data[5] = {{1, 3}, {2, 5}, {4, 2}, {8, 3}};
    data[6] = {{4, 4}, {7, 4}, {8, 1}};
    data[7] = {{3, 3}, {6, 4}};
    data[8] = {{4, 5}, {5, 3}, {6, 1}};

    for (auto &i : data) {
        for (auto &j : i.second) {
            G.addEdge(i.first, j.first, j.second);
        }
    }

    return G;
}


template <typename T>
vector<int> BFS(const Graph<T>& G, int start) {
    queue<int> q;
    set<int> visited;
    vector<int> order;

    q.push(start);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        if (visited.find(curr) == visited.end()) {
            visited.insert(curr);
            order.push_back(curr);

            for (auto e : G.getEdgesFrom(curr)) {
                if (visited.find(e.dest) == visited.end()) {
                    q.push(e.dest);
                }
            }
        }
    }
    return order;
}


int main() {
    Graph<unsigned> G = makeGraph<unsigned>();
    cout << "Graph adjacency list:" << endl;
    G.printGraph();

    cout << "BFS Order of vertices:" << endl;
    auto result = BFS(G, 1);
    for (auto v : result) {
        cout << v << endl;
    }

    return 0;
}
