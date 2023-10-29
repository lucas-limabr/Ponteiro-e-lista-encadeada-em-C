#include <stdio.h>
#include <stdlib.h>
#include<locale.h>

#define MAX 5

int main()
{
    setlocale(LC_ALL, "");

    float *p = (float*)malloc(sizeof(float) * MAX);

    int i;

    for(i = 0; i < MAX; i++)
    {
        printf("Posição %d no ponteiro: %d\n", i + 1, p+i);
    }

    int *num = (int*)malloc(sizeof(int) * MAX);

    printf("\n");
    for(i = 0; i < MAX; i++)
    {
        printf("\nDigite um número: ");
        scanf("%d", num+i);
    }

    for(i = 0; i < MAX; i++)
    {
        printf("Ordem que o usuário digitou: %d\n", *(num+i));
    }

    printf("\n");
    for(i = (MAX - 1); i >= 0; i--)
    {
        printf("Ordem inversa que o usuário digitou: %d\n", *(num + i));
    }
}
