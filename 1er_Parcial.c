#include <stdio.h>

#include <string.h>

#include <stdlib.h>



typedef struct lista{
    int anio;
    char mes[40];
    float blue;
    float mep;
    struct lista *sig;
}nodo;



typedef struct lista2{
    int anio;
    char mes[40];
    float diferencia;
    struct lista2 *sig;

}nodo2;



void crear (nodo *p){
    printf("Ingrese el anio: ");
    scanf("%d",&p->anio);

    if (p->anio==0){
    
        p->sig=NULL;

    } else {

        printf("Ingrese el mes: ");

        scanf("%s", p->mes);

        printf("Ingrese la cotizacion del dolar blue: ");

        scanf("%f", &p->blue);

        printf("Ingrese la cotizacion del dolar mep: ");

        scanf("%f", &p->mep);

        p->sig=(nodo*)malloc(sizeof(nodo));

        crear(p->sig);
    }



}



void mostrar(nodo *p){
    if(p->sig!=NULL){

        printf("\nEl anio es: %d", p->anio);

        printf("\nEl mes es: %s", p->mes);

        printf("\nLa cotizacion del dolar blue es: %.2f", p->blue);

        printf("\nLa cotizacion del dolar mep es: %.2f", p->mep);

        mostrar(p->sig);
  }

}



void calcular(nodo *p){
    int anio_mayor;
    char mes_mayor[40];
    float diferencia;

    anio_mayor=p->anio;
    strcpy(mes_mayor, p->mes);
    diferencia=p->mep-p->blue;
    p=p->sig;

    while(p->sig!=NULL){

        if((p->mep-p->blue) > diferencia){
            anio_mayor=p->anio;
            strcpy(mes_mayor, p->mes);
            diferencia=p->mep-p->blue;
        }
        p=p->sig;
    }

    printf("\nSe registro la mayor diferencia entre el dolar blue y el dolar mep en el mes de %s del anio %d", mes_mayor, anio_mayor);

}


void crear2 (nodo *p, nodo2 *q){

    while(p->sig!=NULL){

        q->anio=p->anio;

        strcpy(q->mes, p->mes);

        q->diferencia=p->mep-p->blue;

        q->sig=(nodo2*)malloc(sizeof(nodo2));

        q=q->sig;

        p=p->sig;

    }
    
    q->sig=NULL;

}



void mostrar2(nodo2 *q){

  if(q->sig!=NULL){

    printf("\nEl anio es: %d", q->anio);

    printf("\nEl mes es: %s", q->mes);

    printf("\nLa diferencia entre el mep y el blue es: %.2f", q->diferencia);

    mostrar2(q->sig);

  }

}





nodo* eliminar(nodo *p, nodo *k){

    nodo *aux=NULL;

    nodo *prin=NULL;


    while((p->mep - p->blue)<200){

        k->anio=p->anio;
        strcpy(k->mes, p->mes);
        
        k->blue=p->blue;
        k->mep=p->mep;

        k->sig=(nodo*)malloc(sizeof(nodo));
        k=k->sig;
        aux=p->sig;

        free(p);

        p=aux;

    }

   

    prin=p;

   

    while(p->sig!=NULL && p->sig->sig!=NULL){

        if((p->sig->mep-p->sig->blue)<200){

            k->anio=p->sig->anio;

            strcpy(k->mes, p->sig->mes);

            k->blue=p->sig->blue;

            k->mep=p->sig->mep;

            k->sig=(nodo*)malloc(sizeof(nodo));

            k=k->sig;

            aux=p->sig->sig;

            free(p->sig);

            p->sig=aux;

        }else {

            p=p->sig;

        }

    }

    k->sig=NULL;

   

  return prin;

}







int main(){

    nodo *prin=NULL;

    nodo2 *prin2=NULL;

    nodo *prin3=NULL;

   

    prin=(nodo*)malloc(sizeof(nodo));

    prin2=(nodo2*)malloc(sizeof(nodo2));

    prin3=(nodo*)malloc(sizeof(nodo));



    

    crear(prin);

    printf("\n\nLista original");

    mostrar(prin);

    calcular(prin);

    crear2(prin, prin2);

    printf("\n\nSegunda lista");

    mostrar2(prin2);

    prin=eliminar(prin, prin3);

    printf("\n\nLista original con eliminacion");

    mostrar(prin);

    printf("\n\nTercer lista");

    mostrar(prin3);

   

}

