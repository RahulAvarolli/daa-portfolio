#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Graph {
public:
    int V;
    vector<vector<int>> adjMatrix;

    Graph(int V) {
        this->V = V;
        adjMatrix.resize(V, vector<int>(V, INT_MAX));
    }

    void addEdge(int u, int v, int weight) {
        adjMatrix[u][v] = weight;
        adjMatrix[v][u] = weight;
    }

    vector<pair<int, int>> primMST() {
        vector<bool> inMST(V, false);
        vector<pair<int, int>> mstEdges;
        inMST[0] = true;

        for (int i = 1; i < V; i++) {
            int minWeight = INT_MAX;
            int u = -1, v = -1;
            
            for (int j = 0; j < V; j++) {
                if (inMST[j]) {
                    for (int k = 0; k < V; k++) {
                        if (!inMST[k] && adjMatrix[j][k] < minWeight) {
                            minWeight = adjMatrix[j][k];
                            u = j;
                            v = k;
                        }
                    }
                }
            }

            inMST[v] = true;
            mstEdges.push_back({u, v});
        }

        return mstEdges;
    }
};

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;

    Graph g(V);

    cout << "Enter the number of edges: ";
    cin >> E;

    cout << "Enter the edges (format: u v weight) for each edge:\n";
    for (int i = 0; i < E; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        g.addEdge(u, v, weight);
    }

    vector<pair<int, int>> mst = g.primMST();
    cout << "Edges in the MST:\n";
    for (auto& edge : mst) {
        cout << edge.first << " - " << edge.second << endl;
    }

    return 0;
}
