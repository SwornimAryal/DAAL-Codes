#include <stdio.h>

struct Item {
    int start;
    int finish;
    char name[20];
};

void mergesort(struct Item arr[], int left, int right);

int main() {
    struct Item activities[] = {
        {1, 4, "A1"},
        {3, 5, "A2"},
        {0, 6, "A3"},
        {5, 7, "A4"},
        {3, 9, "A5"},
        {5, 9, "A6"},
        {6, 10, "A7"}
    };
    printf("Activity Selection using Greedy Strategy\n\n");
    //Merge Sort 
    mergesort(activities, 0, 6);
    printf("\nActivities sorted by finish time:\n");
    for (int i = 0; i < 7; i++) {
        printf("%s: Start = %d, Finish = %d\n",
               activities[i].name,
               activities[i].start,
               activities[i].finish);
    }

    // Greedy Activity Selection
    printf("\n--- Activity Selection ---\n");
    printf("Selected Activities:\n");
    int lastFinish = 0;
    int count = 0;
    for (int i = 0; i < 7; i++) {
        if (activities[i].start >= lastFinish) {
            printf("%s: Start = %d, Finish = %d\n",
                   activities[i].name,
                   activities[i].start,
                   activities[i].finish);
            lastFinish = activities[i].finish;
            count++;
        }
    }
    printf("\nMaximum number of non-overlapping activities = %d\n",
           count);
    return 0;
}
