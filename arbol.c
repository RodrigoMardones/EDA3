#include "stdlib.h"
#include "stdio.h"
#include "string.h"

typedef struct Arbol{
    char *esp;
    char *ing;
    int peso;

    struct Arbol *padreEsp;
    struct Arbol *izquierdoEsp;
    struct Arbol *derechoEsp;

    struct Arbol *padreIng;
    struct Arbol *izquierdoIng;
    struct Arbol *derechoIng;
} arbol;

arbol *crearArbol(char *esp, char *ing){
    arbol *a = malloc(sizeof(arbol));
    // inicializamos valores
    a->esp = malloc(sizeof(esp));
    strcpy(a->esp, esp);
    a->ing = malloc(sizeof(ing));
    strcpy(a->ing, ing);

    a->padreEsp = NULL;
    a->izquierdoEsp = NULL;
    a->derechoEsp = NULL;

    a->padreIng = NULL;
    a->izquierdoIng = NULL;
    a->derechoIng = NULL;

    return a;
}


arbol *agregarHoja(arbol *a, char *esp,char *ing){
    if(a == NULL){
        return crearArbol(esp, ing);
    }
    if(strcmp(a->esp, esp) < 0){
        a->izquierdoEsp = agregarHoja(a->izquierdoEsp, esp, ing);
    }
    else if(strcmp(a->esp, esp) > 0){
        a->derechoEsp = agregarHoja(a->derechoEsp, esp, ing);
    }
    return a;
}

arbol *agregarHojaIngles(arbol *a, char *esp, char *ing){
    if(a == NULL){
        return crearArbol(esp, ing);
    }
    if(strcmp(a->ing, ing) < 0){
        a->izquierdoIng = agregarHojaIngles(a->izquierdoIng,esp, ing);

    }
    else if(strcmp(a->ing, ing) >= 0){
        a->derechoEsp = agregarHoja(a->derechoEsp, esp, ing);
    }
    return a;
}

arbol *rellenarArbol(){
    FILE *fptr;
    char *esp = malloc(1024 * sizeof(char));
    char *ing = malloc(1024 * sizeof(char));
    arbol *a = NULL;
    fptr = fopen("entrada.in", "r");
    while (fscanf(fptr,"%s %s",esp, ing) != EOF){
        // printf("%s  %s \n", esp, ing);
        a = agregarHoja(a, esp, ing);
        a = agregarHojaIngles(a, esp, ing);
        
    }
    inorder(a,a);
    inorder(inorderIngles);
    fclose(fptr);
    free(esp);
    free(ing);
    return a;
}

void imprimirArbol(arbol *a, arbol *root){
    
    
    printf("españ ol : %s \n", a->esp);
    printf("ingles : %s \n", a->ing);
    // padre español
    if(a->padreEsp != NULL){
        printf("el nodo padre español : %s/%s \n", root->padreEsp->esp, root->padreEsp->ing);
    }else {
        printf("sin padre español \n");
    }
    // padre ingles
    if(a->padreIng != NULL){
        printf("el nodo padre ingles es: %s/%s \n", root->padreIng->esp, root->padreIng->ing);
    }else{
        printf("sin padre ingles \n");
    }
    if(a->derechoEsp != NULL){
        printf("\t hijo derecho : %s/%s \n", a->derechoEsp->esp, a->derechoEsp->ing);
    }else{
        printf("\t sin hijo derecho español \n");
    }
    if(a->izquierdoEsp != NULL){
        printf("\t hijo izquierdo : %s/%s \n", a->izquierdoEsp->esp, a->izquierdoEsp->ing);
    }else{
        printf("\t sin hijo izquierdo español \n");
    }

    if(a->derechoIng != NULL){
        printf("\t hijo derecho : %s/%s \n", a->derechoIng->esp, a->derechoIng->ing);
    }else{
        printf("\t sin hijo derecho ingles\n");
    }
    if(a->izquierdoIng != NULL){
        printf("\t hijo izquierdo : %s/%s \n", a->izquierdoIng->esp, a->izquierdoIng->ing);
    }else{
        printf("\t sin hijo izquierdo ingles \n");
    }
}
void inorder(arbol *a, arbol* root){
    if(a == NULL){
        return;
    }
    inorder(a->izquierdoEsp, a, word);
    a->padreEsp = root;
    inorder(a->derechoEsp, a, word);
}
void inorderIngles(arbol *a, arbol *root){
    if(a == NULL){
        return;
    }
    inorder(a->izquierdoIng, a, word);
    a->padreIng = root;
    inorder(a->derechoIng, a, word);
}