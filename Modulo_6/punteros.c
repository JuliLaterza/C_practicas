#include <stdio.h>

void cargarVector(float vec[], int dim, int i){
    if(i >= dim) {
        return;
    }else{
        printf("Ingrese un número en el vector" );
        scanf(" %f", &vec[i]);
        cargarVector(vec,15, i + 1);
    }
}

void mostrarVector(float vec[], int dim, int i){
    if(i >= dim) {
        return;
    }else {
        printf("\n");
        printf(" %.2f", vec[i]);
        mostrarVector(vec, 15, i+1);
    }
}


int main() {
    
    float vec[15], i;
    
    cargarVector(vec,15,0);
    
    mostrarVector(vec,15,0);
    
    return 0;
}