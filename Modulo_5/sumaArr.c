#include <stdio.h>

int sumar(int vec[], int dim) {
    if (dim == 0)
        return 0;
    else
        return sumar(vec, dim - 1) + vec[dim];
}

int main() {
    int arreglo[] = {1, 2, 3, 4, 6};
    int dimension = sizeof(arreglo) / sizeof(arreglo[0]);
    
    int resultado = sumar(arreglo, dimension);
    
    printf("La suma de los elementos del arreglo es: %d\n", resultado);
    
    return 0;
}
