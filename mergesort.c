#include <stdio.h>

struct Item {
    int start;
    int finish;
    char name[20];
};

void printArray(struct Item arr[], int left, int right) {
    printf("[ ");

    for (int i = left; i <= right; i++)
        printf("(S=%d F=%d N=%s) ",
               arr[i].start, arr[i].finish, arr[i].name);

    printf("]");
}

void merge(struct Item arr[], int left, int mid, int right) {
    struct Item temp[50];
    int i = left;
    int j = mid + 1;
    int k = left;

    printf("Merging: ");
    printArray(arr, left, mid);
    printf(" and ");
    printArray(arr, mid + 1, right);
    printf("\n");

    // Sort according to increasing finish time
    while (i <= mid && j <= right) {

        if (arr[i].finish <= arr[j].finish)
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    printf("Result -> ");
    printArray(arr, left, right);
    printf("\n\n");
}

void mergesort(struct Item arr[], int left, int right) {

    if (left < right) {

        int mid = (left + right) / 2;

        printf("Splitting: ");
        printArray(arr, left, right);
        printf("\n");

        mergesort(arr, left, mid);
        mergesort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}