#include <stdio.h>


int main(){
    /*
    char c;
    printf("Ingrese un caracter: ");
    c = getchar();
    printf("\n%d ", c);
    putchar(c);
    */

    int c;
    printf("Ingrese una palabra y que termine con punto\n");
    c = getchar(); //ingresamos la palabra
    while(c != '.') {
        putchar(c);
        c = getchar();
    }   
    return 0;
}