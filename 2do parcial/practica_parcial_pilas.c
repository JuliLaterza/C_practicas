#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
    int num;
    struct stack *siguiente;
} stack;

// Función para crear un nuevo nodo
stack* crear_nodo(int num) {
    stack* nuevo = (stack *)malloc(sizeof(stack));
    nuevo->num = num;
    nuevo->siguiente = NULL;
    return nuevo;
}

// Función para apilar un nodo
void apilar(stack** p, stack* nuevo) {
    nuevo->siguiente = *p;
    *p = nuevo;
}

// Función para desapilar un nodo
stack* desapilar(stack** p) {
    if (*p == NULL) {
        return NULL;
    }
    stack* temp = *p;
    *p = (*p)->siguiente;
    return temp;
}

// Función para calcular la sumatoria de números mayores al primer elemento ingresado en la pila
void sumatoria_mayores(stack* p) {
    if (p == NULL) {
        printf("La pila está vacía.\n");
        return;
    }
    int primer_num = p->num;
    int sumatoria = 0;
    int found = 0;

    while (p != NULL) {
        if (p->num > primer_num) {
            sumatoria += p->num;
            found = 1;
        }
        p = p->siguiente;
    }

    if (found) {
        printf("La sumatoria de números mayores al primer elemento es: %d\n", sumatoria);
    } else {
        printf("No hay ningún número mayor al primer elemento ingresado en la pila.\n");
    }
}

int main() {
    int num;
    stack* pila = NULL;
    
    // Ingreso de datos a la pila
    for (int i = 0; i < 5; i++) {
        printf("Ingrese un numero: ");
        scanf("%d", &num);
        apilar(&pila, crear_nodo(num));
    }

    // Mostrar la sumatoria de números mayores al primer elemento
    sumatoria_mayores(pila);

    // Desapilar y liberar la memoria de los nodos
    while (pila != NULL) {
        stack* temp = desapilar(&pila);
        free(temp);
    }

    return 0;
}
