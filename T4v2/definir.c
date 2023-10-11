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
}

int esta_en_diccionario(char *nom_dic, char *palabra) {
  // Abrimos el archivo 
  FILE *f = fopen(nom_dic, "r+");
  int on = 0;
  
  char buf[80+1];
  while(fread(buf, 1, 80, f) > 0){
    char *c = buf;
    while(*c != ':'){
      c++;
    }
    *c = '\0';
    if(strcmp(palabra, buf) == 0){
      // son iguales! encontramos la línea
      fseek(f, -80+strlen(palabra)+1, SEEK_CUR);
      
      while(fgetc(f) != ':'){
        fseek(f, -1, SEEK_CUR);
      }
      on = 1;
    
    }
  }
  return on;
  fclose(f);
}


void definir(char *nom_dic, char *palabra, char *def){
  // Abrimos el archivo 
  FILE *f = fopen(nom_dic, "r+");
  int n = 80;
  char buf[n+1];

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
  else if (esta_en_diccionario(nom_dic, palabra) == 1) {
    // Si no esta vacio, revisamos si es la misma palabra
    printf("La llave %s ya se encuentra en el diccionario", palabra);
  }
  else{
    while (fgets(buf, n+1, f)) {
      fseek(f, -n, SEEK_CUR);
      char firstchar = fgetc(f);
      fseek(f, -1, SEEK_CUR);
      if (firstchar == ' ') {
        fputs(palabra,f);
        fputc(58,f);
        fputs(def,f);
        break;
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
        printf("Uso: %s <diccionario> <palabra> <definicion>\n", argv[0]);
        return 1;
    }
  else if (f == NULL) {
    perror("Error al abrir el archivo");
  }
  else {
    fclose(f);
    definir(argv[1], argv[2], argv[3]);
  }
}