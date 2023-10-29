#include <stdio.h>
#include <stdlib.h>
#include<locale.h>

int main()
{
    setlocale(LC_ALL, "");

    int numero = 20;
    int *ponteiro = &numero;
    /*O ponteiro está apontando para o local de memória da variável numero*/

    printf("Conteúdo de número: %d\n", numero);
    printf("Endereço de memória de número: %d\n", &numero);
    printf("Conteúdo de ponteiro: %d\n", ponteiro);
    printf("Conteúdo que o ponteiro aponta(referencia): %d\n", *ponteiro);
}
