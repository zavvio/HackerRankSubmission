// https://www.hackerrank.com/challenges/lilys-homework
// https://www.geeksforgeeks.org/minimum-number-swaps-required-sort-array/
// https://www.geeksforgeeks.org/heap-sort/
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE* fptr;

char* readline();
char** split_string(char*);

void swap(int *a, int *b);
void heapify(int arr[], int pos[], int n, int i);
void heapSort(int arr[], int pos[], int n);

int minSwaps(int arr[], int n);

// Complete the lilysHomework function below.
int lilysHomework(int arr_count, int* arr) {
    // This is essentially a min-swap-to-sort problem
    // But also need to check both ascending and descending sort
    // Thus, must use a sorting algorithm with O(n log n) worst case
    // choosing heap sort
    return minSwaps(arr, arr_count);
}

// Function returns the minimum number of swaps required to sort the array
int minSwaps(int arr[], int n) {
    int ans, ans_rev, cycle_size, j;
    int *values, *pos;
    bool *visited, *visited_rev;

    // Create two array (== a map), first one holding element values, and
    // second one its original position
    values = (int *) malloc(n * sizeof(int));
    pos = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        values[i] = arr[i];
        pos[i] = i;
        // fprintf(fptr, "%d --- pos = %d\n", values[i], pos[i]);
    }

    // Sort the array by array element values (ascending)
    heapSort(values, pos, n);

    // To keep track of visited elements. Initialize all elements as not visited or false.
    visited = (bool *) malloc(n * sizeof(bool));
    visited_rev = (bool *) malloc(n * sizeof(bool));
    for (int i = 0; i < n; i++) {
        visited[i] = false;
        visited_rev[i] = false;
    }

    // Initialize result
    ans = 0;
    ans_rev = 0;

    // Traverse array elements
    for (int i = 0; i < n; i++) {
        // already swapped and corrected or already present at correct pos
        if (visited[i] || pos[i] == i)
            continue;

        // find out the number of node in this cycle and add in ans
        cycle_size = 0;
        j = i;
        while (!visited[j]) {
            visited[j] = true;

            // move to next node
            j = pos[j];
            cycle_size++;
        }

        // Update answer by adding current cycle. 
        if (cycle_size > 0) {
            ans += (cycle_size - 1);
        }
    }

    // Traverse array elements (reversed)
    for (int i = 0; i < n; i++) {
        // already swapped and corrected or already present at correct pos
        // this part could have been easy if we sort the array again in descending order
        // but to save time, let's just compare the reversed index with some logic
        // e.g. n = 6
        // values:        1 5 4 3 2 6
        // orginal pos:   0 1 2 3 4 5
        // sorted values: 1 2 3 4 5 6
        // sorted pos:    0 4 3 2 1 5
        // reversed pos:  5 4 3 2 1 0
        // The reversed index is supposed to be n - i - 1 == 6 - 0 - 1 = 5
        if (visited_rev[i] || pos[i] == (n - i - 1))
            continue;

        // find out the number of node in this cycle and add in ans
        cycle_size = 0;
        j = i;
        while (!visited_rev[j]) {
            visited_rev[j] = true;

            // move to next node
            // Extending the trickiness here
            // j was 0 for value 1, then j should go to where value 6 is,
            // n - 1 - pos[j] == 6 - 1 - 0 = 5
            // again, we could have avoided these logic if we sort the values in reversed order
            j = n - 1 - pos[j];
            cycle_size++;
        }

        // Update answer by adding current cycle. 
        if (cycle_size > 0) {
            ans_rev += (cycle_size - 1);
        }
    }
    // Return result
    free(values);
    free(pos);
    free(visited);
    free(visited_rev);
    return ans < ans_rev ? ans : ans_rev;
}

void swap(int* a, int* b) { 
    int t = *a;
    *a = *b;
    *b = t;
}

// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(int arr[], int pos[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2*i + 1; // left = 2*i + 1
    int r = 2*i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        swap(&pos[i], &pos[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, pos, n, largest);
    }
}

// main function to do heap sort
void heapSort(int arr[], int pos[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, pos, n, i);

    // One by one extract an element from heap
    for (int i=n-1; i>=0; i--)
    {
        // Move current root to end
        swap(&arr[0], &arr[i]);
        swap(&pos[0], &pos[i]);

        // call max heapify on the reduced heap
        heapify(arr, pos, i, 0);
    }
}

int main()
{
    fptr = fopen(getenv("OUTPUT_PATH"), "w");

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

    int result = lilysHomework(arr_count, arr);

    fprintf(fptr, "%d\n", result);

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
