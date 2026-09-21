//Assign 2 (Case Study): Sorting product prices for flash sale using Quick Sort algorithm

#include <stdio.h>
#include <time.h>
long long comparisons = 0;
long long swaps = 0;
int pass = 1;
void printPrices(int prices[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", prices[i]);
    printf("\n");
}

void swap(int prices[], int i, int j) {
    if (i != j) {
        int temp = prices[i];
        prices[i] = prices[j];
        prices[j] = temp;
        swaps++;
    }
}

int partition(int prices[], int l, int h, int n) {
    int pivot = prices[l];
    int i = l;
    int j = h;
    printf("\n-----------------------------\n");
    printf("Pass %d\n", pass++);
    printf("Pivot Price Selected: %d\n", pivot);
    while (i < j) {
        do {
            i++;
            comparisons++;
        } while (i < h && prices[i] <= pivot);
        do {
            j--;
            comparisons++;
        } while (prices[j] > pivot);
        if (i < j)
            swap(prices, i, j);
    }
    swap(prices, l, j);
    printf("Partitioned Prices: ");
    printPrices(prices, n);
    return j;
}

void quickSort(int prices[], int l, int h, int n) {
    if (l < h){
        int p = partition(prices, l, h, n);
        quickSort(prices, l, p, n);
        quickSort(prices, p + 1, h, n);
    }
}

int main(){
    int n;
    printf("===== FLASH SALE PRICE SORTING =====\n");
    printf("Enter number of products: ");
    scanf("%d", &n);
    int prices[n + 1];
    printf("Enter product prices:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &prices[i]);
    // Sentinel value
    prices[n] = 999999;
    clock_t start = clock();
    quickSort(prices, 0, n, n);
    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\n==============================\n");
    printf("Sorted Product Prices:\n");
    printPrices(prices, n);
    printf("\nPerformance Statistics\n");
    printf("----------------------\n");
    printf("Comparisons : %lld\n", comparisons);
    printf("Swaps       : %lld\n", swaps);
    printf("Execution Time : %.6f seconds\n", time_taken);
    printf("\nComplexity Analysis\n");
    printf("----------------------\n");
    printf("Best Case    : O(n log n)\n");
    printf("Average Case : O(n log n)\n");
    printf("Worst Case   : O(n^2)\n");
    return 0;
}
