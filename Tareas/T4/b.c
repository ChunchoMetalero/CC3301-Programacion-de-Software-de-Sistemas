#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "pss.h"



int lectura(char *nom_dicc){
    FILE *f = fopen(nom_dicc, "r+");
    char buf[100];
    int largeline = 0;
    while (buf[0] != '\n') {
        largeline++;
        fread(buf, 1,1, f);
    }
    return largeline;
}



int main(int argc, char *argv[]) {
  if (fopen(argv[1], "r+") == NULL) {
        fprintf(stderr, "Uso: ./definir <diccionario> <llave> <definicion>\n");
        exit(1);
    }
  else{  
    int x = lectura(argv[1]);
    printf("%d\n", x);}
}