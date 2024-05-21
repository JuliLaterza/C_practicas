#include <stdio.h>
#include <stdlib.h>

typedef struct alumno {
    int legajo;
    int edad;
    int cant_mat_cur;
    int cant_mat_aprob;
    int cant_mat_repro;
    struct alumno *sig;
}nodo;

void agregarAlumno(nodo *registro){
    FILE *fp = fopen("alumnos.dat","w");
    if (fp == NULL){
        printf("ERROR al abrir el archivo\n");
    }else{
        while (registro != NULL) {
            if(registro->cant_mat_cur > registro->cant_mat_aprob){
                fprintf(fp,"%d %d %d %d %d\n", registro->legajo,registro->edad,registro->cant_mat_cur,registro->cant_mat_aprob,registro->cant_mat_repro);
            }
            registro = registro->sig;
        }
    }

    fclose(fp);
}


void crear (nodo *registro){
    printf("Ingresar legajo: ");
    scanf("%d", &registro->legajo);

    if (registro->legajo == 0){
        registro -> sig = NULL;
    }else{
        printf("\nIngrese edad: ");
        scanf("%d", &registro->edad);
        printf("\nIngrese Cant Materias cursadas: ");
        scanf("%d", &registro->cant_mat_cur);
        printf("\nIngrese Cant materias aprobadas: ");
        scanf("%d", &registro->cant_mat_aprob);
        printf("\nIngrese Cant materias recursadas: ");
        scanf("%d", &registro->cant_mat_repro);

        registro->sig = (nodo*)malloc(sizeof(nodo));
        crear(registro->sig);
        
    }
}

void mostrar(){
    int legajo, edad, materias_aprobadas, materias_cursadas, materias_reprobadas;
    FILE *fp = fopen("alumnos.dat","r");

    if (fp == NULL) {
        printf("Error al abrir");
    }else{
        while(!feof(fp)){
            fscanf(fp,"%d %d %d %d %d\n", &legajo, &edad, &materias_cursadas, &materias_aprobadas, &materias_reprobadas);
            if(materias_reprobadas == 0 && edad >= 35){
                printf("Legajo: %d \nedad: %d \ncursadas: %d \naprobadas: %d \nreprobadas: %d\n", legajo,edad,materias_cursadas,materias_aprobadas,materias_reprobadas);
            }
        }
    }
    fclose(fp);    
}

int main(){

    nodo *p = NULL;
    p=(nodo*)malloc(sizeof(nodo));

    crear(p);

    agregarAlumno(p);

    mostrar();
    
    return 0;
}