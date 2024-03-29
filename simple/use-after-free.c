#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    char* s = calloc(100, sizeof(char));

    if (!s)
        exit(EXIT_FAILURE);

    strcpy(s, "hello world\n");
    free(s);

    printf("%s\n", s);
}
