#include <stdio.h>
#include <stdlib.h>


int main() {
    int* a = malloc(sizeof(int));

    *a = 4;

    printf("%d\n", *a);
    free(a);
}
