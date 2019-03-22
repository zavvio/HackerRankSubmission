// https://www.hackerrank.com/challenges/fraudulent-activity-notifications
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

// Complete the activityNotifications function below.
int activityNotifications(int expenditure_count, int* expenditure, int d) {
    int walker, count_spendings, count_notification = 0;
    int trail_spendings[201] = {0};
    double median;
    for (int i = 0; i < d; i++) {
        trail_spendings[expenditure[i]]++;
    }
    for (int day = d; day < expenditure_count; day++) {
        // printf("Analyzing day %d, spent %d\n", day, expenditure[day]);
        // for (int i = 0; i < 201; i++) {
        //     if (trail_spendings[i] != 0) {
        //         printf("%d ==> %d\n", i, trail_spendings[i]);
        //     }
        // }
        walker = -1;
        count_spendings = 0;
        median = 0;
        // using counting sort, so it's "index base 1"
        // for odd, e.g. 5, only need 5 / 2 => 2 => +1 => 3rd number
        // for even, e.g. 4, need 4 / 2 => 2nd and +1 => 3rd number
        while (count_spendings < (d / 2)) {
            walker++;
            count_spendings += trail_spendings[walker];
        }
        if (d % 2 == 0) { // trailing day count is even
            median += walker;
        }
        while (count_spendings < ((d / 2) + 1)) {
            walker++;
            count_spendings += trail_spendings[walker];
        }
        median += walker;
        if (d % 2 == 0) { // trailing day count is even
            median /= 2;
        }
        // printf("Median = %f\n", median);
        if (expenditure[day] >= (median * 2)) {
            count_notification++;
        }
        trail_spendings[expenditure[day - d]]--;
        trail_spendings[expenditure[day]]++;
    }
    return count_notification;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char** nd = split_string(readline());

    char* n_endptr;
    char* n_str = nd[0];
    int n = strtol(n_str, &n_endptr, 10);

    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

    char* d_endptr;
    char* d_str = nd[1];
    int d = strtol(d_str, &d_endptr, 10);

    if (d_endptr == d_str || *d_endptr != '\0') { exit(EXIT_FAILURE); }

    char** expenditure_temp = split_string(readline());

    int* expenditure = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        char* expenditure_item_endptr;
        char* expenditure_item_str = *(expenditure_temp + i);
        int expenditure_item = strtol(expenditure_item_str, &expenditure_item_endptr, 10);

        if (expenditure_item_endptr == expenditure_item_str || *expenditure_item_endptr != '\0') { exit(EXIT_FAILURE); }

        *(expenditure + i) = expenditure_item;
    }

    int expenditure_count = n;

    int result = activityNotifications(expenditure_count, expenditure, d);

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
