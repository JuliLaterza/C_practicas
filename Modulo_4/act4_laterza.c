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

        while (c != ' ' && c != '\n') {
        
            ultLetra = c;
            sum_long++;


            if (c == 'a' || c == 'A') {
                a++;
            } else if (c == 'e' || c == 'E') {
                e++;
            } else if (c == 'i' || c == 'I') {
                i++;
            } else if (c == 'o' || c == 'O') {
                o++;
            } else if (c == 'u' || c == 'U') {
                u++;
            }
            contLetras++;
            c = getchar();
        }

        if (a > 0 && e > 0 && i > 0 && o > 0 && u > 0) {
            todasVocales = 1;
        } else {
            todasVocales = 0;
        }

        if (todasVocales == 1) {
            if (contLetras % 2 == 0) {
                cantPalabras++;
            }
        }


        if((prim == 'A' || prim == 'a') && (ultLetra =='n' || ultLetra == 'N' )){
            acum_long = acum_long + sum_long;
            palabrasAN++;
        }

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
    
    
    printf("\nLa cantidad de palabras que tiene todas las vocales y su longitud es par son: %d", cantPalabras);
    if(palabrasAN > 0){
        promedio = acum_long/palabrasAN;
        printf("\nAcumulador de longitudes %d", acum_long);
        printf("\nPalabras que cumplen la condicion %d", palabrasAN);
        printf("\nEl promedio es: %.2f", promedio);
    }else{
        printf("\nNo hay palabras que empiecen con N y terminen con Z.");
    }
    return 0;
}
