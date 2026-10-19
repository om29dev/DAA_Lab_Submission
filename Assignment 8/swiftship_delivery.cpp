#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct Node {
    int cost, bound, city, level;
    vector<int> path;

    bool operator>(const Node& other) const {
        return bound > other.bound;
    }
};

int n;
vector<vector<int>> costMatrix;
int bestCost = INF;
vector<int> bestPath;

int calculateBound(Node node) {
    int bound = node.cost;

    for (int i = 0; i < n; i++) {
        if (find(node.path.begin(), node.path.end(), i) != node.path.end())
            continue;

        int minimum = INF;

        for (int j = 0; j < n; j++) {
            if (i != j &&
                (find(node.path.begin(), node.path.end(), j) == node.path.end() || j == 0)) {
                minimum = min(minimum, costMatrix[i][j]);
            }
        }

        if (minimum != INF)
            bound += minimum;
    }

    if (node.level == n)
        bound = node.cost + costMatrix[node.city][0];

    return bound;
}

void leastCostBranchAndBound() {
    priority_queue<Node, vector<Node>, greater<Node>> pq;

    Node root;
    root.cost = 0;
    root.city = 0;
    root.level = 1;
    root.path = {0};
    root.bound = calculateBound(root);

    pq.push(root);

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();

        if (current.bound >= bestCost)
            continue;

        if (current.level == n) {
            int totalCost = current.cost + costMatrix[current.city][0];

            if (totalCost < bestCost) {
                bestCost = totalCost;
                bestPath = current.path;
                bestPath.push_back(0);
            }

            continue;
        }

        for (int next = 1; next < n; next++) {
            if (find(current.path.begin(), current.path.end(), next)
                != current.path.end())
                continue;

            Node child;
            child.path = current.path;
            child.path.push_back(next);
            child.city = next;
            child.level = current.level + 1;
            child.cost = current.cost + costMatrix[current.city][next];
            child.bound = calculateBound(child);

            if (child.bound < bestCost)
                pq.push(child);
        }
    }
}

int main() {
    cout << "SwiftShip Delivery Route Optimization\n";
    cout << "------------------------------------\n";

    cout << "Enter the number of cities: ";
    cin >> n;

    if (n < 2) {
        cout << "Please enter at least 2 cities.\n";
        return 0;
    }

    costMatrix.assign(n, vector<int>(n));

    cout << "\nEnter the cost matrix (" << n << " x " << n << "):\n";
    cout << "Enter 0 for the distance from a city to itself.\n";

    for (int i = 0; i < n; i++) {
        cout << "Enter costs from City " << i << ": ";

        for (int j = 0; j < n; j++) {
            cin >> costMatrix[i][j];
        }
    }

    leastCostBranchAndBound();

    cout << "\n----------- Optimal Route -----------\n";

    if (bestCost == INF) {
        cout << "No valid route found.\n";
        return 0;
    }

    cout << "Minimum Delivery Cost: " << bestCost << '\n';
    cout << "Optimal Route: ";

    for (int i = 0; i < bestPath.size(); i++) {
        cout << "City " << bestPath[i];

        if (i != bestPath.size() - 1)
            cout << " -> ";
    }

    cout << "\n-------------------------------------\n";

    return 0;
}

