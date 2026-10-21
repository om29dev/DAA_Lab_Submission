#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

struct Item {
    string name;
    int weight, value;
};

struct State {
    int weight, value;
    vector<string> items;
};

int main() {
    int n, W;

    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter truck capacity: ";
    cin >> W;

    vector<Item> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i].name >> a[i].weight >> a[i].value;
    }

    vector<State> dp = {{0, 0, {}}};
    int merged = 0, pruned = 0;

    for (const auto& item : a) {
        vector<State> next = dp;

        for (auto s : dp) {
            if (s.weight + item.weight <= W) {
                s.weight += item.weight;
                s.value += item.value;
                s.items.push_back(item.name);
                next.push_back(s);
            } else {
                pruned++;
            }
        }

        map<int, State> uniqueStates;

        for (auto s : next) {
            if (uniqueStates.count(s.weight)) {
                merged++;
                if (s.value > uniqueStates[s.weight].value)
                    uniqueStates[s.weight] = s;
            } else {
                uniqueStates[s.weight] = s;
            }
        }

        dp.clear();

        int bestValue = -1;

        for (auto entry : uniqueStates) {
            State s = entry.second;

            if (s.value > bestValue) {
                dp.push_back(s);
                bestValue = s.value;
            } else {
                pruned++;
            }
        }
    }

    State best = dp.back();

    for (auto s : dp) {
        if (s.value > best.value)
            best = s;
    }

    cout << "\nSelected Items:\n";
    for (auto name : best.items)
        cout << name << "\n";

    cout << "Total Weight: " << best.weight << " kg\n";
    cout << "Maximum Utility: " << best.value << "\n";
    cout << "Merged States: " << merged << "\n";
    cout << "Pruned States: " << pruned << "\n";

    return 0;
}
