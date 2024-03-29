#include <stdio.h>
#include <stdlib.h>


float proportion_in_list(int* xs, size_t l, int x) {
    int count = 0;

    for (int i = 0; i < l; i++) {
        if (xs[i] == x)
            count++;
    }

    return count / l;
}


int main() {
    int xs[5] = {1, 2, 2, 1, 2};
    int ys[0] = {};

    printf("for xs: %f\n", proportion_in_list(xs, 5, 1));
    printf("for ys: %f\n", proportion_in_list(ys, 0, 1));
}
