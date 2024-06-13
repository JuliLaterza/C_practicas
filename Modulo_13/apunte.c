#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct NodoArbol {
    int valor;
    struct NodoArbol* izquierdo;
    struct NodoArbol* derecho;
};


struct NodoArbol* crearNodo(int valor) {
    struct NodoArbol* nodo = (struct NodoArbol*)malloc(sizeof(struct NodoArbol));
    nodo->valor = valor;
    nodo->izquierdo = NULL;
    nodo->derecho = NULL;
    return nodo;
}


struct NodoArbol* insertarNodo(struct NodoArbol* raiz, int valor) {
    if (raiz == NULL) {
        return crearNodo(valor);
    }
 
    if (valor < raiz->valor) {
        raiz->izquierdo = insertarNodo(raiz->izquierdo, valor);
    } else if (valor > raiz->valor) {
        raiz->derecho = insertarNodo(raiz->derecho, valor);
    }
 
    return raiz;
}


struct NodoArbol* eliminarNodo(struct NodoArbol* raiz, int valor) {
    if (raiz == NULL) {
        return raiz;
    }
 
    if (valor < raiz->valor) {
        raiz->izquierdo = eliminarNodo(raiz->izquierdo, valor);
    } else if (valor > raiz->valor) {
        raiz->derecho = eliminarNodo(raiz->derecho, valor);
    } else {
        if (raiz->izquierdo == NULL) {
            struct NodoArbol* temp = raiz->derecho;
            free(raiz);
            return temp;
        } else if (raiz->derecho == NULL) {
            struct NodoArbol* temp = raiz->izquierdo;
            free(raiz);
            return temp;
        }
 
        struct NodoArbol* sucesor = encontrarSucesor(raiz->derecho);
        raiz->valor = sucesor->valor;
        raiz->derecho = eliminarNodo(raiz->derecho, sucesor->valor);
    }
 
    return raiz;
}


void inOrden(struct NodoArbol* raiz) {
    if (raiz != NULL) {
        inOrden(raiz->izquierdo);
        printf("%d ", raiz->valor);
        inOrden(raiz->derecho);
    }
}



int main() {
    // Crear el árbol binario

    struct NodoArbol* raiz = NULL;
 
    raiz = insertarNodo(raiz, 10);
    raiz = insertarNodo(raiz, 5);
    raiz = insertarNodo(raiz, 15);
    raiz = insertarNodo(raiz, 3);
    raiz = insertarNodo(raiz, 7);
    raiz = insertarNodo(raiz, 13);
    raiz = insertarNodo(raiz, 18);

    
 
    printf("Recorrido en orden: ");
    inOrden(raiz);
    printf("\n");
 
    return 0;
}