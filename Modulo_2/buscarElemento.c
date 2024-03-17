#include <stdio.h>

int main () {
    int vec[5], dim;
    int num;
    int i;
    dim = 5;
    //Cargamos el vector con datos
    for(int j = 0; j < dim; j++ ) {
        printf("Ingrese un valor en el vector: ");
        scanf(" %d",&vec[j]);
    }

    printf("Ingrese un valor a buscar dentro del vector ");
    scanf(" %d", &num);


    while (i < dim && vec[i] != num) {
        i++;
    }

    if (i == dim) {
        printf("El valor %d no se encuentra en el vector.\n", num);
    } else {
        printf("El valor %d se encuentra en la posición %d.\n", num, i);

    return 0;
    }
}