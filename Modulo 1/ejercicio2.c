// Online C compiler to run C program online
#include <stdio.h>

int main() {
    int dias,max_dia;
    float cotizacion, max_coti=0;
    dias = 1;
    max_dia = 0;
    for (dias=1; dias<=30; dias++){
        printf("Ingrese la cotizacion del día: \n");
        scanf("%f", &cotizacion);
        if (cotizacion > max_coti){
            max_coti = cotizacion;
            max_dia = dias;
        }
    }
    printf("La maxima cotizacion fue el dia %d con un valor de %.2f",max_dia,max_coti);
}
