#include <stdio.h>
#include <stdlib.h>


int count_lines(char* buf, int length) {
    int c = 0;

    for (int i = 0; i < length; i++) {
        if (buf[i] == '\n') c++;
    }

    return c;
}


int main(int argc, char* argv[]) {
    char buf[1000];
    int i = 0;

    if (argc < 2)
        exit(EXIT_FAILURE);

    FILE* f = fopen(argv[1], "r");

    if (!f)
        exit(EXIT_FAILURE);

    while ((buf[i++] = fgetc(f)) != EOF);

    fclose(f);

    printf("lines = %d\n", count_lines(buf, i));
}
