/*
 * Bubble Sort - Algorithm Analysis Midterm
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped) break; /* Zaten sirali, cik */
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(void) {
    srand(time(NULL));

    /* Kucuk demo */
    int demo[] = {5, 3, 8, 4, 2};
    int n = 5;

    printf("=== BUBBLE SORT ===\n\n");
    printf("Before: ");
    printArray(demo, n);

    bubbleSort(demo, n);

    printf("After:  ");
    printArray(demo, n);

    /* Performans testi */
    int sizes[] = {1000, 5000, 10000, 20000};
    int numSizes = 4;

    printf("\n--- Performance Test ---\n");
    printf("%-10s %-15s %-15s %-15s\n", "n", "Best(s)", "Worst(s)", "Random(s)");

    for (int s = 0; s < numSizes; s++) {
        int size = sizes[s];
        int *arr = malloc(size * sizeof(int));

        clock_t start, end;

        /* Best: zaten sirali */
        for (int i = 0; i < size; i++) arr[i] = i;
        start = clock();
        bubbleSort(arr, size);
        end = clock();
        double best = (double)(end - start) / CLOCKS_PER_SEC;

        /* Worst: ters sirali */
        for (int i = 0; i < size; i++) arr[i] = size - i;
        start = clock();
        bubbleSort(arr, size);
        end = clock();
        double worst = (double)(end - start) / CLOCKS_PER_SEC;

        /* Random */
        for (int i = 0; i < size; i++) arr[i] = rand() % 10000;
        start = clock();
        bubbleSort(arr, size);
        end = clock();
        double avg = (double)(end - start) / CLOCKS_PER_SEC;

        printf("%-10d %-15.4f %-15.4f %-15.4f\n", size, best, worst, avg);
        free(arr);
    }

    return 0;
}
