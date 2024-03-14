#include <stdio.h>

int main() {
    int vec[3];
    int i = 0;

    for (i = 0; i < 3; i++) {
        printf("Ingrese un numero: \n");
        scanf("%d", &vec[i]);
    }
    printf("\n");
    for (i = 0; i < 3; i++) {
        printf("%d\n", vec[i]);
    }
    return 0;
}