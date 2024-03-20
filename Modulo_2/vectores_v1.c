// Online C compiler to run C program online
#include <stdio.h>

int maximo(int vec[],int n ) {
    int max = vec[0];
    int i;
    
    for (i = 0; i<n; i++) {
        if (vec[i]>max){
            max = vec[i];
        }
    }
    
    return max;
}

void mostrar(int vec[], int n){
    int i = 0;
    
    for(i = 0; i<n; i++){
        
        printf(" %d", vec[i]);
    }
}


int main() {
  int vec[] = {1, 5, 3, 2, 4};
  int num = 5; // Longitud del vector conocida de antemano
  int maximo_valor = maximo(vec, num);
  mostrar(vec,num);
  printf("El valor máximo del vector es: %d\n", maximo_valor);

  return 0;
}