#include <stdio.h>

void cargarVector(int vec[], int dim, int i) {
    if (i >= dim) {
        return;
    }
    
    printf("Ingrese el elemento %d: ", i + 1);
    scanf("%d", &vec[i]);
    cargarVector(vec, dim, i + 1);
}

void enOrden(int vec[], int dim, int i) {
    if (i >= dim) {
        return;
    }

    printf("%d ", vec[i]);
    enOrden(vec, dim, i + 1);
}

void inverso(int vec[], int dim, int i) {
    if (i < 0) {
        return;
    }
    
    printf("%d ", vec[i]);
    inverso(vec, dim, i - 1);
}

int main() {
    int vec[22];
    
    cargarVector(vec, 20, 0);
    
    printf("Vector en orden: ");
    enOrden(vec, 20, 0);
    
    printf("\nVector en orden inverso: ");
    inverso(vec, 20, 3);
    
    return 0;
}
