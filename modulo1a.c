#include <stdio.h>

int main() {
    int cant_num_malvados = 0; int numero = 0;
    float promedio = 2.5;
    while (cant_num_malvados < 4) {
        if (numero % 2 == 0 || numero % 3 == 0 || numero % 5 == 0 || numero % 7 == 0) {
            cant_num_malvados++;
            printf("%d\n", numero);
        }
        numero++;
    }

    return 0;
}
