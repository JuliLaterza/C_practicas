#include <stdio.h>
#include <stdlib.h>

// Definición del nodo
typedef struct Nodo {
    int dato;
    struct Nodo* izquierdo;
    struct Nodo* derecho;
} Nodo;

// Función para crear un nuevo nodo
Nodo* crearNodo(int dato) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->dato = dato;
    nuevoNodo->izquierdo = NULL;
    nuevoNodo->derecho = NULL;
    return nuevoNodo;
}

// Función para insertar un dato en el árbol
Nodo* insertar(Nodo* nodo, int dato) {
    if (nodo == NULL) {
        return crearNodo(dato);
    }

    if (dato < nodo->dato) {
        nodo->izquierdo = insertar(nodo->izquierdo, dato);
    } else if (dato > nodo->dato) {
        nodo->derecho = insertar(nodo->derecho, dato);
    }

    return nodo;
}

// Función para buscar un dato en el árbol
Nodo* buscar(Nodo* raiz, int dato) {
    if (raiz == NULL || raiz->dato == dato) {
        return raiz;
    }

    if (dato < raiz->dato) {
        return buscar(raiz->izquierdo, dato);
    }

    return buscar(raiz->derecho, dato);
}

// Función para buscar el valor máximo en el árbol
Nodo* buscarMaximo(Nodo* nodo) {
    Nodo* actual = nodo;

    while (actual && actual->derecho != NULL) {
        actual = actual->derecho;
    }

    return actual;
}

// Función para realizar un recorrido en orden del árbol
void recorridoEnOrden(Nodo* raiz) {
    if (raiz != NULL) {
        recorridoEnOrden(raiz->izquierdo);
        printf("%d ", raiz->dato);
        recorridoEnOrden(raiz->derecho);
    }
}

int main() {
    Nodo* raiz = NULL;
    raiz = insertar(raiz, 50);
    insertar(raiz, 30);
    insertar(raiz, 20);
    insertar(raiz, 80);
    insertar(raiz, 70);
    insertar(raiz, 60);
    insertar(raiz, 40);

    printf("Recorrido en orden del árbol:\n");
    recorridoEnOrden(raiz);
    printf("\n");

    int datoBuscado = 40;
    Nodo* resultadoBusqueda = buscar(raiz, datoBuscado);
    if (resultadoBusqueda != NULL) {
        printf("Elemento %d encontrado en el árbol.\n", datoBuscado);
    } else {
        printf("Elemento %d no encontrado en el árbol.\n", datoBuscado);
    }

    Nodo* maximo = buscarMaximo(raiz);
    if (maximo != NULL) {
        printf("El valor máximo en el árbol es: %d\n", maximo->dato);
    }

    return 0;
}
