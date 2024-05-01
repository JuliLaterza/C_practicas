#include <stdlib.h>
#include <stdio.h>

typedef struct lista{
    int num1;
    int num2;
    int num3;
    struct lista *sig;
}nodo;


void cargar(nodo *registro){
    printf("Ingrese un número (0 para finalizar): ");
    scanf("%d", &registro->num1);
    printf("Ingrese otro número: ");
    scanf("%d", &registro->num2);
    printf("Ingrese otro número: ");
    scanf("%d", &registro->num3);
    if (registro->num1 == 0 || registro->num2 == 0 || registro->num3 == 0) {
        registro->sig = NULL;
        return;
    }else {
        registro->sig = (nodo*)malloc(sizeof(nodo));
        cargar(registro->sig);
    }
    
}

void mostrar(nodo *registro){
    if (registro != NULL){
        printf("%d\n",registro->num1);
        printf("%d\n",registro->num2);
        printf("%d\n",registro->num3);
        mostrar(registro->sig);
    }
}

int main(){
    nodo *prin;
    prin=(nodo*)malloc(sizeof(nodo));
    cargar(prin);
    mostrar(prin);
    return 0;
}