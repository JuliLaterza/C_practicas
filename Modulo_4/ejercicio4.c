#include <stdio.h>
#include <stdlib.h>

int main() {

    int c, d;
    printf("Ingrese una frase:\n");
    c = getchar();

    while(c != '\n'){
        if(c == 'v'){
            d = getchar();
            if (d == 'l'){
                putchar('b');
                putchar('l');
            }
            else{
                putchar(d);
            }
        }

        if(c != 'v' || d != 'l'){
            putchar(c);
        }
        c = getchar();

    }


    return 0;
}