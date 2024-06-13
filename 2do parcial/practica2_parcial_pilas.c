#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
    int num;
    struct stack *siguiente;
} stack;

// Función para crear un nuevo nodo
stack* crear_nodo(int num) {
    stack* nuevo = (stack *)malloc(sizeof(stack));
    if (nuevo == NULL) {
        printf("Error: No se pudo asignar memoria para el nuevo nodo.\n");
        exit(EXIT_FAILURE);
    }
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

// Función para contar la cantidad de elementos múltiplos del último número ingresado a la pila
int contarMultiplos(stack* p) {
    if (p == NULL) {
        printf("La pila está vacía.\n");
        return 0;
    }

    // Encontrar el último número ingresado
    int ultimoNumero = p->num;
    int contador = 0;

    // Recorrer la pila y contar múltiplos del último número
    while (p != NULL) {
        if (p->num != ultimoNumero && ultimoNumero != 0 && p->num % ultimoNumero == 0) {
            contador++;
        }
        p = p->siguiente;
    }

    return contador;
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

    // Calcular la cantidad de elementos múltiplos del último número
    int cantidadMultiplos = contarMultiplos(pila);

    // Mostrar resultados
    if (cantidadMultiplos > 0) {
        printf("Cantidad de elementos múltiplos del último número ingresado: %d\n", cantidadMultiplos);
    } else {
        printf("No hay elementos múltiplos del último número ingresado.\n");
    }

    // Desapilar y liberar la memoria de los nodos
    while (pila != NULL) {
        stack* temp = desapilar(&pila);
        free(temp);
    }

    return 0;
}
