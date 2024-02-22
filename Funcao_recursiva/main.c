#include <stdio.h>
#include <stdlib.h>

int fatorial(int n);

int main()
{
    int n = 4;

    printf("\nFatorial de 4 é %d", fatorial(n));
}

int fatorial(int n){

if(n == 1){
    return 1;
}
    printf("\nFatorial: %d", n);

    return n * fatorial(n - 1);
    printf("\nNUNCA");
}
