// https://www.hackerrank.com/challenges/jim-and-the-orders
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

// Choose insertion sort (stable) over quicksort (instable), and insertion is more efficient than bubble sort; quicksort can be modified into stable, not too bad with external memory but quite complex to convert as in-place; gave up half way since N is small here, 10^3, need not to overkill.
/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int id[], int n) {
    int i, key, key_id, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        key_id = id[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            id[j + 1] = id[j];
            j = j - 1;
        }
        arr[j + 1] = key;
        id[j + 1] = key_id;
    }
}

// Complete the jimOrders function below.

// Please store the size of the integer array to be returned in result_count pointer. For example,
// int a[3] = {1, 2, 3};
//
// *result_count = 3;
//
// return a;
//
int* jimOrders(int orders_rows, int orders_columns, int** orders, int* result_count) {
    int *time, *customer_id;
    // Just build a "map" of serve time and customer number, then sort both together
    time = malloc(orders_rows * sizeof(int));
    customer_id = malloc(orders_rows * sizeof(int));
    for (int i = 0; i < orders_rows; i++) {
        // printf("Order %d: %d\n", orders[i][0], orders[i][1]);
        time[i] = orders[i][0] + orders[i][1];
        customer_id[i] = i + 1;
    }
    insertionSort(time, customer_id, orders_rows);
    *result_count = orders_rows;
    free(time);
    return customer_id;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* n_endptr;
    char* n_str = readline();
    int n = strtol(n_str, &n_endptr, 10);

    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

    int** orders = malloc(n * sizeof(int*));

    for (int i = 0; i < n; i++) {
        *(orders + i) = malloc(2 * (sizeof(int)));

        char** orders_item_temp = split_string(readline());

        for (int j = 0; j < 2; j++) {
            char* orders_item_endptr;
            char* orders_item_str = *(orders_item_temp + j);
            int orders_item = strtol(orders_item_str, &orders_item_endptr, 10);

            if (orders_item_endptr == orders_item_str || *orders_item_endptr != '\0') { exit(EXIT_FAILURE); }

            *(*(orders + i) + j) = orders_item;
        }
    }

    int orders_rows = n;
    int orders_columns = 2;

    int result_count;
    int* result = jimOrders(orders_rows, orders_columns, orders, &result_count);

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

/** A failed attempt to convert quicksort into stable & in-place.
void swap(int *a, int *b);
int special_ordered_partition_for_two_array(int arr[], int id[], int low, int high);
void special_ordered_quicksort_for_two_array(int arr[], int id[], int low, int high);

void swap(int* a, int* b) { 
    int t = *a;
    *a = *b;
    *b = t;
}

/* This function takes last element as pivot, places the pivot element at its
correct position in sorted array, and places all smaller (smaller than pivot)
to left of pivot and all larger elements to right of pivot *
int special_ordered_partition_for_two_array(int arr[], int id[], int low, int high) {
    int tmp, tmp_id;
    int pivot = arr[high]; // pivot
    int i = (low - 1); // index barrier of smaller element

    if (low == 281 && high == 395) {
      for (int i = low; i <= high; i++) {
        printf("%06d ", id[i]);
      }
      printf("\n");
      for (int i = low; i <= high; i++) {
        printf("%d ", arr[i]);
      }
      printf("\n");
    }
    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++; // increment index of smaller element
            if (id[i] == 500 || id[i] == 703 || id[j] == 500 || id[j] == 703) {
              printf("Swapping customer %d and %d at position i = %d, j = %d\n",
                     id[i], id[j], i, j);
            }
            swap(&arr[i], &arr[j]);
            swap(&id[i], &id[j]);
        }
    }

    // Replacing the simple swap with shifting here because the order must be kept
    tmp = arr[high];
    tmp_id = id[high];
    for (int j = high - 1; j >= i + 1; j--) {
        if (id[j] == 500 || id[j] == 703) {
            printf("Shifting cust %d from %d to %d\n", id[j], j, j+1);
        }
        arr[j + 1] = arr[j];
        id[j + 1] = id[j];
    }
    arr[i + 1] = tmp;
    id[i + 1] = tmp_id;
    // swap(&arr[i + 1], &arr[high]);
    // swap(&id[i + 1], &id[high]);
    return (i + 1);
}

/* The main function that implements quick sort
        arr[] --> Array to be sorted,
        low  --> Starting index,
        high  --> Ending index *
void special_ordered_quicksort_for_two_array(int arr[], int id[], int low, int high) {
  if (low < high) {    
    // pi is partitioning index, arr[p] is now at right place
    int pi = special_ordered_partition_for_two_array(arr, id, low, high);

    // Separately sort elements before
    // partition and after partition
    // if (pi - 1 - low > 5)
    //   printf("Sorting %d to %d for pi = %d\n", low, pi - 1, pi);
    special_ordered_quicksort_for_two_array(arr, id, low, pi - 1);
    // if (high - pi + 1 > 5)
    //   printf("Sorting %d to %d for pi = %d\n", pi + 1, high, pi);
    special_ordered_quicksort_for_two_array(arr, id, pi + 1, high);
    }
}
**/
