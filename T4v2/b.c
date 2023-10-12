#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "pss.h"



int lectura(char *nom_dicc){
    FILE *f = fopen(nom_dicc, "r+");
    char buf[81];
    fseek(f, 0, SEEK_END);
    int lineas = ftell(f)/81;
    int j = 0;
    int i = 0;
    int linea = 0;
    fseek(f, 0, SEEK_SET);
    while (j< lineas) {
        //leemos la linea
        fread(buf, 1,81, f);
        //movemos el puntero al inicio de la linea
        fseek(f, linea*81, SEEK_SET);
        // Aumentamos el contador
        j++;
        // Obtenemos Primer caracter
        char firstchar = fgetc(f);
        printf("El valor de firstchar es: %c\n", firstchar);
        // Devolvemos el puntero
        fseek(f, -1, SEEK_CUR);
        // Si es un espacio, entonces la linea esta vacia.
        if (firstchar == ' ') {
            i++;
        }
        // Aumentamos el contador de linea
        linea++;        
    }
    // Cerramos el archivo
    fclose(f);
    // Revisamos si habian espacios o no
    printf("El valor de i es: %d\n", i);
    if (i == 0) {
        return 1;
    }
    else{
        return 0;
    }
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