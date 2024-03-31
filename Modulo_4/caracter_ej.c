#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int c, cant, long_palabra;
    
    printf("Ingrese una frase y un . para finalizar: ");
    c = getchar();
    while(c != '.'){
        
        if (c == ' ' || c == '.'){  //Codigo fundamental para hacer la separacion de palabras.
            if(long_palabra > 3){
                cant++;
            }
            long_palabra = 0;
        }else{
            long_palabra++; //aumenta el incremento de la long, porque no es igual a espacio.
        }
        
        c = getchar();
    }
    if(long_palabra > 3){
        cant++;
    }
    printf("\nCantidad de palabras mayores a 3 de long: %d ", cant);
    return 0;
}
