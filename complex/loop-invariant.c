#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void bubblesort(int* xs, int len) {
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            // Foolishly swapping elements without a temporary variable
            if (xs[j] > xs[j + 1]) {
                xs[j] = xs[j] + xs[j + 1];
                xs[j + 1] = xs[j] - xs[j + 1];
                xs[j] = xs[j] - xs[j + 1];
            }
        }
    }
}


int main() {
    int xs[100];
    srand(time(NULL));

    for (int i = 0; i < 100; i++)
        xs[i] = rand();

    bubblesort(xs, 100);
}
