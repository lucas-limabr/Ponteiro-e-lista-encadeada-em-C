#include <stdio.h>
#include <stdlib.h>
#include<locale.h>

#define MAX 5
void leSalario(float *salario);
void exibeSalario(float *salario);
void reajustaSalario(float *salario, float percentual);

int main()
{
    setlocale(LC_ALL, "");

    float *salario = (float*)malloc(sizeof(salario) * MAX);

    leSalario(salario);
    exibeSalario(salario);
    reajustaSalario(salario, 1.1);
    printf("\n");
    exibeSalario(salario);
    printf("\n");
}

void leSalario(float *salario)
{
    int i;

    for(i = 0; i < MAX; i++)
    {
        printf("\nInforme o %d salário: ", i +1);
        scanf("%f", (salario + i));
    }
}

void exibeSalario(float *salario)
{
    int i;

    for(i = 0; i < MAX; i++)
    {
        printf("\nSalário %d: %.2f", i + 1, *(salario + i));
    }
}

void reajustaSalario(float *salario, float percentual){
    int i;

    for(i = 0; i < MAX; i++){
       *(salario + i) = *(salario + i) * percentual;
    }
}
