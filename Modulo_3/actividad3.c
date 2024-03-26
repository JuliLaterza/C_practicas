#include <stdio.h>
#include <stdlib.h>



void cargarMatriz(int mat[][100], int filas, int columnas) {
    int i, j;

    for(i = 0; i < filas; i++){
        for(j=0; j < columnas; j++){
            printf("Ingresar un valor para la matriz: ");
            scanf(" %d", &mat[i][j]);
        }
    }
}


void mostrarMatriz(int mat[][100], int filas, int columnas) {
    int i, j;
    printf("\n");
    for(i = 0; i < filas; i++){
        for(j = 0; j < columnas; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

}

int maximo(int mat[][100], int filas, int columnas){
    int i,j,max;

    max = mat[0][0];

    for(i = 0; i < filas; i++){
        for(j=0; j < columnas; j++) {
            if (mat[i][j] > max){
                max = mat[i][j];
            }
        }
    }

    return max;
}

int sumaDiagonal(int mat[][100], int filas, int columnas){
    int i, j, sum;
    sum = 0;
    for(i = 0; i < filas; i++){
        for(j=0; j < columnas; j++) {
            if(i==j){
                sum += mat[i][j];
            }
        }
    }
    return sum;
}

void vectorPromColums(int mat[][100], int filas, int columnas){

    float promedios[4];

    int i, j, sum;
    for(j = 0; j < columnas;j++){
        for(i=0; i < filas; i++) {
            promedios[j] += mat[i][j]; 
        }
    }

    for(j = 0; j < columnas; j++){
        promedios[j] = promedios[j] / 4;
    }

    for(j = 0; j < columnas; j++){
        printf("\nEl promedio de la columna %d es %.2f", j, promedios[j]);
    }
    printf("\n");
}

void transponerMatriz(int mat[][100], int filas, int columnas){
    int i, j, mat_trans[100][100];

    for(i = 0; i < filas; i++){
        for(j = 0; j < columnas; j++){
            
            mat_trans[j][i] = mat[i][j];
        }
    }

    mostrarMatriz(mat_trans, filas, columnas);
}

int main(){
    int mat[100][100], filas, columnas, max, sum_diag;
    printf("Ingrese las filas de la matriz: ");
    scanf("%d", &filas);
    printf("Ingrese las columnas de la matriz: ");
    scanf("%d", &columnas);
    cargarMatriz(mat, filas, columnas);
    mostrarMatriz(mat, filas, columnas);
    max = maximo(mat, filas, columnas);

    printf("\nEl maximo es %d ", max);
    sum_diag = sumaDiagonal(mat, filas, columnas);
    printf("\nLa suma de la diagonal es %d", sum_diag);
    
    if(sum_diag < max){
        vectorPromColums(mat, filas, columnas);
    }else{
        transponerMatriz(mat, filas, columnas);
    }
    
    return 0;
}