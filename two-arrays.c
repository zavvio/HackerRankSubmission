// https://www.hackerrank.com/challenges/two-arrays
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

// Complete the twoArrays function below.

// Please either make the string static or allocate on the heap. For example,
// static char str[] = "hello world";
// return str;
//
// OR
//
// char* str = "hello world";
// return str;
//
char* twoArrays(int k, int A_count, int* A, int B_count, int* B) {
    static char yes[] = "YES";
    static char no[] = "NO";
    quicksort(A, 0, A_count - 1);
    quicksort(B, 0, B_count - 1);
    for (int i = 0; i < A_count; i++) {
        // printf("A = %d, B = %d\n", A[i], B[B_count - i - 1]);
        if (A[i] + B[B_count - i - 1] < k) {
            return no;
        }
    }
    return yes;
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

    char* q_endptr;
    char* q_str = readline();
    int q = strtol(q_str, &q_endptr, 10);

    if (q_endptr == q_str || *q_endptr != '\0') { exit(EXIT_FAILURE); }

    for (int q_itr = 0; q_itr < q; q_itr++) {
        char** nk = split_string(readline());

        char* n_endptr;
        char* n_str = nk[0];
        int n = strtol(n_str, &n_endptr, 10);

        if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

        char* k_endptr;
        char* k_str = nk[1];
        int k = strtol(k_str, &k_endptr, 10);

        if (k_endptr == k_str || *k_endptr != '\0') { exit(EXIT_FAILURE); }

        char** A_temp = split_string(readline());

        int* A = malloc(n * sizeof(int));

        for (int i = 0; i < n; i++) {
            char* A_item_endptr;
            char* A_item_str = *(A_temp + i);
            int A_item = strtol(A_item_str, &A_item_endptr, 10);

            if (A_item_endptr == A_item_str || *A_item_endptr != '\0') { exit(EXIT_FAILURE); }

            *(A + i) = A_item;
        }

        int A_count = n;

        char** B_temp = split_string(readline());

        int* B = malloc(n * sizeof(int));

        for (int i = 0; i < n; i++) {
            char* B_item_endptr;
            char* B_item_str = *(B_temp + i);
            int B_item = strtol(B_item_str, &B_item_endptr, 10);

            if (B_item_endptr == B_item_str || *B_item_endptr != '\0') { exit(EXIT_FAILURE); }

            *(B + i) = B_item;
        }

        int B_count = n;

        char* result = twoArrays(k, A_count, A, B_count, B);

        fprintf(fptr, "%s\n", result);
    }

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
