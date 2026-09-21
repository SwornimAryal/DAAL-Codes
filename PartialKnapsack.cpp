//  Partial Knapsack Algorithm in C
#include <iostream>
#include <algorithm>
using namespace std;

struct Item {
    int profit, weight;
    double ratio;
};

bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}

int main() {
    int n, capacity;
    cout << "Enter number of items: ";
    cin >> n;
    Item a[20];
    for (int i = 0; i < n; i++) {
        cout << "Enter profit and weight: ";
        cin >> a[i].profit >> a[i].weight;
        a[i].ratio = (double)a[i].profit / a[i].weight;
    }
    cout << "\nProfit to weight ratio:\n";
    for (int i = 0; i < n; i++)
        cout << "Item " << i + 1 << ": " << a[i].ratio << endl;
    sort(a, a + n, compare);
    cout << "\nEnter capacity: ";
    cin >> capacity;
    double profit = 0;
    cout << "\nItem selection:\n";
    for (int i = 0; i < n; i++) {
        if (capacity >= a[i].weight) {
            capacity -= a[i].weight;
            profit += a[i].profit;
            cout << "Item " << i + 1 << " selected completely\n";
        }
        
        else {
            double fraction = (double)capacity / a[i].weight;
            profit += a[i].profit * fraction;
            cout << "Item " << i + 1 << " selected partially\n";
            break;
        }
    }
    cout << "\nMaximum Profit = " << profit;
    return 0;
}