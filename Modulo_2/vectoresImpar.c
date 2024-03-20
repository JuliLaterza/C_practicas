// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

/* 
Ingresar números enteros hasta cargar
un arreglo de 8 posiciones
intercalando
un numero impar positivo y un número
negativo. Mostrarlo

a) Ingresar un numero por teclado y eliminar todos los números que se encuentren entre el promedio de los números ingresados en el arreglo y la mitad del numero ingresado.
b) Insertar un cero en la posición siguiente a todos los valores impares que estén entre el máximo y el promedio de los datos del vector. Mostrar el vector.
c) Ordenar el vector de mayor a menor y mostrar el vector.
*/

void cargarVector(int vec[]) {
    int i=0, j=1, cont = 0;
    int num;
    
    while(cont < 8) {
        printf("Mi loco, ingresate un numero: ");
        scanf(" %d", &num);        
        
        if(num%2 != 0 && num > 0 && i < 7){
            vec[i] = num;
            i+=2;
            cont += 1;// para pasar a un numero impar
        }
        if(num < 0 && j < 8){
            vec[j] = num;
            j +=2 ;
            cont += 1;
        }
    }
         //Intercalando con numero impar
}


void mostrarVector(int vec[], int dim){
    int i;
    for(i = 0; i < dim ; i++){
        printf("vec[%d] = %d\n",i, vec[i]);
    }
}

void maximo(int vec[], int dim){
    int maximo, i;
    maximo = vec[0];
    for(i=0 ; i < dim; i++){
        if (vec[i] > maximo) {
            maximo = vec[i];
        }
    }

    printf("El maximo es %d", maximo);
}

void minimo(int vec[], int dim) {
    int minimo, i;
    minimo = vec[0];

    for (i = 0; i < dim; i++){
        if(vec[i] < minimo) {
            minimo = vec[i];
        }
    }
    printf("\nEl minimo es %d", minimo);
}

int promedio(int vec[], int dim){
    int cant,suma,i,prom;
    suma = 0;
    cant = 0;
    for(i = 0; i < dim ; i++) {
        suma = suma + vec[i];
    }

    return suma/8;
}


int main() {

    int vec[10], dim, p, max;
    cargarVector(vec);
    mostrarVector(vec,8);
    maximo(vec,8);
    minimo(vec,8);
    p = promedio(vec,8);
    printf("\nEl promedio es %d", p);
    return 0;
}