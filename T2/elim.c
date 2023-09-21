#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "elim.h"

void eliminar(char *str, char *pat) {
  char *str1 = str; // Puntero a str
  char *str2 = pat; // Puntero a pat
  char *str3 = str; // Puntero pre reemplazo
  int contador = 0;
  int largePat = strlen(pat);

  while(*str1 != '\0') {
    if(*str1 == *str2){
      while((((*str1) == (*str2)) && (*str2) != '\0')) {
        str1++;
        str2++;
        contador++;
        }
      if(contador == largePat) {
        if(*str1 == '\0') {
          break;
        }
      }
      else{
        str1 -= contador;
        *str = *str1;
        str1++;
        str++;
      }
    }
      
    else{
      *str = *str1;
      str1++;
      str++;
    }
    contador = 0;
    str2 = pat;
  }
*str = '\0';
str = str3;
}



char *eliminados(char *str, char *pat) {
  int lenstr = strlen(str);
  char *copy = malloc(lenstr+1);
  strcpy(copy, str);
  eliminar(copy,pat);
  char *resp = malloc(strlen(copy) + 1);
  strcpy(resp, copy);
  free(copy);
  return resp;
}

   
//int main() {
//    char s1[] = "las palas van"; // pa van
//    char s2[] = "111011001"; // 11101
//    char s3[] = "abccbdddbeeeeb"; // accdddeeee
//    
//    // Parte a: Eliminar el patrón del string original
//    eliminar(s1, "las");
//    eliminar(s2, "10");
//    eliminar(s3, "b");
//    
//    printf("Resultado de eliminar (Parte a):\n");
//    printf("s1: %s\n", s1);
//    printf("s2: %s\n", s2);
//    printf("s3: %s\n", s3);
//
//}