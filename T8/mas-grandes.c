#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdarg.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "pss.h"
       
// Defina aca la estructura para guardar nombre y tamanno

// Agregue aca las funciones y variables globales adicionales que necesite

typedef struct 
{
  char *nombre;
  int tamano;
} Archivo;

Queue *q;

int cmpTamano(void *ptr, int i, int j) {
  Archivo **a= ptr;
  if (a[i]->tamano == a[j]->tamano){
    return strcmp(a[j]->nombre, a[i]->nombre);
  }
  else {
    return a[i]->tamano - a[j]->tamano;
  }
}

void masGrandes(char *nom, int n) {
  struct stat st_nom;
  int rc;
  rc= stat(nom, &st_nom);

  if (rc!=0) {
    exit(0);
  }

  else if (S_ISDIR(st_nom.st_mode)) {
    DIR *dir = opendir(nom);
    if (dir == NULL) {
      perror(nom);
      exit(1);
    }
    for (struct dirent *entry = readdir(dir);
         entry != NULL;
         entry = readdir(dir)) {
      if (strcmp(entry->d_name, ".")==0 || strcmp(entry->d_name, "..")==0) {
        continue;
      }
      char *nom_arch= malloc(strlen(nom)+strlen(entry->d_name)+2);
      strcpy(nom_arch, nom);
      strcat(nom_arch, "/");
      strcat(nom_arch, entry->d_name);
      masGrandes(nom_arch, n);
      free(nom_arch);
    }
    closedir(dir);
  }
  else {
    Archivo *file = malloc(sizeof(Archivo));
    file->nombre = strdup(nom);
    file->tamano = st_nom.st_size;
    put(q, file);
  }
}

int main(int argc, char *argv[]) {
  if (argc!=3) {
    fprintf(stderr, "uso: %s <arch|dir>\n", argv[0]);
    exit(1);
  }
  int n = atoi(argv[2]);
  q = makeQueue();
  masGrandes(argv[1], atoi(argv[2]));
  int largo = queueLength(q);
  Archivo *Array[largo];
  for (int i = 0; i < largo; i++) {
    Array[i] = get(q);
  }
  sortPtrArray(Array, 0, largo-1, cmpTamano);
  for (int i = 0; i < largo; i++) {
    while(i < n) {
      printf("%s %d\n", Array[largo - 1 - i]->nombre, Array[largo - 1 - i]->tamano);
      free(Array[i]->nombre);
      free(Array[i]);
      i++;
    }
    free(Array[i]->nombre);
    free(Array[i]);
  }
  return 0;
  // ... complete ...
}
