#include <stdio.h>
#include <stdlib.h>


int main() {
    int* a = malloc(sizeof(int));

    if (a) {
        *a = 4;

        printf("%d\n", *a);

        free(a);
        free(a);
    }
}
