#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* string_concat(char* a, char* b) {
    size_t length = strlen(a) + strlen(b);
    char* new_string = calloc(length + 1, sizeof(char));

    if (new_string == NULL)
        return NULL;

    sprintf(new_string, "%s%s", a, b);

    free(a);
    free(b);

    return new_string;
}


int main() {
    char* s1 = calloc(6, sizeof(char));
    char* s2 = calloc(6, sizeof(char));

    if (s1 == NULL || s2 == NULL)
        exit(-1);

    sprintf(s1, "hello");
    sprintf(s2, "world");

    char* perm1 = string_concat(s1, s2);
    char* perm2 = string_concat(s2, s1);

    if (perm1 && perm2)
        printf("%s\n%s\n", perm1, perm2); 

    free(perm1);
    free(perm2);
}
