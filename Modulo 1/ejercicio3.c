#include <stdio.h>

int main() {
    int x,anio, autos, acum,max_cant,mejor_anio;
    printf("Ingrese el año: \n");
    scanf("%d", &anio);
    acum = 0;
    
    max_cant = 0;
    for (x = 0; x <=9; x++){

        printf("Ingrese la cantidad de autos vendidos: \n");
        scanf("\n %d", &autos);
        if(autos > max_cant) {
            max_cant = autos;
            mejor_anio = anio;
        }
        acum += autos;
        anio += 1;
    }
    
    printf("El año que mejor ventas tuvo fue %d",mejor_anio);
    printf("\nLa cantidad total de autos vendidos en 9 años es:%d",acum);

    return 0;
}