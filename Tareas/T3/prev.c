#include <stddef.h>

#include "prev.h"


void asignarPrev(Nodo *t, Nodo **pprev) {
  if (t == NULL) return;
  else {
    asignarPrev(t->izq, pprev); 
    t->prev = *pprev; 
    if(*pprev != NULL) { 
      (*pprev)->prox = t; 
    } 
    *pprev = t; 
    if (*pprev == t) { 
      t->prox = NULL; 
    }
    asignarPrev(t->der, pprev); 
  }
}