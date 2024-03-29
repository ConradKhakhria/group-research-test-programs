#include <stdio.h>
#include <stdlib.h>


int main(int argc, char* argv[]) {
    char* buf = malloc(sizeof(char) * 1000);
    int buf_size = 1000;
    int index = 0;

    if (!buf || argc < 2)
        exit(EXIT_FAILURE);

    FILE* f = fopen(argv[1], "r");

    while ((buf[index++] = fgetc(f)) != EOF) {
        if (index == buf_size) {
            buf_size += 1000;
            char* tmp = realloc(buf, buf_size);

            if (tmp)
                buf = tmp;
        }
    }

    printf("File has %d characters\n", index);
    free(buf);
}
