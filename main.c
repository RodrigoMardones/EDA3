#include "stdio.h"
#include "arbol.h"
#define MAX 100


int main(){
    printf("laboratorio3 !!!  \n");
    char *res = malloc(MAX * sizeof(char));
    dictionary *dict = crearDiccionario();
    do{
        printf("ingrese su option, ingles-español o español-ingles : ");
        scanf("%s", res);
        
        if(strcmp(res, "español-ingles") == 0){
            fflush(stdin);
            char *option = malloc(MAX * sizeof(char));
            printf("ingrese palabra a traducir: ");
            scanf("%s",option);
            arbol *resultado = buscarPalabra(dict->espanol, option, 1);
            arbol *resultadoIngles = buscarPalabra(dict->ingles, resultado->ing,0);
            if(resultado == NULL){
                printf("palabra no encontrada \n");
                break;
            }
            printf("palabra traducida : %s \n\n", resultado->ing);

            if(resultado->padre != NULL){
                printf("nodo padre español : %s/%s \n", resultado->padre->esp, resultado->padre->ing);
            }
            if(resultadoIngles->padre != NULL){
                printf("nodo padre ingles : %s/%s\n",resultadoIngles->padre->esp, resultado->padre->ing);
            }
            if(resultado->derecho != NULL){
                printf("nodo hijo español derecho : %s/%s\n", resultado->derecho->esp, resultado->derecho->ing);
            }
            if(resultado->izquierdo != NULL){
                printf("nodo hijo español izquierdo: %s/%s \n", resultado->izquierdo->esp, resultado->izquierdo->ing);
            }
            if(resultadoIngles->derecho !=NULL){
                printf("nodo hijo ingles derecho : %s/%s\n", resultadoIngles->derecho->esp, resultadoIngles->derecho->ing);
            }
            if(resultadoIngles->izquierdo != NULL){
                printf("nodo hijo ingles izquierdo: %s/%s \n", resultadoIngles->izquierdo->esp, resultadoIngles->izquierdo->ing);
            }

            free(option);
            free(resultado);
            free(resultadoIngles);
            break;
        }
        if(strcmp(res, "ingles-español") == 0){
            fflush(stdin);
            char *option = malloc(MAX * sizeof(char));
            printf("ingrese palabra a traducir: ");
            scanf("%s",option);
            arbol *resultado = buscarPalabra(dict->ingles, option, 0);
            arbol *resultadoEspanol = buscarPalabra(dict->espanol, resultado->esp, 1);
            if(resultado == NULL){
                printf("palabra no encontrada \n");
                break;
            }
            printf("palabra traducida : %s \n\n", resultado->esp);

            if(resultado->padre != NULL){
                printf("nodo padre ingles : %s/%s \n", resultado->padre->esp, resultado->padre->ing);
            }
            if(resultadoEspanol->padre != NULL){
                printf("nodo padre español : %s/%s\n",resultadoEspanol->padre->esp, resultadoEspanol->padre->ing);
            }
            if(resultado->derecho != NULL){
                printf("nodo hijo ingles derecho : %s/%s\n", resultado->derecho->esp, resultado->derecho->ing);
            }
            if(resultado->izquierdo != NULL){
                printf("nodo hijo ingles izquierdo: %s/%s \n", resultado->izquierdo->esp, resultado->izquierdo->ing);
            }
            if(resultadoEspanol->derecho !=NULL){
                printf("nodo hijo español derecho : %s/%s\n", resultadoEspanol->derecho->esp, resultadoEspanol->derecho->ing);
            }
            if(resultadoEspanol->izquierdo != NULL){
                printf("nodo hijo español izquierdo: %s/%s \n", resultadoEspanol->izquierdo->esp, resultadoEspanol->izquierdo->ing);
            }
            free(option);
            break;
        }
        if(strcmp(res, "0") == 0){
            break;
        }
        else{
            printf("opcion no valida\n");
        }   
    } while(1);

    free(res);
    free(dict);
    printf("------------\n");
    return 0;   
}