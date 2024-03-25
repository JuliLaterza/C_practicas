#include <stdio.h>
#include <stdlib.h>


void cargarVector(int vec[]){
    int i, j ,numero, cont;
    cont = 0;
    while(cont != 10){
        printf("Ingresa un numero: ");
        scanf("\n%d", &numero);
        if(numero > 0 && cont < 5){
            vec[cont] += numero;
            cont += 1;
        }
        else if (numero < 0 && cont >= 5){
            vec[cont] = numero;
            cont += 1;
        }else{
            printf("Che, no ingresaste un numero permitido.")
        }
    }
}

void mostrarVector(int vec[]){
    int i,n;
    n = 10;

    for(i = 0; i < n; i++){
        printf("\n%d", vec[i]);
    }
}


int main() {
    int vec[12];
    cargarVector(vec);
    mostrarVector(vec);

    return 0;
}
