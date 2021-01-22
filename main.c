#include "stdio.h"
#include "arbol.c"

void procesar(arbol *a, arbol *root, char *palabra, int flag){
    if(strcmp(a->esp, palabra) == 0){
        printf("tu palabra traducida es : %s \n", a->ing);
        printf("el nodo padre es: %s/%s", root->esp, root->ing);
        if(a->izquierdo != NULL){
            printf("el nodo hijo izquierdo en idioma español es : %s/%s \n", a->izquierdo->esp, a->izquierdo->esp);
        }
        //derecho
        if(a->derecho != NULL){
            printf("el nodo hijo derecho en idioma español es: %s/%s \n", a->derecho->esp, a->derecho->ing);
        }
    }
    return;
}
void imprimirArbol(arbol *a, arbol *root){
    printf("root esp : %s \n", root->esp);
    printf("root ing : %s \n", root->ing);
    printf("espanol : %s \n", a->esp);
    printf("ingles : %s \n", a->ing);
    if(a->derecho != NULL){
        printf("\t hijo derecho : %s/%s \n", a->derecho->esp, a->derecho->ing);
    }else{
        printf("\t sin hijo derecho \n");
    }
    if(a->izquierdo != NULL){
        printf("\t hijo izquierdo : %s/%s \n", a->izquierdo->esp, a->izquierdo->ing);
    }else{
        printf("\t sin hijo izquierdo \n");
    }
}

void inorder(arbol *a, arbol* root, char *word){
    if(a == NULL){
        return;
    }
    inorder(a->izquierdo, a, word);
    printf("--------- \n");
    imprimirArbol(a, root);
    printf("--------- \n");
    //procesar(a, a, word, 1);
    inorder(a->derecho, a, word);
}



int main(){
    printf("laboratorio3 !!!  \n");
    char *option = malloc(1024 * sizeof(char));

    printf("%s   \n \n", option);
    arbol *a = NULL;
    arbol *b = NULL;
    a = rellenarArbol(1);
    b = rellenarArbol(0);
    /* a = agregarHoja(a, "Casa", "House");
    a = agregarHoja(a, "Zorro", "Fox");
    a = agregarHoja(a, "Manzana", "Apple");
    a = agregarHoja(a, "Dedo", "Finger");
    a = agregarHoja(a, "Jugar", "Play");
    a = agregarHoja(a, "Oso", "Bear");
    a = agregarHoja(a, "Arbol", "Tree");

    b = agregarHojaIngles(b, "Casa", "House");
    b = agregarHojaIngles(b, "Zorro", "Fox");
    b = agregarHojaIngles(b, "Manzana", "Apple");
    b = agregarHojaIngles(b, "Dedo", "Finger");
    b = agregarHojaIngles(b, "Jugar", "Play");
    b = agregarHojaIngles(b, "Oso", "Bear");
    b = agregarHojaIngles(b, "Arbol", "Tree"); */
    inorder(a, a, "Oso");
    // inorder(a, a, )
    printf("-----------------\n");
    return 0;


}