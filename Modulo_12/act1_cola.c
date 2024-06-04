#include<stdio.h>
#include<stdlib.h>

#define CANT 5

typedef struct cola {
    int dato;
    struct cola *sig;
} nodo;

void mostrar(nodo aux, int *c, int *max, int *cant, int segundo) {
    if (aux.dato % 4 == 0)
        *c = *c + aux.dato;
    if (aux.dato > *max)
        *max = aux.dato;
    if (aux.dato == segundo)
        *cant = *cant + 1;

    printf("%d \n", aux.dato);
}

nodo* crear_nodo(int dato) {
    nodo* u = (nodo *)malloc(sizeof(nodo));
    
    u->dato = dato;
    u->sig = NULL;

    return u;
}

void acolar(nodo** p, nodo** u, nodo *q) {
    printf("acolar_nodo\n");
    if (*p == NULL) {
        *p = *u = q;
    } else {
        (*u)->sig = q;
        (*u) = q;
    }
}

nodo desacolar(nodo** inicio) {
    nodo* aux;
    nodo datos;

    datos = **inicio;
    aux = *inicio;
    *inicio = (*inicio)->sig;
    free(aux);

    return datos;
}

int repeticiones(nodo* p, int segundo) {
    int contador = 0;
    nodo* actual = p;

    while (actual != NULL) {
        if (actual->dato == segundo) {
            contador = contador + 1;
        }
        actual = actual->sig;
    }

    return contador;
}

int main() {
    int i, num,dim, c = 0, cant = 0, primero;
    nodo* p = NULL;
    nodo* u = NULL;

    printf("Ingrese un numero para la dimension de la cola:\n");
    scanf("%d",dim);

    for (i = 0; i < dim; i++) {
        printf("Ingrese un numero: ");
        scanf("%d", &num);
        if (i == 0) {
            max = num;
            primero = num;
        }
        acolar(&p, &u, crear_nodo(num));
    }

    int segundo_numero;
    if (p != NULL && p->sig != NULL) {
        segundo_numero = p->sig->dato;
        cant = repeticiones(p, segundo_numero);
    }

    printf("\n La cantidad de veces que se repite el segundo numero es %d\n", cant);

    return 0;
}
