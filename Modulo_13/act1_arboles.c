#include <stdlib.h>
#include <stdio.h>

typedef struct arbol{
    int num;
    struct arbol* izq;
    struct arbol* der;
}treenode;



void crear (treenode **hoja);
void insertar(treenode **hoja, int elem);
void mostrar (treenode *hoja);


int main (){
    printf ("Actividad 1:\n");
    treenode* arbol=NULL;

    crear(&arbol);
    printf ("**************\n");
    printf ("mostrar arbol\n");
    printf ("***************\n");
    mostrar (arbol);

    maximo = buscarMaximo(arbol);
    printf("\n%d ", maximo);

    return 0;
}

void crear (treenode **hoja){
    int numero;

    printf ("ingrese numero\n");
    scanf ("%d",&numero);
    while (numero!=-1)
    {

        insertar(&(*hoja),numero);
        printf ("ingrese numero\n");
        scanf ("%d",&numero);
    }
}


void insertar (treenode **hoja,int elem){
    int numero=elem;
    if (elem==-1)
        return;
    if (*hoja==NULL)
    {
        //creo la hoja vacia
        (*hoja)=(treenode*)malloc(sizeof(treenode));
        (*hoja)->num=elem;
        (*hoja)->der=NULL;
        (*hoja)->izq=NULL;
    }else{
            
        if (numero>(*hoja)->num){

            insertar (&(*hoja)->der,elem);

        }else{

            insertar (&(*hoja)->izq,elem);
        }
    }
    return;
}

treenode* buscarMaximo(treenode* nodo){
    Nodo* actual = nodo;
    while(actual && actual->der != NULL){
        actual = actual->der;
    }
    return actual;
}


void mostrar (treenode *hoja){
    if (hoja!=NULL)
    {

        mostrar(hoja->izq);
        printf("%d ",hoja->num);
        mostrar(hoja->der);

    }
    return;
}


