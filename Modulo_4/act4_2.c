#include <stdio.h>
#include <stdlib.h>

int main() {
    int c, a, e, i, o, u, todasVocales, contLetras, cantPalabras, prim, ultLetra, sum_long, acum_long, palabrasAN;
    float promedio;
    a = 0;
    e = 0;
    i = 0;
    o = 0;
    u = 0;
    todasVocales = 0;
    contLetras = 0;
    cantPalabras = 0;
    sum_long = 0;
    palabrasAN = 0;
    printf("Ingresar una frase: ");
    
    c = getchar();

    while (c != '\n') {
        prim = c;
        ultLetra = c;
        putchar(prim);
        printf("\n");
        while (c != ' ' && c != '\n') {
            printf("\n");
            putchar(c);
            ultLetra = c;
            sum_long++;
            c = getchar();
        }
        cantPalabras++;
        printf("\nLongitud de la palabra: %d", sum_long);
        if((prim == 'A' || prim == 'a') && (ultLetra =='n' || ultLetra == 'N' )){
            acum_long = acum_long + sum_long;
            palabrasAN++;
        }else{
            printf("\nNo cumple.");
        }
        
        
        
        
        
        
        // Reiniciar contadores
        sum_long = 0;
        a = 0;
        e = 0;
        i = 0;
        o = 0;
        u = 0;
        
        contLetras = 0;
        
        if (c != '\n') {
            c = getchar();
        }
        
    }
    promedio = acum_long/palabrasAN;
    printf("\nCantidad de palabras %d", cantPalabras);
    printf("\nAcumulador de longitudes %d", acum_long);
    printf("\nPalabras que cumplen la condicion %d", palabrasAN);
    printf("\nEl promedio es: %.2f", promedio);
    //printf("\nLa cantidad de palabras que tiene todas las vocales y su longitud es par son: %d", cantPalabras);
    return 0;
}