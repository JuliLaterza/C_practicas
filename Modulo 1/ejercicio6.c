#include <stdio.h>
#include <stdlib.h>

int main(){
    int num,lotes,cont,acum,min,contpares=0, i;

    printf("Ingrese un numero: \n");
    scanf("%d", &num);

    while (num > 0) {
        
        if (num % 2 == 0) {
            contpares += 1;
        }
        printf("Ingrese un numero de lote: \n");
        scanf("%d", &lotes);
        min = lotes;

        for (i = 0; i < num-1; i++) {
            acum += lotes;
            cont += 1;
            if(lotes % 2 == 0) {
                contpares += 1;
            }
            if (lotes < min) {
                min = lotes;
            }
            printf("Ingrese un numero de lote: \n");
            scanf("%d", &lotes);
        }
        printf("El promedio de los lotes es %d", acum/cont);
        printf("\nEl valor minimo de este lote es %d", min);
    }
    printf('\nLa cantidad de cont es %d', cont);
    printf("La cantidad total de pares leidos es de %d", contpares);
}