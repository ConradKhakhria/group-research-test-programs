#include <stdio.h>
#include <stdlib.h>


void increment(int* a) {
    *a += 1;
}


int main() {
    int* a = malloc(sizeof(*a));

    *a = 0;
    increment(a);

    printf("%d\n", *a);
    free(a);
}
