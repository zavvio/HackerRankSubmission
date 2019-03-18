// https://www.hackerrank.com/challenges/greedy-florist
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
int partition(int arr[], int low, int high);
void quicksort(int arr[], int low, int high);

// Complete the getMinimumCost function below.
int getMinimumCost(int k, int c_count, int* c) {
    int purchased = 0, sum = 0, i_friend = 0, index = c_count - 1;
    quicksort(c, 0, c_count - 1);
    while (index >= 0) {
        sum += (purchased + 1) * c[index];
        i_friend++;
        if (i_friend / k) {
            purchased++;
            i_friend %= k;
        }
        index--;
    }
    return sum;
}

void swap(int* a, int* b) { 
    int t = *a;
    *a = *b;
    *b = t;
}

/* This function takes last element as pivot, places the pivot element at its
correct position in sorted array, and places all smaller (smaller than pivot)
to left of pivot and all larger elements to right of pivot */
int partition (int arr[], int low, int high) {
    int pivot = arr[high]; // pivot
    int i = (low - 1); // index barrier of smaller element

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] < pivot) {
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
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        /* pi is partitioning index, arr[p] is now at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char** nk = split_string(readline());

    char* n_endptr;
    char* n_str = nk[0];
    int n = strtol(n_str, &n_endptr, 10);

    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

    char* k_endptr;
    char* k_str = nk[1];
    int k = strtol(k_str, &k_endptr, 10);

    if (k_endptr == k_str || *k_endptr != '\0') { exit(EXIT_FAILURE); }

    char** c_temp = split_string(readline());

    int* c = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        char* c_item_endptr;
        char* c_item_str = *(c_temp + i);
        int c_item = strtol(c_item_str, &c_item_endptr, 10);

        if (c_item_endptr == c_item_str || *c_item_endptr != '\0') { exit(EXIT_FAILURE); }

        *(c + i) = c_item;
    }

    int c_count = n;

    int minimumCost = getMinimumCost(k, c_count, c);

    fprintf(fptr, "%d\n", minimumCost);

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

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!line) {
            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);
    } else {
        data = realloc(data, data_length + 1);

        data[data_length] = '\0';
    }

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
