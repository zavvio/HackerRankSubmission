// https://www.hackerrank.com/challenges/printing-pattern-2
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int n, pos_mid, size, offset_low, offset_high;
    int **grid;
    scanf("%d", &n);
    size = (n * 2) - 1;
    pos_mid = n - 1;
    
    grid = (int **) malloc(size * sizeof(int *));
    for (int i=0; i<size; i++) {
        *(grid + i) = (int *) malloc(size * sizeof(int));
    }
    grid[pos_mid][pos_mid] = 1;
    for (int i=2; i<=n; i++) {
        offset_low = pos_mid - (i - 1);
        offset_high = pos_mid + (i - 1);
        for (int j=offset_low; j<=offset_high; j++) {
            grid[offset_low][j] = i;
            grid[offset_high][j] = i;
            grid[j][offset_low] = i;
            grid[j][offset_high] = i;
        }
    }
    for (int i=0; i<size; i++) {
        for (int j=0; j<size; j++) {
            printf("%d", grid[i][j]);
            if (j < size - 1)
                printf(" ");
        }
        printf("\n");
    }
    
    for (int i=0; i<size; i++) {
        free(*(grid + i));
    }
    free(grid);
    // Complete the code to print the pattern.
    
    return 0;
}
