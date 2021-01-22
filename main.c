#include "stdio.h"
#include "arbol.c"

void inorderAccess(arbol *a){
    if(a == NULL){
        return;
    }
    inorderAccess(a->izquierdoEsp);
    //proccess
    inorderAccess(a->derechoIng);
}

int main(){
    printf("laboratorio3 !!!  \n");
    arbol *a = NULL;
    a = rellenarArbol();
/*     char *option = malloc(1024 * sizeof(char));
    arbol *a = NULL;
    arbol *b = NULL;
    ;
    b = rellenarArbol(0);
    inorder(a, a, "Oso"); */
    // inorder(a, a, )

    return 0;


}