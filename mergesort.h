#ifndef MERGESORT_H
#define MERGESORT_H

typedef struct {
    int start;
    int finish;
    char name[20];
} Item;

void mergesort(Item arr[], int left, int right);

#endif