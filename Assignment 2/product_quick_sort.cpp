#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Product {
    string name;
    float price;
    float rating;
    int popularity;
};

vector<string> parseCSVLine(string line) {
    vector<string> fields;
    string field;
    bool inQuotes = false;

    for (char c : line) {
        if (c == '"') {
            inQuotes = !inQuotes;
        }
        else if (c == ',' && !inQuotes) {
            fields.push_back(field);
            field.clear();
        }
        else {
            field += c;
        }
    }

    fields.push_back(field);
    return fields;
}

string cleanNumber(string value) {
    string result;

    for (char c : value) {
        if ((c >= '0' && c <= '9') || c == '.') {
            result += c;
        }
    }

    return result;
}

vector<Product> loadProducts(string filename) {
    vector<Product> products;
    ifstream file(filename);

    if (!file.is_open()) {
        cout << "Error opening amazon.csv" << endl;
        return products;
    }

    string line;
    getline(file, line);

    while (getline(file, line)) {
        vector<string> data = parseCSVLine(line);

        if (data.size() < 8)
            continue;

        try {
            Product p;

            p.name = data[1];
            p.price = stof(cleanNumber(data[3]));
            p.rating = stof(cleanNumber(data[6]));
            p.popularity = stoi(cleanNumber(data[7]));

            products.push_back(p);
        }
        catch (...) {
            continue;
        }
    }

    file.close();
    return products;
}

void quickSort(vector<Product>& products, int low, int high,
               bool (*compare)(const Product&, const Product&)) {

    if (low < high) {

        int pivotIndex = low;
        Product pivot = products[high];

        for (int i = low; i < high; i++) {

            if (compare(products[i], pivot)) {
                swap(products[i], products[pivotIndex]);
                pivotIndex++;
            }
        }

        swap(products[pivotIndex], products[high]);

        quickSort(products, low, pivotIndex - 1, compare);
        quickSort(products, pivotIndex + 1, high, compare);
    }
}

bool compareByPrice(const Product& a, const Product& b) {
    return a.price < b.price;
}

bool compareByRating(const Product& a, const Product& b) {
    return a.rating < b.rating;
}

bool compareByPopularity(const Product& a, const Product& b) {
    return a.popularity < b.popularity;
}

int main() {

    vector<Product> products = loadProducts("amazon.csv");

    if (products.empty()) {
        cout << "No products found." << endl;
        return 1;
    }

    string choice;

    cout << "\n==============================================\n";
    cout << "       AMAZON PRODUCT SORTING SYSTEM\n";
    cout << "==============================================\n";

    cout << "\nEnter sorting parameter\n";
    cout << "1. price\n";
    cout << "2. rating\n";
    cout << "3. popularity\n";
    cout << "\nChoice: ";

    cin >> choice;

    bool (*compare)(const Product&, const Product&);

    if (choice == "price") {
        compare = compareByPrice;
    }
    else if (choice == "rating") {
        compare = compareByRating;
    }
    else if (choice == "popularity") {
        compare = compareByPopularity;
    }
    else {
        cout << "\nInvalid choice." << endl;
        return 1;
    }

    quickSort(products, 0, products.size() - 1, compare);

    cout << "\n==============================================\n";
    cout << "          TOP 10 PRODUCTS BY " << choice << "\n";
    cout << "==============================================\n\n";

    cout << left
         << setw(5) << "No."
         << setw(55) << "Product"
         << setw(12) << "Price"
         << setw(10) << "Rating"
         << setw(15) << "Popularity"
         << endl;

    cout << string(97, '-') << endl;

    int count = 0;

    for (int i = products.size() - 1;
         i >= 0 && count < 10;
         i--, count++) {

        string name = products[i].name;

        if (name.length() > 52)
            name = name.substr(0, 49) + "...";

        cout << left
             << setw(5) << count + 1
             << setw(55) << name
             << setw(12) << fixed << setprecision(2) << products[i].price
             << setw(10) << fixed << setprecision(1) << products[i].rating
             << setw(15) << products[i].popularity
             << endl;
    }

    cout << "\n==============================================\n";
    cout << "Total products sorted: " << products.size() << endl;
    cout << "==============================================\n";

    return 0;
}