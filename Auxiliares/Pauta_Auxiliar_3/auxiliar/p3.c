#include "string.h"
#include "stdio.h"

void reverse(char *s);

void reverse(char *s) {
    char *p = s + strlen(s) - 1;
    while (s < p) {
        char tmp = *s;
        *s = *p;
        *p = tmp;
        s++;
        p--;
    }
}

int main(int argc, char *argv[]) {
    char test[] = "dinosaurio";

    reverse(test);
    printf("%s\n", test);
}