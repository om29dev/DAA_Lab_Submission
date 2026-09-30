#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Item {
    string name;
    int weight;
    int value;
};

int main() {
    int n, W;
    cout << "Enter number of relief items: ";
    if (!(cin >> n)) return 0;

    cout << "Enter truck capacity (kg): ";
    cin >> W;

    vector<Item> items(n);
    cout << "Enter each item's name, weight, and utility value:\n";
    for (int i = 0; i < n; i++) {
        cin >> items[i].name >> items[i].weight >> items[i].value;
    }

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        int wt = items[i - 1].weight;
        int val = items[i - 1].value;
        for (int w = 1; w <= W; w++) {
            if (wt <= w) {
                dp[i][w] = max(val + dp[i - 1][w - wt], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    int maxUtility = dp[n][W];
    cout << "\nMaximum Relief Utility: " << maxUtility << "\n";

    vector<string> selectedItems;
    int totalWeight = 0;
    int currW = W;

    for (int i = n; i >= 1; i--) {
        if (dp[i][currW] != dp[i - 1][currW]) {
            selectedItems.push_back(items[i - 1].name);
            totalWeight += items[i - 1].weight;
            currW -= items[i - 1].weight;
        }
    }

    reverse(selectedItems.begin(), selectedItems.end());

    cout << "Total Weight Carried: " << totalWeight << " kg\n";
    cout << "Selected Relief Supplies:\n";
    for (const string &itemName : selectedItems) {
        cout << "- " << itemName << "\n";
    }

    return 0;
}
