#include "string.h"
#include "stdio.h"

char mas_repetido(char *s);

char mas_repetido(char *s) {
    int cnt[256] = {0};
    for (int i = 0; i < strlen(s); i++)
        cnt[s[i]]++;
    char max = 0;
    for (int i = 0; i < 256; i++) {
        if (cnt[i] > cnt[max])
            max = (char) i;
    }
    return max;
}

int main(int argc, char *argv[]) {
    char test[] = "dinosauri";

    char max = mas_repetido(test);
    printf("%c\n", max);
}