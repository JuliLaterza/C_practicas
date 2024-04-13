#include <stdio.h>

int f(int x) {
    if (x > 100)
        return (x - 10);
    else
        return (f(f(x + 11)));
}

int main() {
    int a = 99;
    printf("%d", f(a));
    return 0;
}
