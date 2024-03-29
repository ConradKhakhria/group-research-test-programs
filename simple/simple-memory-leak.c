#include <stdlib.h>


int main() {
    int* xs = malloc(10 * sizeof(int));

    if (xs)
        xs[4] = 4;
}
