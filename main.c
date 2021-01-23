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
            proccessEsp(dict, option);
            free(option);
            break;
        }
        if(strcmp(res, "ingles-español") == 0){
            fflush(stdin);
            char *option = malloc(MAX * sizeof(char));
            printf("ingrese palabra a traducir: ");
            scanf("%s",option);
            proccessIng(dict, option);
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