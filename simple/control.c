#include <stdio.h>
#include <stdlib.h>


int* fibonacci_sequence(int n) {
    int* seq = malloc(sizeof(int) * n);

    if (seq) {
        seq[0] = 1;
        seq[1] = 1;

        for (int i = 2; i < n; i++)
            seq[i] = seq[i - 1] + seq[i - 2];
    }

    return seq;
}


int main() {
    int* seq = fibonacci_sequence(10);

    if (seq) {
        for (int i = 0; i < 10; i++) {
            printf("element %d = %d\n", i, seq[i]);
        }
    }

    free(seq);
}