//Assign 1 (Case Study): Searching for account numbers using Linear and Binary Search algorithms-=[]f
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int linearComparisons = 0;
int binaryComparisons = 0;
int linearSearch(int arr[], int n, int key)
{
    linearComparisons = 0;
    for (int i = 0; i < n; i++)
    {
        linearComparisons++;      
        if (arr[i] == key)
            return i;             
    }
    return -1;                    
}

int binarySearch(int arr[], int n, int key)
{
    int low = 0;
    int high = n - 1;
    binaryComparisons = 0;
    while (low <= high)
    {
        binaryComparisons++;
        int mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main()
{
    int smallSize = 10;
    int largeSize = 100000;
    int small[10];
    int *large = (int *)malloc(largeSize * sizeof(int));
    for (int i = 0; i < smallSize; i++)
        small[i] = 1001 + i;
    for (int i = 0; i < largeSize; i++)
        large[i] = 1001 + i;
    int key = 1010;   
    int position;
    clock_t start, end;
    double timeTaken;
    printf("ACCOUNT NUMBERS ARE SORTED IN ASCENDING ORDER\n");
    printf("\n========== SMALL DATASET ==========\n");

    // Linear Search
    start = clock();
    position = linearSearch(small, smallSize, key);
    end = clock();
    timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nLinear Search\n");
    printf("Account Position : %d\n", position + 1);
    printf("Comparisons      : %d\n", linearComparisons);
    printf("Execution Time   : %f seconds\n", timeTaken);

    // Binary Search
    start = clock();
    position = binarySearch(small, smallSize, key);
    end = clock();
    timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nBinary Search\n");
    printf("Account Position : %d\n", position + 1);
    printf("Comparisons      : %d\n", binaryComparisons);
    printf("Execution Time   : %f seconds\n", timeTaken);
    printf("\n========== LARGE DATASET ==========\n");
    key = 101000; 

    // Linear Search
    start = clock();
    position = linearSearch(large, largeSize, key);
    end = clock();
    timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nLinear Search\n");
    printf("Account Position : %d\n", position + 1);
    printf("Comparisons      : %d\n", linearComparisons);
    printf("Execution Time   : %f seconds\n", timeTaken);

    // Binary Search
    start = clock();
    position = binarySearch(large, largeSize, key);
    end = clock();
    timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nBinary Search\n");
    printf("Account Position : %d\n", position + 1);
    printf("Comparisons      : %d\n", binaryComparisons);
    printf("Execution Time   : %f seconds\n", timeTaken);
    free(large);
    return 0;
}