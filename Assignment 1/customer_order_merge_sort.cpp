#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

struct Order {
    string orderId;
    string customerId;
    string status;
    string timestamp;
};

void merge(vector<Order>& orders, int low, int mid, int high) {
    vector<Order> left, right;

    for (int i = low; i <= mid; i++)
        left.push_back(orders[i]);

    for (int i = mid + 1; i <= high; i++)
        right.push_back(orders[i]);

    int i = 0, j = 0, k = low;

    while (i < left.size() && j < right.size()) {
        if (left[i].timestamp <= right[j].timestamp)
            orders[k++] = left[i++];
        else
            orders[k++] = right[j++];
    }

    while (i < left.size())
        orders[k++] = left[i++];

    while (j < right.size())
        orders[k++] = right[j++];
}

void mergeSort(vector<Order>& orders, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;

        mergeSort(orders, low, mid);
        mergeSort(orders, mid + 1, high);

        merge(orders, low, mid, high);
    }
}

vector<Order> loadOrders(const string& filename) {
    vector<Order> orders;
    ifstream file(filename);

    if (!file.is_open()) {
        cout << "Error opening customer_orders.csv" << endl;
        return orders;
    }

    string line;
    getline(file, line);

    while (getline(file, line)) {
        stringstream ss(line);
        Order o;

        getline(ss, o.orderId, ',');
        getline(ss, o.customerId, ',');
        getline(ss, o.status, ',');
        getline(ss, o.timestamp, ',');

        if (!o.timestamp.empty())
            orders.push_back(o);
    }

    file.close();
    return orders;
}

int main() {
    vector<Order> orders = loadOrders("customer_orders.csv");

    if (orders.empty()) {
        cout << "No valid orders found." << endl;
        return 1;
    }

    cout << "\n==============================================\n";
    cout << "       CUSTOMER ORDER SORTING SYSTEM\n";
    cout << "==============================================\n";

    cout << "\nSorting orders by purchase timestamp...\n";

    mergeSort(orders, 0, static_cast<int>(orders.size()) - 1);

    cout << "\n==============================================\n";
    cout << "        ORDERS SORTED BY TIMESTAMP\n";
    cout << "==============================================\n\n";

    cout << left
         << setw(5) << "No."
         << setw(38) << "Order ID"
         << setw(38) << "Customer ID"
         << setw(16) << "Status"
         << "Purchase Timestamp" << '\n';

    cout << string(120, '-') << '\n';

    int count = 0;

    for (const Order& o : orders) {
        if (count >= 10)
            break;

        cout << left
             << setw(5) << count + 1
             << setw(38) << o.orderId
             << setw(38) << o.customerId
             << setw(16) << o.status
             << o.timestamp << '\n';

        count++;
    }

    cout << "\n==============================================\n";
    cout << "Total orders sorted: " << orders.size() << '\n';
    cout << "Orders displayed: " << count << '\n';
    cout << "==============================================\n";

    return 0;
}

