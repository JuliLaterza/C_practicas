#include <stdio.h>

void cargarVec(float *pun) {
    for (int i = 0; i < 15; i++) {
        printf("Ingrese un valor para el vector: ");
        scanf("%f", pun);
        pun++;
    }
}

void mostrarVec(float *pun) {
    for (int i = 0; i < 15; i++) {
        printf("dirección: %p | valor: %.2f\n", pun, *pun);
        pun++;
    }
}

int main() {
    float vec[15];
    float *pun = vec;

    cargarVec(pun);
    mostrarVec(pun);

    return 0;
}
