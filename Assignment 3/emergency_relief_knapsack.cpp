#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>

using namespace std;

struct Item {
    string name;
    double weight;
    double value;
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

double fractionalKnapsack(vector<Item>& items, double capacity, double& totalWeight) {
    sort(items.begin(), items.end(), compare);

    double totalValue = 0;
    totalWeight = 0;
    int selectedCount = 0;

    cout << "\n========== SELECTED RELIEF ITEMS ==========\n";

    for (const auto& item : items) {
        if (capacity <= 0)
            break;

        double takenWeight = 0;
        double takenValue = 0;

        if (item.divisible) {
            takenWeight = min(item.weight, capacity);
            takenValue = item.valuePerWeight() * takenWeight;
        } 
        else if (item.weight <= capacity) {
            takenWeight = item.weight;
            takenValue = item.value;
        }

        if (takenWeight > 0) {
            totalValue += takenValue;
            totalWeight += takenWeight;
            capacity -= takenWeight;
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

    cout << "\nTotal Items Selected: " << selectedCount << endl;

    return totalValue;
}

int main() {
    vector<Item> items = {
        Item("Medical Kits", 10, 100, false, 1),
        Item("Food Packets", 20, 60, true, 3),
        Item("Drinking Water", 30, 90, true, 2),
        Item("Blankets", 15, 45, false, 3),
        Item("Infant Formula", 5, 50, false, 1)
    };

    double capacity;

    cout << "========================================\n";
    cout << "     EMERGENCY RELIEF SUPPLY SYSTEM\n";
    cout << "========================================\n";

    cout << "\nPriority Levels: 1 = High, 2 = Medium, 3 = Low\n";
    cout << "Enter maximum boat capacity (kg): ";
    cin >> capacity;

    if (cin.fail() || capacity <= 0) {
        cout << "Invalid capacity. Enter a positive number.\n";
        return 1;
    }

    double totalWeight;
    double totalValue = fractionalKnapsack(items, capacity, totalWeight);

    cout << "\n========================================\n";
    cout << "               FINAL REPORT\n";
    cout << "========================================\n";

    cout << "Total Weight Carried : " << fixed << setprecision(2)
         << totalWeight << " kg\n";

    cout << "Remaining Capacity   : " << capacity - capacity + 0
         << " kg\n";

    cout << "Total Utility Value  : " << totalValue << " units\n";

    cout << "========================================\n";

    return 0;
}