#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct IntVector {
    int* vs;
    size_t size;
    size_t length;
};


struct IntVector* intvector_init() {
    struct IntVector* v = malloc(sizeof(*v));

    if (v) {
        v->size = 100;
        v->length = 0;
        v->vs = calloc(100, sizeof(int));

        if (v->vs == NULL) {
            free(v);
            return NULL;
        }
    }

    return v;
}


void intvector_append(struct IntVector* v, int i) {
    if (!v)
        return;

    if (v->length + 1 == v->size) {
        v->size += 100;
        int* new = realloc(v->vs, v->size);

        if (new) {
            free(v->vs);
            v->vs = new;
        }
    }

    v->vs[v->length++] = i;
}


int main() {
    struct IntVector* v = intvector_init();

    if (!v)
        exit(EXIT_FAILURE);

    for (int i = 0; i < 2000; i++)
        intvector_append(v, i);

    printf("final: %d\n", v->vs[v->length - 1]);
}
