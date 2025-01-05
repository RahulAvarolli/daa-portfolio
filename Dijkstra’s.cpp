#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

struct Edge {
    int to;
    int weight;
};

struct Node {
    int vertex;
    int distance;
    bool operator>(const Node &other) const {
        return distance > other.distance;
    }
};

void Dijkstra(vector<vector<Edge>> &graph, int source) {
    int n = graph.size();
    vector<int> distance(n, INT_MAX);
    vector<int> previous(n, -1);
    priority_queue<Node, vector<Node>, greater<Node>> pq;

    distance[source] = 0;
    pq.push({source, 0});

    vector<bool> visited(n, false);

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();

        int u = current.vertex;

        if (visited[u])
            continue;

        visited[u] = true;

        for (Edge edge : graph[u]) {
            int v = edge.to;
            int weight = edge.weight;

            if (!visited[v] && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                previous[v] = u;
                pq.push({v, distance[v]});
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (distance[i] == INT_MAX) {
            cout << "Vertex " << i << ": No Path\n";
        } else {
            cout << "Vertex " << i << ": Distance = " << distance[i] << ", Previous = " << previous[i] << "\n";
        }
    }
}

int main() {
    int n, m;
    cout << "Enter the number of vertices: ";
    cin >> n;

    cout << "Enter the number of edges: ";
    cin >> m;

    vector<vector<Edge>> graph(n);

    cout << "Enter the edges (format: u v weight) for each edge:\n";
    for (int i = 0; i < m; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph[u].push_back({v, weight});
    }

    int source;
    cout << "Enter the source vertex: ";
    cin >> source;

    Dijkstra(graph, source);

    return 0;
}
