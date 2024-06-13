#include <stdlib.h>
#include <stdio.h>


typedef struct arbol {
    int dato;
    struct arbol *izq;
    struct arbol *der;
}treenode;


void crear( treenode **hoja) {
    int numero;
    
    printf("Ingrese un numero: ");
    scanf("%d", &numero);
    while (numero != -1){
        insertar(hoja, numero);
        printf("Ingrese un numero: ");
        scanf("%d", &numero);
    }
}

void insertar(treenode **hoja, int elem){
    if (elem == -1){
        return;
    }
    if (*hoja == NULL ){
        *hoja = (treenode*)malloc(sizeof(treenode));
        (*hoja)->dato = elem;
        (*hoja)->izq = NULL;
        (*hoja)->der = NULL;
    }else {
        if(elem > (*hoja)->dato){
            insertar(&(*hoja)->der,elem);
        }else{
            insertar(&(*hoja)->izq, elem);
        }
    }
    return;
}

void mostrar(treenode *hoja){
    if(hoja != NULL){
        mostrar(hoja->izq);
        printf("%d ",hoja->dato);
        mostrar(hoja->der);
    }
    return;
}


int main(){

    treenode* arbol = NULL; // Siempre arrancando con la cabecera en NULL

    crear(&arbol);

    mostrar(arbol);


    return 0;
}