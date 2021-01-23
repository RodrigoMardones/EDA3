#include "arbol.c"

arbol *crearArbol(char *esp, char *ing, arbol *root);

arbol *agregarHoja(arbol *a ,char *esp,char *ing, arbol *root, int flag);

arbol *rellenarArbol(int flag);

dictionary *crearDiccionario();

arbol *buscarPalabra(arbol *a, char *palabra, int flag);

arbol* buscarPadre(arbol *a, char *palabra, arbol *root, int flag);