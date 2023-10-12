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

int completo(char *nom_dicc){
    FILE *f = fopen(nom_dicc, "r+");
    char buf[81];
    fseek(f, 0, SEEK_END);
    int lineas = ftell(f)/81;
    int j = 0;
    int i = 0;
    int linea = 0;
    fseek(f, 0, SEEK_SET);
    while (j< lineas) {
      if (i>0) {
        break;
      }
      else{
        //leemos la linea
        fread(buf, 1,81, f);
        //movemos el puntero al inicio de la linea
        fseek(f, linea*81, SEEK_SET);
        // Aumentamos el contador
        j++;
        // Obtenemos Primer caracter
        char firstchar = buf[0];
        // Devolvemos el puntero
        fseek(f, -1, SEEK_CUR);
        // Si es un espacio, entonces la linea esta vacia.
        if (firstchar == ' ') {
            i++;
        }
        // Aumentamos el contador de linea
        linea++; 
      }         
    }
    // Cerramos el archivo
    fclose(f);
    // Revisamos si habian espacios o no
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
  fseek(f, 0, SEEK_END);
  int lineas = ftell(f)/81;
  fseek(f, 0, SEEK_SET);
  char buf[n+1];
  char *esta_en;
  int large = strlen(palabra);
  int j = 0;

  fseek(f, nhash(nom_dic, palabra)*81, SEEK_SET);
  fread(buf, 1, 1, f);
  char firstchar2 = buf[0];
  fseek(f, -1, SEEK_CUR);
  
  if (firstchar2 == ' ') {
    fputs(palabra,f);
    fputc(58,f);
    fputs(def,f);
    fclose(f);
    return;
  } 
  else{
    fseek(f, 81, SEEK_CUR);
    while (j < lineas) {
      j++;
      fread(buf, 1, 1, f);
      char firstchar = buf[0];
      fseek(f, -1, SEEK_CUR);
      fread(buf, 1, large, f);
      buf[large] = '\0';
      esta_en = buf;
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