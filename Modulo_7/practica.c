#include <stdio.h>

int main() {
#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    char nombre[50];
    char apellido[50];
    int edad;
    float salario;
    struct Nodo* siguiente;
} Nodo;

Nodo* cargarLista() {
    Nodo* cabeza = NULL;
    Nodo* actual = NULL;
    int continuar = 1;

    while (continuar) {
        Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));

        printf("Ingrese el nombre: ");
        scanf("%s", nuevoNodo->nombre);

        printf("Ingrese el apellido: ");
        scanf("%s", nuevoNodo->apellido);

        printf("Ingrese la edad: ");
        scanf("%d", &nuevoNodo->edad);

        printf("Ingrese el salario: ");
        scanf("%f", &nuevoNodo->salario);

        nuevoNodo->siguiente = NULL;

        if (cabeza == NULL) {
            cabeza = nuevoNodo;
            actual = nuevoNodo;
        } else {
            actual->siguiente = nuevoNodo;
            actual = nuevoNodo;
        }

        printf("Ingrese 0 para finalizar la carga, o cualquier otro número para continuar: ");
        scanf("%d", &continuar);

        if (continuar == 0) {
            break;
        }
    }

    return cabeza;
}
    // Tu código aquí
    
    return 0;
}
