/*
Crear una lista simplemente enlazada con el número de legajo, nombre y apellido, sector (codificado entre 1 y 3), antigüedad y sueldo. La carga de datos finaliza cuando el número de legajo es igual a cero. Se pide:
Mostrar la lista con los datos cargados
Calcular el promedio de sueldos del sector 2 y cuyos apellidos tengan mas de 4 caracteres.
Generar una nueva lista con los empleados que pertenecen al sector que mas empleados tenga y que además tengan al menos 3 años de antigüedad.
*/

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
    struct Empleado* siguiente;
} Empleado;

Empleado* cargarLista() {
    Empleado* cabeza = NULL;
    Empleado* actual = NULL;
    int continuar = 1;

    while (continuar) {
        Empleado* nuevoEmpleado = (Empleado*)malloc(sizeof(Empleado));

        printf("Ingrese el legajo: ");
        scanf("%d", &nuevoEmpleado->legajo);

        if (nuevoEmpleado->legajo == 0) {
            break;
        }

        printf("Ingrese el nombre: ");
        scanf("%s", nuevoEmpleado->nombre);

        printf("Ingrese el apellido: ");
        scanf("%s", nuevoEmpleado->apellido);

        printf("Ingrese el sector (1, 2 o 3): ");
        scanf("%d", &nuevoEmpleado->sector);

        printf("Ingrese la antiguedad: ");
        scanf("%d", &nuevoEmpleado->antiguedad);

        printf("Ingrese el sueldo: ");
        scanf("%f", &nuevoEmpleado->sueldo);

        nuevoEmpleado->siguiente = NULL;

        if (cabeza == NULL) {
            cabeza = nuevoEmpleado;
            actual = nuevoEmpleado;
        } else {
            actual->siguiente = nuevoEmpleado;
            actual = nuevoEmpleado;
        }
    }

    return cabeza;
}

void mostrarLista(Empleado* cabeza) {
    Empleado* actual = cabeza;

    while (actual != NULL) {
        printf("Legajo: %d\n", actual->legajo);
        printf("Nombre: %s\n", actual->nombre);
        printf("Apellido: %s\n", actual->apellido);
        printf("Sector: %d\n", actual->sector);
        printf("Antiguedad: %d\n", actual->antiguedad);
        printf("Sueldo: %.2f\n", actual->sueldo);
        printf("\n");

        actual = actual->siguiente;
    }
}

float promedioSueldosSector2(Empleado* cabeza) {
    Empleado* actual = cabeza;
    int cantidadEmpleados = 0;
    float sumaSueldos = 0;

    while (actual != NULL) {
        if (actual->sector == 2 && strlen(actual->apellido) > 4) {
            sumaSueldos += actual->sueldo;
            cantidadEmpleados++;
        }

        actual = actual->siguiente;
    }

    return cantidadEmpleados > 0 ? sumaSueldos / cantidadEmpleados : 0;
}

Empleado* empleadosSectorMasEmpleadosConAntiguedad(Empleado* cabeza) {
    Empleado* actual = cabeza;
    int cantidadEmpleadosSector1 = 0;
    int cantidadEmpleadosSector2 = 0;
    int cantidadEmpleadosSector3 = 0;

    while (actual != NULL) {
        if (actual->sector == 1) {
            cantidadEmpleadosSector1++;
        } else if (actual->sector == 2) {
            cantidadEmpleadosSector2++;
        } else if (actual->sector == 3) {
            cantidadEmpleadosSector3++;
        }

        actual = actual->siguiente;
    }

    int sectorMasEmpleados = 1;
    if (cantidadEmpleadosSector2 > cantidadEmpleadosSector1 && cantidadEmpleadosSector2 > cantidadEmpleadosSector3) {
        sectorMasEmpleados = 2;
    } else if (cantidadEmpleadosSector3 > cantidadEmpleadosSector1 && cantidadEmpleadosSector3 > cantidadEmpleadosSector2) {
        sectorMasEmpleados = 3;
    }

    Empleado* cabezaNueva = NULL;
    Empleado* actualNueva = NULL;
    actual = cabeza;

    while (actual != NULL) {
        if (actual->sector == sectorMasEmpleados && actual->antiguedad >= 3) {
            Empleado* nuevoEmpleado = (Empleado*)malloc(sizeof(Empleado));
            *nuevoEmpleado = *actual;
            nuevoEmpleado->siguiente = NULL;

            if (cabezaNueva == NULL) {
                cabezaNueva = nuevoEmpleado;
                actualNueva = nuevoEmpleado;
            } else {
                actualNueva->siguiente = nuevoEmpleado;
                actualNueva = nuevoEmpleado;
            }
        }

        actual = actual->siguiente;
    }

    return cabezaNueva;
}

int main() {
    Empleado* cabeza = cargarLista();

    printf("Lista de empleados:\n");
    mostrarLista(cabeza);


    return 0;
}