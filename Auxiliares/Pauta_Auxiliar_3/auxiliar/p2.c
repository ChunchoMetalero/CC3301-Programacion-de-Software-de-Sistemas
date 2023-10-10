#include "string.h"
#include <stdio.h>

int palindromo(char* s);

int palindromo(char* s) {
    char *p = s + strlen(s) - 1;
    while(s < p) {
        if (*s != *p) 
            return 0;
        s++;
        p--;
    }
    return 1;
}

int main(int argc, char *argv[]) {
    char test[] = "somos";
    char test2[] = "hola";

    int res1 = palindromo(test);
    printf("%s es un palindromo?: %d\n", test, res1);

    int res2 = palindromo(test2);
    printf("%s es un palindromo?: %d\n", test2, res2);
}