#include <stdio.h>

void to_lower(char* s);
void to_upper(char* s);

void to_lower(char* s) {
    while(*s) {
        if (*s >= 'A' && *s <= 'Z')
            *s += 'a' - 'A';
        s++;
    }
    return;
}

void to_upper(char* s) {
    while(*s) {
        if (*s >= 'a' && *s <= 'z')
            *s -= 'a' - 'A';
        s++;
    }
    return;
}

int main(int argc, char *argv[]) {
    char test[] = "cHanCHo";
    char test2[] = "cHanCHo";

    to_lower(test);
    printf("%s\n", test);

    to_upper(test2);
    printf("%s\n", test2);
}