// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>



typedef struct lista{
    int num;
    struct lista *sig;
}nodo;


void crear(nodo *registro){
    printf("Ingrese un número: ");
    scanf("%d", &registro->num);
    if (registro->num == 1000){
        registro->sig = NULL;
    }else{
        registro->sig = malloc(sizeof(nodo));
        crear(registro->sig);
    }
}

void mostrar(nodo *registro) {
    if(registro == NULL){
        return;
    }else {
        printf("%d",registro->num);
        mostrar(registro->sig);
    }
}

nodo *generar_multiplo3(nodo *registro){
    nodo *lista_3 = (nodo*)malloc(sizeof(nodo));
    
    if(lista_3 == NULL){
        printf("\nMemoria insuficiente");
    }
    nodo *current = lista_3;
    
    
    while(registro != NULL){
        if(registro->num % 3 ==0){
            current = malloc(sizeof(nodo));
            if(current -> sig == NULL) {
                printf("\nNo se puede ingresar a la memoria");
            }else{
                current = current->sig;
                current->num = registro->num;
            }
        }
        registro = registro->sig;
    }
    current->sig == NULL;
    return lista_3;
}


int main() {
    
    nodo *prin, *lista_3;
    prin = (nodo*)malloc(sizeof(nodo));
    
    crear(prin);
    mostrar(prin);
    
    lista_3 = generar_multiplo3(prin->sig);
    
    mostrar(lista_3->sig);
    
    return 0;
}


