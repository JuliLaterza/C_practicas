#include <stdio.h>
#include <stdlib.h>

int main() {
    int num,cant_numAbun,cant_numDef, suma, i;
    printf("Ingrese un numero: ");
    scanf("%d", &num);
    cant_numAbun = 0;
    cant_numDef = 0;    

    while (num != 0) {
        suma = 0;
        for (i = 1; i < num; i++) {
            if (num % i == 0) {
                suma += i;
            }
        }
        if (suma > num) {
            cant_numAbun += 1;
        } else {
            cant_numDef += 1;
        }
        printf("Ingrese un numero: ");
        scanf("%d", &num);
    }
    printf("La cantidad de numeros abundantes es: %d", cant_numAbun);
    printf("\nLa cantidad de numeros deficientes es: %d\n", cant_numDef);
    return 0;
}