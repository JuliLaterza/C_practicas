// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int num;
    struct lista *sig;
} nodo;


void crear(nodo *registro) {
    printf("Ingrese un numero o 0 para finalizar: ");
    scanf("%d",&registro->num);
    if(registro->num == 0){
        registro->sig = NULL;
    }else{
        registro->sig = (nodo*)malloc(sizeof(nodo));
        crear(registro->sig);
    }
}


void mostrar(nodo *registro){
    if(registro->sig == NULL){
        return;
    }else{
        printf("%d\n", registro->num);
        mostrar(registro->sig);
    }
}



int main() {
    
    nodo *prin;
    prin = (nodo*)malloc(sizeof(nodo *)); //almacena mi puntero, mi direccion
    crear(prin);
    mostrar(prin);
    
    return 0;
}