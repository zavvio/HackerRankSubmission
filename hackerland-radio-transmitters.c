// https://www.hackerrank.com/challenges/hackerland-radio-transmitters
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *readline();
char **split_string(char *);

void swap(int *a, int *b);
void heapify(int arr[], int n, int i);
void heapSort(int arr[], int n);

// Complete the hackerlandRadioTransmitters function below.
int hackerlandRadioTransmitters(int x_count, int *x, int k) {
  int count = 0, uncovered = 0, covering = 0, installing = 0;
  heapSort(x, x_count);
  while (uncovered < x_count) {
    covering = uncovered;
    // printf("Uncovered: %d ==> %d\n", uncovered, x[uncovered]);
    while ((covering + 1) < x_count && x[covering + 1] <= (x[uncovered] + k)) {
      covering++;
      // printf("Covering: %d ==> %d\n", covering, x[covering]);
    }
    installing = covering;
    count++;
    covering++;
    // printf("Installing tower %d at %d ==> %d\n", count, installing,
    // x[installing]);
    while (covering < x_count && x[covering] <= (x[installing] + k)) {
      // printf("Covering: %d ==> %d\n", covering, x[covering]);
      covering++;
    }
    uncovered = covering;
    // printf("Updating uncovered to: %d ==> ", uncovered);
    // if (uncovered < x_count) {
    //     printf("%d\n", x[uncovered]);
    // } else {
    //     printf("EOF\n");
    // }
  }
  return count;
}

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(int arr[], int n, int i) {
  int largest = i;   // Initialize largest as root
  int l = 2 * i + 1; // left = 2*i + 1
  int r = 2 * i + 2; // right = 2*i + 2

  // If left child is larger than root
  if (l < n && arr[l] > arr[largest])
    largest = l;

  // If right child is larger than largest so far
  if (r < n && arr[r] > arr[largest])
    largest = r;

  // If largest is not root
  if (largest != i) {
    swap(&arr[i], &arr[largest]);

    // Recursively heapify the affected sub-tree
    heapify(arr, n, largest);
  }
}

// main function to do heap sort
void heapSort(int arr[], int n) {
  // Build heap (rearrange array)
  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(arr, n, i);

  // One by one extract an element from heap
  for (int i = n - 1; i >= 0; i--) {
    // Move current root to end
    swap(&arr[0], &arr[i]);

    // call max heapify on the reduced heap
    heapify(arr, i, 0);
  }
}

int main() {
  FILE *fptr = fopen(getenv("OUTPUT_PATH"), "w");

  char **nk = split_string(readline());

  char *n_endptr;
  char *n_str = nk[0];
  int n = strtol(n_str, &n_endptr, 10);

  if (n_endptr == n_str || *n_endptr != '\0') {
    exit(EXIT_FAILURE);
  }

  char *k_endptr;
  char *k_str = nk[1];
  int k = strtol(k_str, &k_endptr, 10);

  if (k_endptr == k_str || *k_endptr != '\0') {
    exit(EXIT_FAILURE);
  }

  char **x_temp = split_string(readline());

  int *x = malloc(n * sizeof(int));

  for (int i = 0; i < n; i++) {
    char *x_item_endptr;
    char *x_item_str = *(x_temp + i);
    int x_item = strtol(x_item_str, &x_item_endptr, 10);
    if (x_item_endptr == x_item_str || *x_item_endptr != '\0') {
        if (x_item_endptr == x_item_str)
            printf("x_item_endptr == x_item_str");
        if (*x_item_endptr != '\0')
          printf("*x_item_endptr != '\\0'\nx_item_str = %s\n", x_item_str);
        // exit(EXIT_FAILURE);
    }

    *(x + i) = x_item;
    // if (i > 780)
    //     printf("i = %d/%d ==> %d \n", i, n, x_item);
  }

  int x_count = n;

  int result = hackerlandRadioTransmitters(x_count, x, k);

  fprintf(fptr, "%d\n", result);

  fclose(fptr);

  return 0;
}

char *readline() {
  size_t alloc_length = 1024;
  size_t data_length = 0;
  char *data = malloc(alloc_length);

  while (true) {
    char *cursor = data + data_length;
    char *line = fgets(cursor, alloc_length - data_length, stdin);

    if (!line) {
      break;
    }

    data_length += strlen(cursor);

    if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
      break;
    }

    size_t new_length = alloc_length << 1;
    data = realloc(data, new_length);

    if (!data) {
      break;
    }

    alloc_length = new_length;
  }

  if (data[data_length - 1] == '\n') {
    data[data_length - 1] = '\0';
  }

  data = realloc(data, data_length);

  return data;
}

char **split_string(char *str) {
  char **splits = NULL;
  char *token = strtok(str, " ");

  int spaces = 0;

  while (token) {
    splits = realloc(splits, sizeof(char *) * ++spaces);
    if (!splits) {
      return splits;
    }

    splits[spaces - 1] = token;

    token = strtok(NULL, " ");
  }

  return splits;
}
