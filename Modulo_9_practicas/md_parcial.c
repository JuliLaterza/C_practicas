#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int num1;
    int num2;
    struct lista *sig;
}nodo;


void crear(nodo *registro){
    
    printf("Ingrese un Número A: ");
    scanf("%d", &registro->num1);
    printf("Ingrese un número B: ");
    scanf("%d",&registro->num2);
    
    if(registro->num1 == 0 && registro->num2 == 0){
        registro -> sig = NULL;
    }else{
        registro->sig = (nodo *)malloc(sizeof(nodo));
        crear(registro->sig);
    }
};

void insertar (nodo *registro) {
    nodo *aux;
    while(registro->sig!=NULL) {
        if((registro->num1+registro->num2) > 15){
            
            aux=(nodo *)malloc(sizeof(nodo));
            
            aux->num1=(registro->num1)/2;
            aux->num2=(registro->num2)/2;
            aux->sig=registro->sig;
            registro->sig=aux;
            registro=registro->sig->sig;

        }
        else
        registro=registro->sig;
    }
}


void mostrar(nodo *registro){
    if (registro != NULL){
        printf("\n%d | ",registro->num1);
        printf("%d",registro->num2);
        printf("\n");
        mostrar(registro->sig);
    }
};

void eliminar(nodo *registro){
    nodo *aux;
    
    while(registro->sig != NULL && registro->sig->sig != NULL){
        if(registro->sig->num1 % registro->sig->num2 == 0){
            
            aux = registro->sig->sig;
            free(registro->sig);
            registro->sig = aux;
        }else{
            registro = registro->sig;
        }
    }
}



int main(){
    
    nodo *prin;
    prin = (nodo *)malloc(sizeof(nodo));
    
    crear(prin);
    mostrar(prin);
    printf("\n--------");
    insertar(prin);
    mostrar(prin);
    printf("\n--------");
    eliminar(prin);
    mostrar(prin);
    
    return 0;
}