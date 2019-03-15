// https://www.hackerrank.com/challenges/largest-permutation
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

// Complete the largestPermutation function below.

// Please store the size of the integer array to be returned in result_count pointer. For example,
// int a[3] = {1, 2, 3};
//
// *result_count = 3;
//
// return a;
//
int* largestPermutation(int k, int arr_count, int* arr, int* result_count) {
    // first method: n^2 without acknowledge the array is actually first N natural numbers
    // int temp, largest, index_largest, swapped = 0;
    // *result_count = arr_count;
    // for (int i = 0; swapped < k && i < arr_count; i++) {
    //     largest = arr[i];
    //     for (int j = i + 1; j < arr_count; j++) {
    //         if (arr[j] > largest) {
    //             largest = arr[j];
    //             index_largest = j;
    //         }
    //     }
    //     if (arr[i] != largest) {
    //         // printf("swapping %d=>%d & %d=>%d\n", i, arr[i], index_largest, arr[index_largest]);
    //         temp = arr[i];
    //         arr[i] = arr[index_largest];
    //         arr[index_largest] = temp;
    //         swapped++;
    //     }
    // }

    // second method: first N natural numbers
    int temp, index_temp, walker = 0, swapped = 0;
    int *index = calloc(arr_count + 1, sizeof(int));
    *result_count = arr_count;
    for (int i = 0; i < arr_count; i++) {
        index[arr[i]] = i;
    }
    while (walker < arr_count && swapped < k) {
        if (arr[walker] != (arr_count - walker)) {
            // swap actual numbers
            temp = arr[walker];
            arr[walker] = arr_count - walker;
            arr[index[arr_count - walker]] = temp;
            // update index array
            index_temp = index[temp];
            index[temp] = index[arr_count - walker];
            index[arr_count - walker] = index_temp;
            swapped++;
        }
        walker++;
    }
    free(index);
    return arr;
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

    char** arr_temp = split_string(readline());

    int* arr = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        char* arr_item_endptr;
        char* arr_item_str = *(arr_temp + i);
        int arr_item = strtol(arr_item_str, &arr_item_endptr, 10);

        if (arr_item_endptr == arr_item_str || *arr_item_endptr != '\0') { exit(EXIT_FAILURE); }

        *(arr + i) = arr_item;
    }

    int arr_count = n;

    int result_count;
    int* result = largestPermutation(k, arr_count, arr, &result_count);

    for (int i = 0; i < result_count; i++) {
        fprintf(fptr, "%d", *(result + i));

        if (i != result_count - 1) {
            fprintf(fptr, " ");
        }
    }

    fprintf(fptr, "\n");

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
