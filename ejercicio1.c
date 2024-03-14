#include <stdio.h>

 int main() {
    float kilos,altura;
    printf("Ingrese los kilos:\n");
    scanf("%f",&kilos);
    printf("Ingrese la altura: \n");
    scanf("%f",&altura);
    printf("El indice corporal es de %.2f", kilos/altura);
    
    return 0;
}