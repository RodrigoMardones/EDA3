#include "stdlib.h"
#include "stdio.h"
#include "string.h"

typedef struct Arbol{
    char *esp;
    char *ing;

    struct Arbol *padre;
    struct Arbol *izquierdo;
    struct Arbol *derecho;

} arbol;

typedef struct Dictionary{
    arbol *ingles;
    arbol *espanol;
} dictionary;

arbol *crearArbol(char *esp, char *ing, arbol *root){
    arbol *a = malloc(sizeof(arbol));
    // inicializamos valores
    a->esp = malloc(sizeof(esp));
    strcpy(a->esp, esp);
    a->ing = malloc(sizeof(ing));
    strcpy(a->ing, ing);

    a->padre = root;
    a->izquierdo = NULL;
    a->derecho = NULL;

    return a;
}

arbol *agregarHoja(arbol *a ,char *esp,char *ing, arbol *root, int flag){
    
    if(a == NULL){
        return crearArbol(esp, ing, root);
    }
    if(flag){
        if(strcmp(a->esp, esp) < 0){
            a->izquierdo = agregarHoja(a->izquierdo, esp, ing, a, flag);
        }
        else{
            if(strcmp(a->esp, esp) > 0){
                a->derecho = agregarHoja(a->derecho, esp, ing, a, flag);
            }   
        }
    } 
    else {
        if(strcmp(a->ing, ing) < 0){
            a->izquierdo = agregarHoja(a->izquierdo, esp, ing, a, flag);
        }
        else {
            if(strcmp(a->ing, ing) > 0){
                a->derecho = agregarHoja(a->derecho, esp, ing, a, flag);
            }
        }
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

        a = agregarHoja(a, esp, ing, a, flag);
    }
    fclose(fptr);
    free(esp);
    free(ing);
    return a;
}

dictionary *crearDiccionario(){;
    dictionary *dict = malloc(sizeof(dictionary));
    dict->espanol = rellenarArbol(1);
    dict->ingles = rellenarArbol(0);
    return dict;
}

arbol *buscarPalabra(arbol *a, char *palabra, int flag){
    if(a == NULL){
        return NULL;
    }
    if(flag){
        if(strcmp(a->esp, palabra) == 0){
            return a;
        }
        if(strcmp(a->esp, palabra) < 0){
            return buscarPalabra(a->izquierdo, palabra, flag);
        }
        if(strcmp(a->esp, palabra) > 0){
            return buscarPalabra(a->derecho, palabra, flag);
        }
    } else {
        if(strcmp(a->ing, palabra) == 0){
            return a;
        }
        if(strcmp(a->ing, palabra) < 0){
            return buscarPalabra(a->izquierdo, palabra, flag);
        }
        if(strcmp(a->ing, palabra) > 0){
            return buscarPalabra(a->derecho, palabra, flag);
        }
    }
}

arbol* buscarPadre(arbol *a, char *palabra, arbol *root, int flag){
    if(a == NULL){
        return NULL;
    }
    if(flag){
        if(strcmp(a->esp, palabra) == 0){
            return root;
        }
        if(strcmp(a->esp, palabra) < 0){
            return buscarPadre(a->izquierdo, palabra, a, flag);
        }
        if(strcmp(a->esp, palabra) > 0){
            return buscarPadre(a->derecho, palabra, a, flag);
        }
    } else {
        if(strcmp(a->ing, palabra) == 0){
            return a;
        }
        if(strcmp(a->ing, palabra) < 0){
            return buscarPadre(a->izquierdo, palabra, a, flag);
        }
        if(strcmp(a->ing, palabra) > 0){
            return buscarPadre(a->derecho, palabra, a, flag);
        }
    }
}