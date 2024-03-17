#include <stdio.h>

int main() {

    int n;
    int i = 0, sum = 0;
    
    printf("Ingrese la cantidad de elementos: \n");
    scanf("%d", &n);
    int vec[n];
    
    for (i = 0; i < n ; i++) {
        printf("Ingrese un numero: \n");
        scanf("%d", &vec[i]);
    }
    
    printf("\n");
    for (i = 0; i < n; i++) {
        sum += vec[i];
    }

    // La diferencia entre mostrar y asignar es que para asignar es con punteros
    for (i = 0; i < n; i++) {
        printf("vec[%d] = %d\n",i, vec[i]); // aca accedemos al indice del vector e imprimimos
    }

    printf("\nLa sumatoria total del vector es %d", sum);
    return 0;
}