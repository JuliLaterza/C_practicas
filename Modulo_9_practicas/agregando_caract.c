// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int edad;
    char nombre[50];
    struct lista *sig;
} nodo;


void crear(nodo *registro) {
    printf("Ingrese un numero o 0 para finalizar:");
    scanf("%d",&registro->edad);
    if(registro->edad == 0){
        registro->sig = NULL;
    }else{
        printf("\nIngrese nombre de la persona: ");
        scanf("%s", &registro->nombre);
        registro->sig = (nodo*)malloc(sizeof(nodo));
        crear(registro->sig);
    }
}


void mostrar(nodo *registro){
    if(registro == NULL){
        return;
    }else{
        printf("%d\n", registro->edad);
        printf("%s\n", registro->nombre);
        mostrar(registro->sig);
    }
}



int main() {
    
    nodo *prin;
    prin = (nodo*)malloc(sizeof(nodo));
    crear(prin);
    mostrar(prin);
    
    return 0;
}