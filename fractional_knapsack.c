//Fractional Knapsack Algorith
#include <stdio.h>
#include "mergesort.h"

struct Item {
    int profit;
    int weight;
    float ratio;
};

int main() {

    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter capacity: ");
    scanf("%d", &capacity);

    struct Item items[n];

    //profit and weight 
    for (int i = 0; i < n; i++) {
        printf("Enter profit and weight of item %d: ", i + 1);
        scanf("%d %d", &items[i].profit, &items[i].weight);
        items[i].ratio =
            (float)items[i].profit / items[i].weight;
    }

    mergesort(items, 0, n - 1);

    float maxProfit = 0;

    for (int i = 0; i < n; i++) {

        if (capacity >= items[i].weight) {
            capacity -= items[i].weight;
            maxProfit += items[i].profit;
        }
        else {
            maxProfit += items[i].ratio * capacity;
            break;
        }
    }

    printf("\nMaximum Profit = %.2f\n", maxProfit);

    return 0;
}