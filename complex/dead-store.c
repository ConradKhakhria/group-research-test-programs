#include <stdio.h>
#include <stdlib.h>


struct Complex {
    float real;
    float imag;
};


struct Complex* complex_init(float r, float i) {
    struct Complex* c = malloc(sizeof(*c));

    if (c) {
        c->real = r;
        c->imag = i;
    }

    return c;
}


void add_to(struct Complex* z, struct Complex* o) {
    z->real += o->real;
    z->imag += o->imag;
}


int main() {
    struct Complex* z1 = complex_init(3.0, 4.0);
    struct Complex* z2 = complex_init(1.0, 1.0);

    add_to(z1, z2);

    printf("z1 now = %f + %fi", z1->real, z1->imag);

    free(z1);
    free(z2);
}
