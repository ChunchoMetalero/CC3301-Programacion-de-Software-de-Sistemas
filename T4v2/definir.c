#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "pss.h"

//... define variables globales o funciones adicionales ...

void definir(char *nom_dic, char *palabra, char *def){
  // Abrimos el archivo 
  FILE *f = fopen(nom_dic, "r+");
  int n = 0;
  char *space = " ";


  //Guardamos un buffer para leer la primera palabra
  char buf[n+1];
  buf[n] = 0; 
  while (fgets(buf, n+1, f)) {
    if (strcmp(buf, space) > 0) {
      fputs(palabra,f);
      fputc(58,f);
      fputs(def,f);
      break;
    }
    fseek(f, 80-n, SEEK_CUR);
  }
  fclose(f);
}

int main(int argc, char *argv[]) {
  //... programe aca su solucion ...
  if (argc != 4) {
        printf("Uso: %s <diccionario> <palabra> <definicion>\n", argv[0]);
        return 1;
    }
  definir(argv[1], argv[2], argv[3]);
}