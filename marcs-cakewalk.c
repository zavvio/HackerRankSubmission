// https://www.hackerrank.com/challenges/marcs-cakewalk
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char** split_string(char*);

void swap(int *a, int *b);
int partition_reverse (int arr[], int low, int high);
void quicksort_reverse(int arr[], int low, int high);

// Complete the marcsCakewalk function below.
long marcsCakewalk(int calorie_count, int *calorie) {
    long min = 0;
    quicksort_reverse(calorie, 0, calorie_count - 1);
    for (int i = 0; i < calorie_count; i++) {
        min += (long) calorie[i] << i;
    }
    return min;
}

void swap(int* a, int* b) { 
    int t = *a;
    *a = *b;
    *b = t;
}

/* This function takes last element as pivot, places the pivot element at its
correct position in sorted array, and places all larger (larger than pivot)
to left of pivot and all smaller elements to right of pivot */
int partition_reverse (int arr[], int low, int high) {
    int pivot = arr[high]; // pivot
    int i = (low - 1); // index barrier of smaller element

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] >= pivot) {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* The main function that implements quick sort
        arr[] --> Array to be sorted,
        low  --> Starting index,
        high  --> Ending index */
void quicksort_reverse(int arr[], int low, int high) {
    if (low < high) {
        /* pi is partitioning index, arr[p] is now at right place */
        int pi = partition_reverse(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quicksort_reverse(arr, low, pi - 1);
        quicksort_reverse(arr, pi + 1, high);
    }
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* n_endptr;
    char* n_str = readline();
    int n = strtol(n_str, &n_endptr, 10);

    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

    char** calorie_temp = split_string(readline());

    int* calorie = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        char* calorie_item_endptr;
        char* calorie_item_str = *(calorie_temp + i);
        int calorie_item = strtol(calorie_item_str, &calorie_item_endptr, 10);

        if (calorie_item_endptr == calorie_item_str || *calorie_item_endptr != '\0') { exit(EXIT_FAILURE); }

        *(calorie + i) = calorie_item;
    }

    int calorie_count = n;

    long result = marcsCakewalk(calorie_count, calorie);

    fprintf(fptr, "%ld\n", result);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);
        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}
