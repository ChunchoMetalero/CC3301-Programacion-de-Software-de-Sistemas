#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "pss.h"



int completooo(char *nom_dic) {
  FILE *f = fopen(nom_dic, "r+");
  char buf[81];

  fseek(f, 0, SEEK_END);
  int lineas = ftell(f)/81;
  printf("El valor de lineas es: %d\n", lineas);
  int i = 0;
  fseek(f, 0, SEEK_SET);
  while (fgets(buf, 81, f)) {
    char firstchar = fgetc(f);
    fseek(f, -1, SEEK_CUR);
    if (firstchar == ' ') {
      i++;
      fseek(f, 80, SEEK_CUR);
    }
    else {
      fseek(f, 80, SEEK_CUR);
    }
  }
  fclose(f);
  printf("El valor de i es: %d\n", i);
  if (i == 0) {
    return 1;
  }
  else{
    return 0;
  }
}

int main(int argc, char *argv[]) {
  if (argc != 4) {
        fprintf(stderr, "Uso: ./definir <diccionario> <llave> <definicion>\n");
        exit(1);
    }
  else{  
    int x = completooo(argv[1]);
    printf("%d\n", x);}
}