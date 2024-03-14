#include <stdio.h>

int main() {

    int num,cant, cond_nums, acum, promedio,min_num;

    cond_nums = 0;
    acum = 0;
    min_num =99999999;
    cant = 0;

    printf("Ingrese un numero positivo o negativo para finalizar: \n");
    scanf("%d", &num);
    while(num > 0) {
        
        if (4 < num < 25){
            cond_nums += 1;
        }

        if (num < min_num) {
            min_num = num;
        }

        if (num%6 == 0) {
            acum += num;
            cant += 1;
        }
        printf("Ingrese un numero positivo o negativo para finalizar: \n");
        scanf("%d", &num);
    }
    printf("La cantidad de numeros mayores a 4 y menores a 25 son %d",cond_nums);
    printf("\nEl promedio es de %d", acum/cant);
    printf("\nEl valor minimo es %d", min_num);
    return 0;
}