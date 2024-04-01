#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void memory_error() {
    fprintf(stderr, "Failed to allocate memory\n");
    exit(EXIT_FAILURE);
}


int* quicksort(int* xs, int len) {
    if (len == 0) {
        return NULL;
    } else if (len == 1) {
        int* res = malloc(sizeof(int));

        if (!res)
            memory_error();

        res[0] = xs[0];

        return res;
    }

    int* lower = malloc(len * sizeof(int));
    int* upper = malloc(len * sizeof(int));

    if (!lower || !upper)
        memory_error();

    int lc = 0;
    int uc = 0;

    for (int i = 1; i < len; i++) {
        if (xs[i] < xs[0]) {
            lower[lc++] = xs[i];
        } else {
            upper[lc++] = xs[i];
        }
    }

    int* s_lower = quicksort(lower, lc);
    int* s_upper = quicksort(upper, lc);
    int* result  = malloc(len * sizeof(int));

    if (!result)   
        memory_error();

    for (int i = 0; i < lc; i++)
        result[i] = s_lower[i];

    result[lc] = xs[0];

    for (int i = 0; i < uc; i++)
        result[i + lc + 1] = s_upper[i];

    free(lower);
    free(upper);
    free(s_lower);
    free(s_upper);

    return result;
}


int main() {
    int data[1000];
    srand(time(NULL));

    for (int i = 0; i < 1000; i++)
        data[i] = rand();

    int* sorted = quicksort(data, 1000);

    for (int i = 1; i < 1000; i++) {
        if (data[i - 1] > data[i]) {
            printf("The sort didn't work!\n");
        }
    }

    free(sorted);
}
