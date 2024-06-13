#include <stdio.h>
#include <stdlib.h>

#define CANT 5

typedef struct cola
{
    int dato;
    struct cola *siguiente;
} nodo;

nodo* crear_nodo(int dato)
{
    nodo* u;
    u = (nodo *)malloc(sizeof(nodo));
    u->dato = dato;
    u->siguiente = NULL;
    return u;
}

void acolar(nodo** p, nodo** u, nodo *q)
{
    if(*p == NULL) {
        *p = *u = q;
    } else {
        (*u)->siguiente = q;
        *u = q;
    }
}

nodo desacolar(nodo** inicio)
{
    nodo* aux;
    nodo datos;

    datos = **inicio;
    aux = *inicio;
    *inicio = (*inicio)->siguiente;
    free(aux);

    return datos;
}

void promedioTresPrimeros(nodo* inicio)
{
    int suma = 0, count = 0;
    nodo* actual = inicio;

    for (int i = 0; i < 3 && actual != NULL; i++) {
        suma += actual->dato;
        actual = actual->siguiente;
        count++;
    }

    if (count < 3) {
        printf("No hay suficientes elementos en la cola\n");
    } else {
        float promedio = suma / 3.0;
        printf("El promedio de los tres primeros números es: %.2f\n", promedio);
    }
}

void mostrar(nodo aux, int *c, int *max, int *cant, int primero)
{
    if (aux.dato % 4 == 0)
        *c = *c + aux.dato;
    if (aux.dato > *max)
        *max = aux.dato;
    if (aux.dato == primero)
        *cant = *cant + 1;

    printf("%d \n", aux.dato);
}

int main()
{
    int i, num, c = 0, max, cant = 0, primero;
    nodo* p = NULL;
    nodo* u = NULL;

    for(i = 0; i < CANT; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", &num);
        if (i == 0) {
            max = num;
            primero = num;
        }
        acolar(&p, &u, crear_nodo(num));
    }

    printf("\nVamos a desacolar todo\n");
    promedioTresPrimeros(p);  // Llamada a la función para mostrar el promedio de los tres primeros números

    while(p != NULL)
    {
        mostrar(desacolar(&p), &c, &max, &cant, primero);
    }

    printf("\nLa sumatoria de los múltiplos de 4 es %d", c);
    printf("\nEl valor máximo de la cola es %d", max);
    printf("\nLa cantidad de veces que se repite el primer número es %d", cant - 1);

    return 0;
}
