#include <stdio.h>
#include <stdlib.h>

void cargarMatriz(int mat[][3]) {
    int i, j;
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("Ingrese el valor de la posicion [%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}

void mostrarMatriz(int mat[][3]) {
    int i, j;
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int sumaDiagonal(int mat[][3]) {
    int i, suma = 0;
    for(i = 0; i < 3; i++) {
        suma += mat[i][i];
    }
    return suma;
}

void sumaPorFila(int mat[][3]){
    int i , j, sum;

    for (i=0; i<3; i++){
        sum = 0;
        for(j=0; j < 3; j++){
            sum += mat[i][j];
        }
        printf("\nLa suma de la fila %d es %d",i,sum);
    }
}

int maximo(int mat[][3]){
    int i,j,max;

    max = mat[0][0];

    for(i = 0; i < 3; i++){
        for(j=0; j < 3; j++) {
            if (mat[i][j] > max){
                max = mat[i][j];
            }
        }
    }

    return max;
}

void sumaFila2(int mat[][3]){
    int i, j, sum;

    for(i = 0; i < 3; i++){
        for(j=0; j < 3; j++) {
            if(i==1){
                sum += mat[i][j];
            }
        }
    }
    printf("\nLa suma de la fila 2 de la matriz es %d ",sum);
}

void simetrica(int mat[][3]){
    int i,j, cont;
    for(i = 0; i < 3; i++){
        for(j=0; j<3; j++) {
            if(mat[i][j] == mat[j][i]){ //Si el primero es igual a su espejo.
                cont++;
            }
        
        }
    }
    if(cont == 9){
        printf("\nLa matriz es simetrica");
    }else{
        printf("\nLa matriz no es simetrica");
    }
}

int main() {
    int mat[3][3];

    cargarMatriz(mat);
    mostrarMatriz(mat);
    printf("La suma de la diagonal es: %d\n", sumaDiagonal(mat));
    sumaPorFila(mat);
    printf("\nEl maximo de la matriz es: %d", maximo(mat));
    sumaFila2(mat);
    simetrica(mat);
    return 0;
}
