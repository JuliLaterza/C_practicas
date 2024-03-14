#include <stdio.h>

int main() {
    
    int edad,prom_edad,acum_edad,cant_edad,cant_Mayores,acum_Mayores;
    float prom_mas10,porc15,porc1520,porc20,sueldo,promMayores,cant_15,cant_1520,cant_20,cant_total;
    cant_edad = 0;
    acum_edad = 0;
    cant_total =0;
    printf("Ingrese edad del empleado: \n");
    scanf("%d",&edad);
    printf("Ingrese sueldo del empleado: \n");
    scanf("%f",&sueldo);
    while(edad != 0 && sueldo != 0 ) {
        

        if (sueldo>10000){
            cant_edad += 1;
            acum_edad += edad;
        }

        if(edad > 58){
            printf("\nSueldo con 5 porciento mas por edad %.2f",sueldo*1.05);
        }

        if( sueldo < 15000){
            cant_15 += 1;
        }else if (15000 <= sueldo && sueldo < 20000) {
            cant_1520 += 1;
        }else {
            cant_20 += 1;
        }
        cant_total += 1;

        printf("Ingrese edad del empleado: \n");
        scanf("%d",&edad);
        printf("Ingrese sueldo del empleado: \n");
        scanf("%f",&sueldo);

    }
    prom_mas10 = (acum_edad/cant_edad)*100;
    printf("El promedio de edad de las personas que ganan mas de 10000 es %.2f", prom_mas10);
    printf("\nEl porcentaje de empleados cuyo sueldo es menor a 15 mil es: %.2f", (cant_15/cant_total)*100);
    printf("\nEl promedio de empleados cuyo sueldo esta entre 15 y 20mil es: %.2f", (cant_1520/cant_total)*100);
    printf("\nEl promedio de empleados cuyo sueldo es mayor a 25 mil es: %.2f", (cant_20/cant_total)*100);
    return 0;
}