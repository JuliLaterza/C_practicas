#include <stdio.h>
#include <stdlib.h>


typedef struct anio {
    int anio;
    struct cotiza *cab;
    struct anio *sig;
}nodoA;


typedef struct cotiza {
    char mes[10];
    float dolar;
    struct cotiza *sigC;
}nodoB;



//Creamos las funciones principales.

void ingresarAnio(nodoA *p);
void mostrarCotizacion(nodoA *p);
void cargarCotiza(nodoB *registro);

int main(){

    nodoA *p = NULL;

    p = (nodoA *)malloc(sizeof(nodoA));
    cargarCotiza(p);
    mostrarCotizacion(p);

    return 0;
}

void ingresarAnio(nodoA *p){
    
    if(p!=NULL){
        printf("\nIngresar año: ");
        scanf("%f", p->anio);
        p->cab = (nodoB *)malloc(sizeof(nodoB));
        cargarCotiza(registro->cab);
        p->sig = (nodoA *)malloc(sizeof(nodoA));
        ingresarAnio(p->sig);
    }
}