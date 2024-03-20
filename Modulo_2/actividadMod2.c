#include <stdio.h>
#include <stdlib.h>


void cargarVector(int vec[]) {
    int i=0, cont = 0;
    int num;
    int cero = 0;
    while(cont < 100 && cero == 0) {
        printf("Ingresa un numero o 0 para salir: ");
        scanf(" %d", &num);        
        
        if(num%2 == 0 && num != 0){
            vec[i] = num;
            cont += 1;
            i += 1;
            printf("Es par\n");
        }
        if(num == 0){
            cero = 1;
        }
    }
}

void mostrarVector(int vec[]){
    int i;
    for(i = 0; i < 100 ; i++){
        printf("vec[%d] = %d\n",i, vec[i]);
    }
}

int promedio(int vec[]){
    int cant,suma,i,prom;
    suma = 0;
    cant = 0;
    for(i = 0; i < 100 ; i++) {
        if (vec[i] != 0) {
            suma = suma + vec[i];
            cant += 1;
        }
    }

    return suma/cant;
}

int maximo(int vec[]){
    int maximo, i;
    maximo = vec[0];
    for(i=0 ; i < 100; i++){
        if (vec[i] > maximo) {
            maximo = vec[i];
        }
    }

    return maximo;
}

void eliminarNumeros(int vec[], int promedio) {
    int i, numero;
    int limite1 = promedio;

    printf("\nIngrese un numero de limite: ");
    scanf("%d", &numero);

    int limite2 = numero / 2;

    for (i = 0; i < 100; i++) {
        if (vec[i] > limite1 && vec[i] < limite2) {
            vec[i] = 0;
        }
    }
}

void insertarCero(int vec[], int maximo, int promedio) {
    int i;
    int insertar = 0;

    for (i = 0; i < 100; i++) {
        if (vec[i] > promedio && vec[i] % 2 != 0) {
            insertar = 1;
        } else if (insertar == 1) {
            for (int j = 99; j > i; j--) {
                vec[j] = vec[j - 1];
            }
            vec[i + 1] = 0;
            insertar = 0;
            i++;
        }
    }
}

void ordenarVector(int vec[]) {
    int i, j, aux;
    for (i = 0; i < 100 - 1; i++) {
        for (j = i + 1; j < 100; j++) {
            if (vec[i] > vec[j]) {
                aux = vec[i];
                vec[i] = vec[j];
                vec[j] = aux;
            }
        }
    }
    printf("\nVector ordenado\n");
}


int main() {

    int vec[102] = {0};
    int p, max;
    cargarVector(vec);
    mostrarVector(vec);
    p = promedio(vec);
    printf("\nEl promedio es %d", p);
    max = maximo(vec);
    printf("\nEl maximo es %d", max);
    eliminarNumeros(vec, p);
    mostrarVector(vec);
    insertarCero(vec, max, p);
    mostrarVector(vec);
    ordenarVector(vec);
    mostrarVector(vec);
    return 0;
}
