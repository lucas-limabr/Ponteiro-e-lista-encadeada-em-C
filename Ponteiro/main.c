#include <stdio.h>
#include <stdlib.h>
#include<locale.h>

int main()
{
    setlocale(LC_ALL, "");

    int numero = 20;
    int *ponteiro = &numero;
    /*O ponteiro est� apontando para o local de mem�ria da vari�vel numero*/

    printf("Conte�do de n�mero: %d\n", numero);
    printf("Endere�o de mem�ria de n�mero: %d\n", &numero);
    printf("Conte�do de ponteiro: %d\n", ponteiro);
    printf("Conte�do que o ponteiro aponta(referencia): %d\n", *ponteiro);
}
