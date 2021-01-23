#include "arbol.c"


/**
 * @descripcion crea un arbol a partir de parametros entregados
 * @param esp - palabra en español
 * @param ing - palabra en ingles
 * @return arbol
*/
arbol *crearArbol(char *esp, char *ing, arbol *root);
/**
 * @descripcion - agrega a una hoja derecha o izquierda a un arbol entregado en ingles o español
 * @param a - arbol a modificar
 * @param esp - palabra en español
 * @param ing - palabra en ingles
 * @param root - raiz de la palabra
 * @param flag - flag de idioma
 * @return arbol
*/
arbol *agregarHoja(arbol *a ,char *esp,char *ing, arbol *root, int flag);
/**
 * @descripcion rellena un arbol desde un archivo entrada.in
 * @param flag de idioma
 * @return arbol
*/
arbol *rellenarArbol(int flag);
/**
 * @descripcion crea un diccionario y lo completa con una entrada de archivo
 * @return diccionario
*/
dictionary *crearDiccionario();
/**
 * @descripcion busca una palabra dentro de un arbol
 * @param a - arbol a recorrer
 * @param palabra - palabra a buscar
 * @param flag - flag de idioma
 * @return arbol
*/
arbol *buscarPalabra(arbol *a, char *palabra, int flag);
/**
 * @descripcion busca el padre de una palabra espefica en un arbol 
 * @param a - arbol a recorrer
 * @param palabra - palabra a buscar
 * @param root - raiz de a
 * @param flag - flag de idioma
 * @return arbol
*/
arbol* buscarPadre(arbol *a, char *palabra, arbol *root, int flag);