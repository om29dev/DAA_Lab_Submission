#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct Edge {
    int u, v, weight;
};

int main() {
    int stages, n, m;
    cout << "Enter number of stages: ";
    if (!(cin >> stages)) return 0;

    cout << "Enter total number of vertices: ";
    cin >> n;

    cout << "Enter total number of edges: ";
    cin >> m;

    vector<vector<pair<int, int>>> adj(n + 1);
    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    int source, sink;
    cout << "Enter source vertex: ";
    cin >> source;
    cout << "Enter sink vertex: ";
    cin >> sink;

    vector<long long> cost(n + 1, LLONG_MAX);
    vector<int> nxt(n + 1, -1);

    cost[sink] = 0;

    for (int i = sink - 1; i >= source; i--) {
        for (auto &edge : adj[i]) {
            int to = edge.first;
            int weight = edge.second;
            if (cost[to] != LLONG_MAX && cost[to] + weight < cost[i]) {
                cost[i] = cost[to] + weight;
                nxt[i] = to;
            }
        }
    }

    if (cost[source] == LLONG_MAX) {
        cout << "\nNo valid path found from source to sink.\n";
        return 0;
    }

    cout << "\nMinimum Delivery Cost: " << cost[source] << "\n";
    cout << "Optimal Delivery Route: ";
    int curr = source;
    while (curr != -1) {
        cout << curr;
        if (curr == sink) break;
        cout << " -> ";
        curr = nxt[curr];
    }
    cout << "\n";

    return 0;
}
