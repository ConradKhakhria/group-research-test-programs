#include <stdio.h>
#include <stdlib.h>

#define PARENT(i)       ((i - 1) / 2)
#define LEFT_CHILD(i)   (2*i + 1)
#define RIGHT_CHILD(i)  (2*i + 2)


struct Heap {
    int* elements;
    size_t count;
};


struct Heap* heap_init() {
    struct Heap* h = malloc(sizeof(*h));

    if (h) {
        h->count = 0;
        h->elements = calloc(100, sizeof(int));
    
        if (!h->elements) {
            free(h);
            h = NULL;
        }
    }

    return h;
}


void heap_insert(struct Heap* h, int value) {
    int index = h->count++;
    h->elements[index] = value;

    while (h->elements[PARENT(index)] > h->elements[index]) {
        int tmp = h->elements[index];
        h->elements[index] = h->elements[PARENT(index)];
        h->elements[PARENT(index)] = tmp;
        index = PARENT(index);
    }
}


int heap_pop(struct Heap* h) {
    int index = 0;
    int res = h->elements[index];
    h->elements[index] = h->elements[h->count--];

    while (1) {
        if (h->elements[index] < h->elements[LEFT_CHILD(index)]
        &&  h->elements[index] < h->elements[RIGHT_CHILD(index)]) {
            break;
        }

        if (h->elements[LEFT_CHILD(index)] < h->elements[RIGHT_CHILD(index)]) {
            int tmp = h->elements[index];
            h->elements[index] = h->elements[LEFT_CHILD(index)];
            h->elements[LEFT_CHILD(index)] = tmp;
            index = LEFT_CHILD(index);
        } else {
            int tmp = h->elements[index];
            h->elements[index] = h->elements[RIGHT_CHILD(index)];
            h->elements[RIGHT_CHILD(index)] = tmp;
            index = RIGHT_CHILD(index);
        }
    } 

    return res;
}


int main() {
    int vals[10] = {5, 2, 4, 6, 7, 1, 5, 23, 9, 1};
    struct Heap* h = heap_init();

    if (!h)
        exit(EXIT_FAILURE);
    
    for (int i = 0; i < 10; i++)
        heap_insert(h, vals[i]);

    for (int i = 0; i < 10; i++)
        printf("- %d\n", heap_pop(h));
}
