#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int cod;
    int cant;
    float precio;
    struct lista *sig;    
}nodo;

typedef struct lista2{
    int cod;
    float precio;
    struct lista2 *sig;

}nodo2;

void crear (nodo *registro){
    printf("Ingrese el codigo del articulo: ");
    scanf("%d", &registro->cod);
    if(registro->cod == 0){
        registro->sig == NULL;
    }else{
        printf("\nIngresar cant: ");
        scanf("%d", &registro->cant);
        printf("\nIngresar precio: ");
        scanf("%f", &registro->precio);
        registro->sig = (nodo*)malloc(sizeof(nodo));
        crear(registro->sig);
    }
}


void mostrar( nodo *registro){
    if(registro != NULL && registro->cod != 0){
        printf("%d\n",registro->cod);
        printf("%d\n",registro->cant);
        printf("%f\n",registro->precio);
        printf("-------\n");
        mostrar(registro->sig);
    }else{
        return;
    }
}


void crear_nuevalista(nodo *registro, nodo2 *lista){
    if (registro != NULL){
        lista->cod = registro->cod;
        lista -> precio = registro->precio;

        lista->sig = (nodo2*)malloc(sizeof(nodo2));
        crear_nuevalista(registro->sig,lista->sig);
    }else{
        lista->sig == NULL;
    }
}

void mostrarLista2(nodo2 *lista){
    if (lista != NULL){
        printf("%d\n", lista->cod);
        printf("%f", lista->precio);
        mostrarLista2(lista->sig);
    }
}


nodo* codigo_mayor(nodo *registro){
    int max = 0;
    int cod_max = 0;


    while(registro != NULL){
        if (registro->cant > max){
            max = registro->cant;
            cod_max = registro->cod;
        }else{
            registro = registro->sig;
        }
    }

    return cod_max;
}

void eliminar_mayor(nodo *p, int cod_max, nodo *elim){
    nodo *aux;
    while(p->sig != NULL && p->sig->sig != NULL){
        if (p->sig->cod == cod_max){
            elim->cod = p->sig->cod;
            elim->cant = p->sig->cant;
            elim -> precio = p->sig->precio;
            elim->sig = NULL;

            aux = p->sig->sig;

            free(p->sig);

            p->sig = aux;
        }else{
            p = p->sig;
        }
    }
}

int main(){
    int cod_mayor;
    nodo *prin;
    prin = (nodo *)malloc(sizeof(nodo));
    nodo2 *cab;
    cab = (nodo2 *)malloc(sizeof(nodo2));

    nodo *elim;
    elim = (nodo *)malloc(sizeof(nodo));

    crear(prin);
    mostrar(prin);
    printf("\n");
    cod_mayor = codigo_mayor(prin);
    printf("\nEl codigo mayor es %d",cod_mayor);
    printf("\nLa nueva lista es: \n");
    crear_nuevalista(prin,cab);
    mostrarLista2(cab);
    printf("\n***********");
    printf("Lista sin el mayor\n");
    eliminar_mayor(prin,cod_mayor,elim);
    mostrar(prin);
    printf("\nArticulo con la mayor cantidad eliminado\n");
    mostrar(elim);
}