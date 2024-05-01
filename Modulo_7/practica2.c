#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int num;
    struct lista *sig;
} nodo;

int main(){

    nodo *prin = NULL;
    prin = (nodo*)malloc(sizeof(nodo));
    crear(prin,0);
    mostrar(prin);
    return 0;
}


void crear(nodo *registro,int cont){

    printf("Ingrese el numero: ");
    scanf("%d", &registro->num);

    if(registro->num == 0){
        registro->sig = NULL;
    }else{
        registro->sig = (nodo*)malloc(sizeof(nodo));
        crear(registro->sig,cont+1);

    }

}

void mostrar(nodo *registro){
    if(registro == NULL){
        return;
    }else{
        printf("Numero: %d\n", registro->num);
        mostrar(registro->sig);
    }
}