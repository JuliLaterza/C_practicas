#include <stdio.h>

int numEspejo(int num, int invertido) {
    
    if (num == 0) {
        return invertido;
    }
    int ultNum = num % 10;
    
    invertido = (invertido * 10) + ultNum;
    printf("\n%d",invertido);
    return numEspejo(num / 10, invertido);
}

int main() {
    int numero, numeroEspejo;
    
    printf("Ingrese un número: ");
    scanf("%d", &numero);
    
    numeroEspejo = numEspejo(numero, 0);
    
    printf("El número espejo de %d es: %d\n", numero, numeroEspejo);
    
    return 0;
}
