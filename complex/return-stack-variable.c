#include <stdio.h>
#include <stdlib.h>
#include <time.h>


float** random_matrix() {
    float M[10][10];
    srand(time(NULL));

    for (int r = 0; r < 10; r++) {
        for (int c = 0; c < 10; c++) {
            M[r][c] = rand();
        }
    }

    // Allocate
    float** ret = malloc(10 * sizeof(float *));

    for (int i = 0; i < 10; i++)
        ret[i] = M[i];

    return ret;
}


int main() {
    float** M = random_matrix();

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++)
            printf("%f ", M[i][j]);

        printf("\n");
    }
}

