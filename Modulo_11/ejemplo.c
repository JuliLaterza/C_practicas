#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct listaR {
    char nomplaylist[40];
    struct listaC *cab;
    struct listaR *sig;
} nodoR;

typedef struct listaC {
    char nomcancion[40];
    char artista[40];
    struct listaC *sigC;
} nodoC;

void mostrarlista(nodoR *);
void cargarPlaylist(nodoR *);
void crearCanciones(nodoC *);
void mostrarCancion(nodoC *);

int main() {
    nodoR *p = NULL;
    
    p = (nodoR *)malloc(sizeof(nodoR));
    cargarPlaylist(p);
    mostrarlista(p);

    return 0;
}

void cargarPlaylist(nodoR *r) {
    printf("\nIngresar nombre de la playlist o una x para finalizar: ");
    scanf("%s", r->nomplaylist);
    if (strcmp(r->nomplaylist, "x") == 0) {
        r->sig = NULL;
        return;
    } else {
        r->cab = (nodoC *)malloc(sizeof(nodoC));
        crearCanciones(r->cab);
        r->sig = (nodoR *)malloc(sizeof(nodoR));
        cargarPlaylist(r->sig);
    }
}

void crearCanciones(nodoC *r) {
    printf("\nIngresar nombre de la canción o una x para finalizar: ");
    scanf("%s", r->nomcancion);
    if (strcmp(r->nomcancion, "x") == 0) {
        r->sigC = NULL;
        return;
    } else {
        printf("\nIngrese el nombre del artista: ");
        scanf("%s", r->artista);
        r->sigC = (nodoC *)malloc(sizeof(nodoC));
        crearCanciones(r->sigC);
    }
}

void mostrarlista(nodoR *reg) {
    while (reg != NULL) {
        printf("\nPlaylist: %s\n", reg->nomplaylist);
        mostrarCancion(reg->cab);
        reg = reg->sig;
    }
}

void mostrarCancion(nodoC *reg) {
    while (reg != NULL) {
        printf("\nCanción: %s\n", reg->nomcancion);
        printf("\nArtista: %s\n", reg->artista);
        reg = reg->sigC;
    }
}
