#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "elim.h"

void eliminar(char *str, char *pat) {
  char *str1 = str; // Puntero a str
  char *str2 = pat; // Puntero a pat
  int lenpat = strlen(pat); // Largo del patrón
  int contador;  // Contador de caracteres
  
  while(*str1 != '\0') { // Mientras no llegue al final del string
    contador = 0; // Resetea el contador
    str2 = pat; // Resetea el puntero del patrón
    if(*str1 == *str2) { // Si el caracter es igual al primer caracter del patrón
      while((((*str1) == (*str2)) && (*str2) != '\0')) { // Mientras los caracteres sean iguales y no llegue al final del patrón
        str1++; // Avanza el puntero del string
        str2++; // Avanza el puntero del patrón
        contador++; // Aumenta el contador
      }
      if(contador != lenpat) { // Si el contador es igual al largo del patrón
        str1 -= contador; // Retrocede el puntero del string
        *str = *str1; // Copia el caracter en el string
        str1++; // Avanza el puntero del string
        str++; // Avanza el puntero del string
      }
    }
      
    else { // Si el caracter no es igual al primer caracter del patrón
      *str = *str1; // Copia el caracter en el string
      str1++; // Avanza el puntero del string
      str++; // Avanza el puntero del string
    }
  }
  *str = '\0'; // Agrega el caracter nulo al final del string
}

char *eliminados(char *str, char *pat) { 
  char*res = malloc(strlen(str)+1); // Reserva memoria para el string
  strcpy(res, str); // Copia el string en res
  eliminar(res, pat); // Elimina el patrón del string
  char*res2 = malloc(strlen(res)+1); // Reserva memoria para el string
  strcpy(res2, res); // Copia el string en res2
  free(res); // Libera la memoria de res
  return res2; // Retorna el string
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