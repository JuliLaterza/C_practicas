// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>


typedef struct lista {
    
    int num1;
    int num2;
    
    struct lista *sig;
}nodo;


void crear(nodo *registro){
    
    printf("Ingrese un número A: ");
    scanf("%d", &registro->num1);
    printf("Ingrese un numero B: ");
    scanf("%d",&registro->num2);
    if (registro->num1 ==0 && registro->num2 == 0){
        registro->sig == NULL;
    }else{
        registro->sig = (nodo*)malloc(sizeof(nodo));
        crear(registro->sig);
    }
}


void mostrar(nodo *registro){
    if(registro != NULL){
        printf("%d | ",registro->num1);
        printf("%d",registro->num2);
        printf("\n");
        mostrar(registro->sig);
    }
}


void insertar(nodo *registro){
    nodo *aux;
    
    while(registro->sig != NULL){
        if(registro->sig->num1 + registro->sig->num2 >= 4){
            aux = (nodo*)malloc(sizeof(nodo));
            aux->num1 = registro->sig->num1 *-1;
            aux->num2 = registro->sig->num2 *-1;
            
            aux->sig = registro->sig->sig;
            registro->sig = aux;
            registro = registro->sig->sig;
        }else{
            registro = registro->sig;
        }
    }
}

nodo *insertar1(nodo *registro) {
    nodo *aux = registro; // Apuntador auxiliar para recorrer la lista

    while (aux != NULL) { // Iterar sobre todos los nodos de la lista
        if (aux->num1 + aux->num2 >= 4) { // Verificar la condición de inserción
            nodo *nuevo_nodo = (nodo*)malloc(sizeof(nodo)); // Crear nuevo nodo
            nuevo_nodo->num1 = aux->num1 * -1; // Asignar valores al nuevo nodo
            nuevo_nodo->num2 = aux->num2 * -1;
            nuevo_nodo->sig = aux->sig; // Enlazar nuevo nodo con el siguiente nodo
            aux->sig = nuevo_nodo; // Enlazar nodo actual con el nuevo nodo
            aux = nuevo_nodo->sig; // Avanzar al siguiente nodo en la lista
        } else {
            aux = aux->sig; // Avanzar al siguiente nodo
        }
    }

    return registro; // Devolver el puntero al inicio de la lista
}



int main() {
    nodo *prin;
    //nodo2 = (nodo*)malloc(sizeof(nodo));
    prin = (nodo *)malloc(sizeof(nodo));
    
    crear(prin);
    //mostrar(prin);
    //insertar(prin);
    //mostrar(prin);
    
    prin = insertar1(prin);
    mostrar(prin);

    return 0;
}