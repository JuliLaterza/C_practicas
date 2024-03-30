#include <stdio.h>
#include <stdlib.h>

int main() {
    int c, aux, prin, cont;
    cont = 0;
    prin = '\0'; // Inicializar prin con un valor que no sea un espacio en blanco

    printf("Ingrese una frase con un . para finalizar: ");
    c = getchar();

    while(c != '.') {
        // Leer caracteres hasta encontrar el comienzo de una palabra
        while(c == ' ') {
            c = getchar();
        }
        
        // Almacenar el primer carácter de la palabra
        prin = c;

        // Leer caracteres hasta encontrar el final de la palabra
        while(c != ' ' && c != '.') {
            aux = c;
            c = getchar();
        }

        // Incrementar cont si el último carácter de la palabra anterior es igual al primer carácter de la palabra actual
        if(prin == aux) {
            cont++;
        }

        // Leer el siguiente carácter si no se ha llegado al final de la frase
        if(c != '.') {
            c = getchar();
        }
    }

    printf("\nLa cantidad de palabras que terminan con la misma letra son: %d\n", cont);

    return 0;
}
