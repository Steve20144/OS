#include <stdio.h>

int add(int *a, int *b, int *c) {
    return *a + *b + *c;
}

int main() {
    int x = 1, y = 2, z = 3;
    printf("Sum: %d\n", add(&x, &y, &z));
    return 0;
}