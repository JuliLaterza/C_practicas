#include <stdio.h>

int sumarDigitos(int numero) {
    if (numero == 0) {
        return 0;
    } else {
        return (numero % 10) + sumarDigitos(numero / 10);
    }
}

int main() {

    int numero;
    printf("Ingrese un numero: ");
    scanf("%d", &numero);
    printf("La suma de los digitos de %d es %d\n", numero, sumarDigitos(numero));

    return 0;
}
