// https://www.hackerrank.com/challenges/frequency-of-digits-1
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int freq[10] = {0};
    char str[1001];
    scanf("%1000s", str);
    for (int i=0; i < 1000; i++) {
        switch(str[i]) {
            case '\0': i = 1000; break;
            case '0': freq[0]++; break;
            case '1': freq[1]++; break;
            case '2': freq[2]++; break;
            case '3': freq[3]++; break;
            case '4': freq[4]++; break;
            case '5': freq[5]++; break;
            case '6': freq[6]++; break;
            case '7': freq[7]++; break;
            case '8': freq[8]++; break;
            case '9': freq[9]++; break;
        }
    }
    for (int i=0; i<10; i++) {
        printf("%d", freq[i]);
        if (i == 9)
            printf("\n");
        else
            printf(" ");
    }
    return 0;
}
