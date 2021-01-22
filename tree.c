#include "stdlib.h"
#include "stdio.h"
#include "string.h"


typedef struct Arbol{
    char *esp;
    char *ing;
    int peso;
    struct Arbol *izquierdo;
    struct Arbol *derecho;
} arbol;

arbol *crearArbol(char *esp, char *ing){
    arbol *a = malloc(sizeof(arbol));
    // inicializamos valores
    a->esp = malloc(sizeof(esp));
    strcpy(a->esp, esp);
    a->ing = malloc(sizeof(ing));
    strcpy(a->ing, ing);

    a->izquierdo = NULL;
    a->derecho = NULL;
    a->peso = 1;
    return a;
}

int height(arbol *a) {
  if (a == NULL)
    return 0;
  return a->peso;
}

int max(int a, int b) {
  return (a > b) ? a : b;
}

arbol *derechoRotate(arbol *y) {
  arbol *x = y->izquierdo;
  arbol *T2 = x->derecho;

  x->derecho = y;
  y->izquierdo = T2;

  y->peso = max(height(y->izquierdo), height(y->derecho)) + 1;
  x->peso = max(height(x->izquierdo), height(x->derecho)) + 1;

  return x;
}

// izquierdo rotate
arbol *izquierdoRotate(arbol *x) {
  arbol *y = x->derecho;
  arbol *T2 = y->izquierdo;

  y->izquierdo = x;
  x->derecho = T2;

  x->peso = max(height(x->izquierdo), height(x->derecho)) + 1;
  y->peso = max(height(y->izquierdo), height(y->derecho)) + 1;

  return y;
}

int getBalanceFactor(arbol *a) {
  if (a == NULL)
    return 0;
  return height(a->izquierdo) - height(a->derecho);
}


arbol *agregarHoja(arbol *a, char *esp, char *ing){
    if(a == NULL){
        return crearArbol(esp, ing);
    }
    if(strcmp(a->esp, esp) < 0){
        a->derecho = agregarHoja(a->derecho, esp, ing);
    }
    else if(strcmp(a->esp, esp) > 0){
        a->izquierdo = agregarHoja(a->izquierdo, esp, ing);
    }else {
        return a;
    }
    a->peso = 1 + max(height(a->izquierdo),height(a->derecho));
    int balanceFactor = getBalanceFactor(a);
    if (balanceFactor > 1) {
        if (strcmp(esp,a->izquierdo->esp) < 0) {
            return derechoRotate(a);
        } else if (strcmp(esp, a->izquierdo->esp) > 0) {
            a->izquierdo = izquierdoRotate(a->izquierdo);
            return derechoRotate(a);
        }
    }
    if (balanceFactor < -1) {
        if (strcmp(esp,a->derecho->esp) > 0) {
            return izquierdoRotate(a);
    } else if (strcmp(esp,a->derecho->esp) < 0) {
        a->derecho = derechoRotate(a->derecho);
        return izquierdoRotate(a);
        }
    }
    return a;
}

arbol *agregarHojaIngles(arbol *a, char *esp, char *ing){
    if(a == NULL){
        return crearArbol(esp, ing);
    }
    if(strcmp(a->ing, ing) < 0){
        a->derecho = agregarHojaIngles(a->derecho, esp, ing);
    }
    else{
        a->izquierdo = agregarHojaIngles(a->izquierdo, esp, ing);
    }
    return a;
}



arbol *rellenarArbol(int flag){
    FILE *fptr;
    char *esp = malloc(1024 * sizeof(char));
    char *ing = malloc(1024 * sizeof(char));
    arbol *a = NULL;
    fptr = fopen("entrada.in", "r");
    while (fscanf(fptr,"%s %s",esp, ing) != EOF){
        // printf("%s  %s \n", esp, ing);
        if(flag){
            a = agregarHoja(a, esp, ing);
        }else{
            a = agregarHojaIngles(a, esp, ing);
        }
    }
    fclose(fptr);
    free(esp);
    free(ing);
    return a;
}

