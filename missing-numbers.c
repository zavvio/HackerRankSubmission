// https://www.hackerrank.com/challenges/missing-numbers
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

// Complete the missingNumbers function below.

// Please store the size of the integer array to be returned in result_count pointer. For example,
// int a[3] = {1, 2, 3};
//
// *result_count = 3;
//
// return a;
//
int* missingNumbers(int arr_count, int* arr, int brr_count, int* brr, int* result_count) {
    int min = brr[0], freq[101] = {0};
    int *result = calloc(101, sizeof(int));
    *result_count = 0;
    for (int i = 1; i < brr_count; i++) {
        if (brr[i] < min) {
            min = brr[i];
        }
    }
    for (int i = 0; i < arr_count; i++) {
        freq[arr[i]-min]--;
    }
    for (int i = 0; i < brr_count; i++) {
        freq[brr[i]-min]++;
    }
    for (int i = 0; i < 101; i++) {
        if (freq[i] > 0) {
            *(result + *result_count) = min + i;
            // printf("val = %d, i = %d\n", *(result + *result_count), i);
            (*result_count)++;
        }
    }
    return result;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* n_endptr;
    char* n_str = readline();
    int n = strtol(n_str, &n_endptr, 10);

    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

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

    char* m_endptr;
    char* m_str = readline();
    int m = strtol(m_str, &m_endptr, 10);

    if (m_endptr == m_str || *m_endptr != '\0') { exit(EXIT_FAILURE); }

    char** brr_temp = split_string(readline());

    int* brr = malloc(m * sizeof(int));

    for (int i = 0; i < m; i++) {
        char* brr_item_endptr;
        char* brr_item_str = *(brr_temp + i);
        int brr_item = strtol(brr_item_str, &brr_item_endptr, 10);

        if (brr_item_endptr == brr_item_str || *brr_item_endptr != '\0') { exit(EXIT_FAILURE); }

        *(brr + i) = brr_item;
    }

    int brr_count = m;

    int result_count;
    int* result = missingNumbers(arr_count, arr, brr_count, brr, &result_count);

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
