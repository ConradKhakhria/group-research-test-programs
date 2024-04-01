#include <stdio.h>
#include <stdlib.h>


struct Complex {
    float real;
    float imag;
};


struct Complex* init_complex(int r, int i) {
    struct Complex* z = malloc(sizeof(*z));

    if (z) {
        z->real = r;
        z->imag = i;
    }

    return z;
}


struct Complex* add_complex(struct Complex* x, struct Complex* y) {
    return init_complex(x->real + y->real, x->imag + y->imag);
}


int main() {
    struct Complex* z1 = init_complex(2, 2);
    struct Complex z2;

    z2.real = 5;

    if (!z1)
        exit(EXIT_FAILURE);

    struct Complex* sum = add_complex(z1, &z2);

    if (!sum)
        exit(EXIT_FAILURE);

    printf("res = %f+%fi\n", sum->real, sum->imag);

    free(z1);
    free(sum);
}
