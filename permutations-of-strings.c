// https://www.hackerrank.com/challenges/permutations-of-strings
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Reference: https://en.wikipedia.org/wiki/Permutation#Generation_in_lexicographic_order
int next_permutation(int n, char **s)
{
	/**
	* Complete this method
	* Return 0 when there is no next permutation and 1 otherwise
	* Modify array s to its next permutation
	*/
    int k = -1, l;
    int pos_mid;
    char *buff;

    // Step 1: Find the largest index k such that a[k] < a[k + 1]. If no such index exists, the permutation is the last permutation.
    for (int i=n-2; i>=0; i--) {
        if (strcmp(*(s + i), *(s + i + 1)) < 0) {
            k = i;
            break;
        }
    }
    if (k == -1) return 0;
    // Step 2: Find the largest index l greater than k such that a[k] < a[l].
    for (int i=n-1; i>k; i--) {
        if (strcmp(*(s + k), *(s + i)) < 0) {
            l = i;
            break;
        }
    }
    // Step 3: Swap the value of a[k] with that of a[l].
    // printf("k = %d ==> %s\n", k, *(s + k));
    // printf("l = %d ==> %s\n", l, *(s + l));
    buff = *(s + k);
    *(s + k) = *(s + l);
    *(s + l) = buff;
    // Step 4: Reverse the sequence from a[k + 1] up to and including the final element a[n].
    pos_mid = (n + k) / 2;
    // printf("pos_mid = %d ==> %s\n", pos_mid, *(s + pos_mid));
    for (int i=1; (k+i)<=pos_mid; i++) {
        // printf("Swapping: %s & %s\n", *(s + k + i), *(s + n - i));
        buff = *(s + k + i);
        *(s + k + i) = *(s + n - i);
        *(s + n - i) = buff;
    }
    return 1;
}
