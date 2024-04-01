#include <stdio.h>


int* first_five_divisors(int n) {
    int divisors[5] = {0, 0, 0, 0, 0};
    int idx = 0;

    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            divisors[idx++] = i;
        }

        if (idx == 5)
            break;
    }

    return divisors;
}


int main() {
    int* divisors = first_five_divisors(36);

    for (int i = 0; i < 5; i++)
        printf("- %d\n", divisors[i]);
}
