#include <stdio.h>


int factorial(int n) {
    // Caso base: si n es igual a 0, el factorial es 1
    if (n == 0) {
        return 1;
    }
    // Caso recursivo: multiplicar n por el factorial de n-1
    else {
        return n * factorial(n - 1);
    }
}


int fibonacci(int n) {
    // Caso base: si n es igual a 0 o 1, el resultado es n
    if (n == 0 || n == 1) {
        return n;
    }
    // Caso recursivo: sumar los dos números anteriores en la secuencia de Fibonacci
    else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}



int main() {

    int n;
    printf("Ingrese un numero: ");
    scanf("%d", &n);
    printf("El factorial de %d es %d\n", n, factorial(n));

    printf("Los primeros %d números de la secuencia de Fibonacci son:\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
    
    return 0;
}
