#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "elim.h"

void eliminar(char *str, char *pat) {
  char *str2 = str; // Puntero que recorre el string
  char *str3 = pat; // Puntero que recorre el patron
  char *str4 = str; // Puntero pre reemplazo
  int contador = 0;

  while (*str2 != '\0') {
    if (*str2 == *str3) {
      str2++; // Avanzo el puntero del string
      str3++; // Avanzo el puntero del patron
      contador++; // Cuento cuantos caracteres coinciden
      if(*str3 =='\0') { // Si llego al final del patron
        str2 = str4; 
        str3 = pat;
        while (*str2 != '\0') {
          *str2 = *(str2 + contador);
          str2++;
        }
        *str2 = '\0';
        str2 = str4;
        str3 = pat;
      }
    }
    else {
      str2++;
      str3 = pat;
      str4++;
      contador = 0;
    }
  } 
}


char *eliminados(char *str, char *pat) {
    char*res = malloc(strlen(str)+1);
    strcpy(res,str);
    eliminar(res,pat);
    return res;
    }
   
   
int main() {
    char s1[] = "las palas van"; // pa van
    char s2[] = "111011001"; // 11101
    char s3[] = "abccbdddbeeeeb"; // accdddeeee
    
    // Parte a: Eliminar el patrón del string original
    eliminar(s1, "las");
    eliminar(s2, "10");
    eliminar(s3, "b");
    
    printf("Resultado de eliminar (Parte a):\n");
    printf("s1: %s\n", s1);
    printf("s2: %s\n", s2);
    printf("s3: %s\n", s3);

}


int lenstr = strlen(str);

  char *copy = malloc(lenstr+1);
  strcpy(copy, str);

  eliminar(copy,pat);

  char *resp = malloc(strlen(copy) + 1);
  strcpy(resp, copy);

  free(copy);
  return resp;