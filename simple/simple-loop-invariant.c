#include <stdio.h>
#include <stdlib.h>


int my_pow(int n, int r) {
    volatile int res = 1;

    for (int i = 1; i < r; i++)
        res *= n;

    return res;
}


int main() {
    int xs[10] = {5, 3, 6, 4, 7, 8, 2, 10, 1};

    for (int i = 0; i < 10; i++)
        xs[i] *= xs[i] + my_pow(10, 15);

    printf("%d\n", xs[0]);
}
