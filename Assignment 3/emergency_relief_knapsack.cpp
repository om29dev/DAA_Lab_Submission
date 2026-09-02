#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

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
    return a.valuePerWeight() > b.valuePerWeight();
}

double fractionalKnapsack(vector<Item>& items, double capacity, double& totalWeight) {
    sort(items.begin(), items.end(), compare);

    double totalValue = 0;
    totalWeight = 0;

    cout << "\nSelected Relief Items:\n";

    for (const auto& item : items) {
        if (capacity <= 0)
            break;

        if (item.divisible) {
            double takenWeight = min(item.weight, capacity);
            double takenValue = item.valuePerWeight() * takenWeight;

            totalValue += takenValue;
            totalWeight += takenWeight;
            capacity -= takenWeight;

            cout << item.name << " : "
                 << fixed << setprecision(2)
                 << takenWeight << " kg, Utility = "
                 << takenValue << endl;
        }
        else if (item.weight <= capacity) {
            totalValue += item.value;
            totalWeight += item.weight;
            capacity -= item.weight;

            cout << item.name << " : "
                 << item.weight << " kg, Utility = "
                 << item.value << endl;
        }
    }

    return totalValue;
}

int main() {

    vector<Item> items = {
        Item("Medical Kits",    10, 100, false, 1),
        Item("Food Packets",    20, 60,  true,  3),
        Item("Drinking Water",  30, 90,  true,  2),
        Item("Blankets",        15, 45, false, 3),
        Item("Infant Formula",   5, 50, false, 1)
    };

    double capacity;

    cout << "========================================\n";
    cout << "   EMERGENCY RELIEF SUPPLY SYSTEM\n";
    cout << "========================================\n";

    cout << "\nEnter maximum boat capacity (kg): ";
    cin >> capacity;

    double totalWeight;
    double totalValue = fractionalKnapsack(items, capacity, totalWeight);

    cout << "\n========================================\n";
    cout << "           FINAL REPORT\n";
    cout << "========================================\n";

    cout << "Total Weight Carried : "
         << fixed << setprecision(2)
         << totalWeight << " kg\n";

    cout << "Total Utility Value  : "
         << fixed << setprecision(2)
         << totalValue << " units\n";

    cout << "========================================\n";

    return 0;
}
