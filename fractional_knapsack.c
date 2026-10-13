// Fractional Knapsack Algorithm

#include <stdio.h>

struct Item {
    int profit;
    int weight;
    float ratio;
};

// Merge function
void merge(struct Item items[], int left, int mid, int right) {

    struct Item temp[50];

    int i = left;
    int j = mid + 1;
    int k = left;

    // Sort according to decreasing ratio
    while (i <= mid && j <= right) {

        if (items[i].ratio >= items[j].ratio)
            temp[k++] = items[i++];
        else
            temp[k++] = items[j++];
    }

    while (i <= mid)
        temp[k++] = items[i++];

    while (j <= right)
        temp[k++] = items[j++];

    for (i = left; i <= right; i++)
        items[i] = temp[i];
}

// Merge Sort function
void mergesort(struct Item items[], int left, int right) {

    if (left < right) {

        int mid = (left + right) / 2;

        mergesort(items, left, mid);
        mergesort(items, mid + 1, right);

        merge(items, left, mid, right);
    }
}

int main() {

    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter capacity: ");
    scanf("%d", &capacity);

    struct Item items[n];

    // Enter profit and weight
    for (int i = 0; i < n; i++) {

        printf("Enter profit and weight of item %d: ", i + 1);

        scanf("%d %d",
              &items[i].profit,
              &items[i].weight);

        items[i].ratio =
            (float)items[i].profit / items[i].weight;
    }

    // Sort items by ratio
    mergesort(items, 0, n - 1);

    float maxProfit = 0;

    // Select items
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