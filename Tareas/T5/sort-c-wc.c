#include <string.h>

int strCmp(char *s1, char *s2) {
    char c1;
    char c2;

    for (;;) {
      c1= *s1;
      c2= *s2;

      if (c1==0)
        break;

      if (c1!=c2)
        break;

      s1++;
      s2++;
    }

    return c1 - c2;
}

int countWords(char *str1) {
  int count = 0;
  int i = 0;
  
  while (str1[i] != '\0') {
    if (str1[i] == ' ') {
      // Saltar espacios en blanco
      i++;
    } else {
      // Encontró una palabra
      count++;
      while (str1[i] != ' ' && str1[i] != '\0') {
        i++;
      }
    }
  }
  return count;
}



void sort(char **a, int n) {
  char **ult= &a[n-1];
  char **p= a;
  while (p<ult) {

    int t1= countWords(p[0])- countWords(p[1]);

    if (t1 <= 0)
      p++;
    else {
      char *tmp= p[0];
      p[0]= p[1];
      p[1]= tmp;
      p= a;
    }
  }
}
