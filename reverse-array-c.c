// https://www.hackerrank.com/challenges/reverse-array-c
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, *arr, i;
    int tmp, pos_mid;
    scanf("%d", &num);
    arr = (int*) malloc(num * sizeof(int));
    for(i = 0; i < num; i++) {
        scanf("%d", arr + i);
    }
    pos_mid = (num % 2) ? num / 2 : (num - 1) / 2;
    for(i = 0; i <= pos_mid; i++) {
        tmp = arr[i];
        arr[i] = arr[num - i - 1];
        arr[num - i - 1] = tmp;
    }
    /* Write the logic to reverse the array. */   
    for(i = 0; i < num; i++)
        printf("%d ", *(arr + i));
    return 0;
}
