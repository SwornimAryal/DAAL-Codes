#include <stdio.h>

struct Activity {
    int start_time;
    int fin_time;
    int actNo;
};

// Swap two activities
void swap(struct Activity *a, struct Activity *b) {
    struct Activity temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function for Quick Sort
int partition(struct Activity activities[], int low, int high) {
    int pivot = activities[high].fin_time;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (activities[j].fin_time <= pivot) {
            i++;
            swap(&activities[i], &activities[j]);
        }
    }

    swap(&activities[i + 1], &activities[high]);

    return i + 1;
}

// Quick Sort by finish time
void quickSort(struct Activity activities[], int low, int high) {
    if (low < high) {
        int pi = partition(activities, low, high);

        quickSort(activities, low, pi - 1);
        quickSort(activities, pi + 1, high);
    }
}

int main() {

    int n;

    printf("Enter number of activities: ");
    scanf("%d", &n);

    struct Activity activities[n];

    printf("Enter start time and finish time:\n");

    for (int i = 0; i < n; i++) {

        printf("Activity %d: ", i + 1);

        scanf("%d %d",
              &activities[i].start_time,
              &activities[i].fin_time);

        activities[i].actNo = i + 1;
    }

    // Sort activities by finish time
    quickSort(activities, 0, n - 1);

    printf("\nActivities sorted by finish time:\n");

    for (int i = 0; i < n; i++) {

        printf("Activity %d: Start time = %d, Finish time = %d\n",
               activities[i].actNo,
               activities[i].start_time,
               activities[i].fin_time);
    }

    // Greedy Activity Selection
    printf("\nSelected activities:\n");

    int last_finish_time = 0;
    int count = 0;

    for (int i = 0; i < n; i++) {

        if (activities[i].start_time >= last_finish_time) {

            printf("Activity %d: Start time = %d, Finish time = %d\n",
                   activities[i].actNo,
                   activities[i].start_time,
                   activities[i].fin_time);

            last_finish_time = activities[i].fin_time;
            count++;
        }
    }

    printf("\nMaximum number of activities = %d\n", count);

    return 0;
}