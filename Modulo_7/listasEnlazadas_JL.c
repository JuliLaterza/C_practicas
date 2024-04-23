#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Empleado {
    int legajo;
    char nombre[50];
    char apellido[50];
    int sector;
    int antiguedad;
    float sueldo;
    struct Empleado* sig;
} nodo;

void cargarLista(nodo *empleado){
    nodo *nuevoNodo = (nodo*)malloc(sizeof(nodo));
    printf("Ingrese el legajo: ");
    scanf("%d", &nuevoNodo->legajo);

    if (nuevoNodo->legajo == 0) {
        empleado ->sig = NULL;
    }
    else {
        printf("Ingrese el nombre: ");
        scanf("%s", nuevoNodo->nombre);
        printf("Ingrese el apellido: ");
        scanf("%s", nuevoNodo->apellido);
        printf("Ingrese el sector (1, 2 o 3): ");
        scanf("%d", &nuevoNodo->sector);
        printf("Ingrese la antiguedad: ");
        scanf("%d", &nuevoNodo->antiguedad);
        printf("Ingrese el sueldo: ");
        scanf("%f", &nuevoNodo->sueldo);
        nuevoNodo->sig = (nodo*)malloc(sizeof(nodo));
        cargarLista(nuevoNodo->sig);
    }
}

void mostrarLista(nodo *empleado) {
    if (empleado == NULL) {
        return;
    }else{
        printf("Legajo: %d\n", empleado->legajo);
        printf("Nombre: %s\n", empleado->nombre);
        printf("Apellido: %s\n", empleado->apellido);
        printf("Sector: %d\n", empleado->sector);
        printf("Antiguedad: %d\n", empleado->antiguedad);
        printf("Sueldo: %.2f\n", empleado->sueldo);
        mostrarLista(empleado->sig);   
    }
}

int main(){
    int i = 0;
    nodo *prin = NULL;
    nodo *s = NULL;

    prin=(nodo*)malloc(sizeof(nodo));
    s = (nodo*)malloc(sizeof(nodo));

    cargarLista(prin);
    mostrarLista(prin);
}