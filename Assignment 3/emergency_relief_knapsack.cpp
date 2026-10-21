
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>

using namespace std;

struct Item {
    string name;
    double weight, value;
    bool divisible;
    int priority;

    Item(string n, double w, double v, bool d, int p)
        : name(n), weight(w), value(v), divisible(d), priority(p) {}

    double valuePerWeight() const {
        return value / weight;
    }
};

bool compare(const Item& a, const Item& b) {
    if (a.priority != b.priority)
        return a.priority < b.priority;
    return a.valuePerWeight() > b.valuePerWeight();
}

double fractionalKnapsack(vector<Item>& items, double capacity,
                          double& totalWeight, double& remainingCapacity) {
    sort(items.begin(), items.end(), compare);

    double totalValue = 0;
    totalWeight = 0;
    remainingCapacity = capacity;
    int selectedCount = 0;

    cout << "\n========== SELECTED RELIEF ITEMS ==========\n";

    for (const auto& item : items) {
        if (remainingCapacity <= 0)
            break;

        double takenWeight = 0;
        double takenValue = 0;

        if (item.divisible) {
            takenWeight = min(item.weight, remainingCapacity);
            takenValue = item.valuePerWeight() * takenWeight;
        } else if (item.weight <= remainingCapacity) {
            takenWeight = item.weight;
            takenValue = item.value;
        }

        if (takenWeight > 0) {
            totalValue += takenValue;
            totalWeight += takenWeight;
            remainingCapacity -= takenWeight;
            selectedCount++;

            cout << "\nItem           : " << item.name;
            cout << "\nPriority       : " << item.priority;
            cout << "\nWeight Taken   : " << fixed << setprecision(2)
                 << takenWeight << " kg";
            cout << "\nUtility Value  : " << takenValue << " units";
            cout << "\nSelection Type : "
                 << (takenWeight < item.weight ? "Partial" : "Full");
            cout << "\n-------------------------------------------\n";
        }
    }

    cout << "\nTotal Items Selected: " << selectedCount << '\n';
    return totalValue;
}

int main() {
    int n;
    double capacity;

    cout << "========================================\n";
    cout << "     EMERGENCY RELIEF SUPPLY SYSTEM\n";
    cout << "========================================\n";

    cout << "Enter number of items: ";
    if (!(cin >> n) || n <= 0) {
        cout << "Invalid number of items.\n";
        return 1;
    }

    vector<Item> items;

    cout << "\nEnter item details (Name Weight Value):\n";

    for (int i = 0; i < n; i++) {
        string name;
        double weight, value;

        if (!(cin >> name >> weight >> value) ||
            weight <= 0 || value < 0) {
            cout << "Invalid item details.\n";
            return 1;
        }

        int priority;
        bool divisible;

        if (name == "Medical" || name == "Formula") {
            priority = 1;
            divisible = false;
        } else if (name == "Water") {
            priority = 2;
            divisible = true;
        } else {
            priority = 3;
            divisible = (name == "Food");
        }

        items.emplace_back(name, weight, value, divisible, priority);
    }

    cout << "Enter boat capacity: ";
    if (!(cin >> capacity) || capacity <= 0) {
        cout << "Invalid capacity.\n";
        return 1;
    }

    double totalWeight, remainingCapacity;
    double totalValue = fractionalKnapsack(
        items, capacity, totalWeight, remainingCapacity
    );

    cout << "\n========================================\n";
    cout << "               FINAL REPORT\n";
    cout << "========================================\n";
    cout << fixed << setprecision(2);
    cout << "Total Weight Carried : " << totalWeight << " kg\n";
    cout << "Remaining Capacity   : " << remainingCapacity << " kg\n";
    cout << "Total Utility Value  : " << totalValue << " units\n";
    cout << "========================================\n";

    return 0;
}
