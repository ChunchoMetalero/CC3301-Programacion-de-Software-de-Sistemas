#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "elim.h"

void eliminar(char *str, char *pat) {
  int x = strlen(str);
  int y = strlen(pat);
  char *str2 = str;
  str2 = str2 + y;
  *str2 = '\0'; 
  printf(str2);
  printf("\n");
  int z = *str2;
  printf("el valor es %d", z);
  while (0 < x) {
    if (str == pat)
    {
      
    }
    
    x--;
  }
  
  
  

  }

  


char *eliminados(char *str, char *pat) {
  
}

int main(int argc, char const *argv[])
{
  eliminar("las palas van", "las");
  return 0;
}
