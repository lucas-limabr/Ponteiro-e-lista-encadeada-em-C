#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n);

int main()
{
    int n;

    printf("Digite o termo (n) da sequência de Fibonacci que vc deseja: ");
    scanf("%d", &n);

    fibonacci(n);

    printf("Termo n corresponde a %d", fibonacci(n));
}

int fibonacci(int n)
{
    if(n==0)
        return 0;
    else if(n==1)
        return 1;
    else
        return fibonacci(n-1) + fibonacci(n-2);
}
