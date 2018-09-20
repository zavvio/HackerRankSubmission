// https://www.hackerrank.com/challenges/the-love-letter-mystery
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int theLoveLetterMystery(char* s){
    // Complete this function
    int count = 0;
    char *front, *back;
    front = s;
    back = s + strlen(s) - 1;
    while (front < back) {
        if (*front == *back) {
            front++;
            back--;
        } else if (*front > *back) {
            (*front)--;
            count++;
        } else {
            (*back)--;
            count++;
        }
    }
    return count;
}

int main() {
    int q; 
    scanf("%i", &q);
    for(int a0 = 0; a0 < q; a0++){
        char* s = (char *)malloc(512000 * sizeof(char));
        scanf("%s", s);
        int result = theLoveLetterMystery(s);
        printf("%d\n", result);
    }
    return 0;
}
