#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "pss.h"

//... define variables globales o funciones adicionales ...

int nhash(char *nom_dic, char *palabra) {
  FILE *f = fopen(nom_dic, "r+");
  fseek(f, 0, SEEK_END);
  int lineas = ftell(f)/81;
  int linea = hash_string(palabra) % lineas;
  fclose(f);
  return linea;
  printf("%d\n", linea);
}

int completo(char *nom_dic) {
  FILE *f = fopen(nom_dic, "r+");
  char buf[81];
  fseek(f, 0, SEEK_END);
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
  if (i == 0) {
    return 1;
  }
  else{
    return 0;
  }
}

void definir(char *nom_dic, char *palabra, char *def){
  // Abrimos el archivo 
  FILE *f = fopen(nom_dic, "r+");
  int n = 80;
  char buf[n+1];
  char *esta_en;
  int large = strlen(palabra);

  fseek(f, nhash(nom_dic, palabra)*81, SEEK_SET);
  char firstchar2 = fgetc(f);
  fseek(f, -1, SEEK_CUR);
  if (firstchar2 == ' ') {
    fputs(palabra,f);
    fputc(58,f);
    fputs(def,f);
    fclose(f);
    return;
  } 
  else{
    while (fgets(buf, n+1, f)) {
      fseek(f, -n, SEEK_CUR);
      char firstchar = fgetc(f);
      fseek(f, -1, SEEK_CUR);
      esta_en = fgets(buf, large+1, f);
      fseek(f, -large, SEEK_CUR);
      if (firstchar == ' ') {
        fputs(palabra,f);
        fputc(58,f);
        fputs(def,f);
        break;
      }
      else if (strcmp(esta_en, palabra) == 0) {
        fprintf(stderr, "La llave %s ya se encuentra en el diccionario\n", palabra );
        exit(1);
      }
      else{
        fseek(f, 80, SEEK_CUR);
      }
    }
  }
  fclose(f);
}


int main(int argc, char *argv[]) {
  //... programe aca su solucion ...
  FILE *f = fopen(argv[1], "r+");
  if (argc != 4) {
        fprintf(stderr, "Uso: ./definir <diccionario> <llave> <definicion>\n");
        exit(1);
    }
  else if (f == NULL) {
    perror(argv[1]);
    exit(1);
  }
  else if (completo(argv[1]) == 1) {
    fprintf(stderr, "%s: el diccionario esta lleno\n",argv[1]);
    exit(1);
  }
  else {
    fclose(f);
    definir(argv[1], argv[2], argv[3]);
  }
}