#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int dato;
    struct nodo* sig;
} nodo;

nodo* crear_nodo(int dato) {
    nodo* nuevo_nodo = (nodo*)malloc(sizeof(nodo));

    nuevo_nodo->dato = dato;
    nuevo_nodo->sig = NULL;
    
    return nuevo_nodo;
}

void apilar(nodo** p, nodo* nuevo_nodo) {
    
    nuevo_nodo->sig = *p;
    *p = nuevo_nodo;

}

nodo desapilar(nodo** p) {
    nodo* aux = *p;
    nodo datos = **p;
    *p = (*p)->sig;
    free(aux);
    return datos;
}

void calc_producto(nodo* p) {
    int count = 0;
    int producto = 1;
    nodo* actual = p;

    while (actual != NULL && count < 5) {
        producto = producto * actual->dato;
        actual = actual->sig;
        count = count + 1;
    }

    if (count < 5) {
        printf("No hay suficientes numeros en la pila\n");
    } else {
        printf("El producto de los numeros es: %d\n", producto);
    }
}

int main() {
    nodo* p = NULL;
    int num; dim;

    printf("Ingrese la cantidad de numeros para cargar la pila: ");
    scanf("%d", &dim);

    for (int i = 0; i < dim; i++) {
        printf("Ingrese un numero: ");
        scanf("%d", &num);
        apilar(&p, crear_nodo(num));
    }

    calc_producto(p);

    while (p != NULL) {
        desapilar(&p);
    }

    return 0;
}
