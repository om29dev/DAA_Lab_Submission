#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Order {
    int orderId;
    string customerName;
    long timestamp;
};

void merge(vector<Order>& orders, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<Order> L(n1);
    vector<Order> R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = orders[left + i];

    for (int j = 0; j < n2; j++)
        R[j] = orders[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i].timestamp <= R[j].timestamp) {
            orders[k] = L[i];
            i++;
        } else {
            orders[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        orders[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        orders[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<Order>& orders, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(orders, left, mid);
        mergeSort(orders, mid + 1, right);

        merge(orders, left, mid, right);
    }
}

int main() {
    int n;

    cout << "Enter number of customer orders: ";
    cin >> n;

    vector<Order> orders(n);

    cout << "\nEnter order details:\n";
    cout << "(Order ID Customer Name Timestamp)\n\n";

    for (int i = 0; i < n; i++) {
        cin >> orders[i].orderId
            >> orders[i].customerName
            >> orders[i].timestamp;
    }

    mergeSort(orders, 0, n - 1);

    cout << "\nOrders sorted by timestamp:\n";
    cout << "---------------------------------------------\n";

    for (const auto& order : orders) {
        cout << "Order ID: " << order.orderId
             << " | Customer: " << order.customerName
             << " | Timestamp: " << order.timestamp
             << endl;
    }

    return 0;
}