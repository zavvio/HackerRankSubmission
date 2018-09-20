// https://www.hackerrank.com/challenges/printing-tokens-
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    char *token, *str, *sentence;
    str = sentence = (char *) malloc(10000 * sizeof(char));
    scanf("%9999[^\n]", sentence);
    while (token = strsep(&str, " ")) {
        printf("%s\n", token);
    }
    free(sentence);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    // char c, str[10000];
    // scanf("%9999[^\n]", str);
    // for (int i = 0; i < 9999; i++) {
    //     if (str[i] == '\0') break;
    //     if (str[i] == ' ') str[i] = '\n';
    // }
    // printf("%s\n", str);
    return 0;
}
