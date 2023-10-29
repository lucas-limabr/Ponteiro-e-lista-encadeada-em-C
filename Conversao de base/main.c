#include <stdio.h>
#include <stdlib.h>
#include<locale.h>

int conversaoInteiro(int parteinteira);

int main()
{
    setlocale(LC_ALL, "");

    float numero, i;
    int parteInteira, l;

    printf("Digite um número, com até 2 casas decimais: ");
    scanf("%f", &numero);

    //pegando a parte inteira do nº
    parteInteira = numero;

    conversaoInteiro(parteInteira);
}

int conversaoInteiro(int parteinteira)
{
    int conversaoBin[23], i, quociente = parteinteira;

    for(i = 0; quociente >= 2; i++)
    {
        conversaoBin[i] = quociente % 2;
        quociente = quociente / 2;
    }
    conversaoBin[i] = quociente;

    //criei o vetor que terá exatamente a msm quantidade de bits da conversão
    int ordemCorreta[i];
    int j, k = i;

    //faço a cópia para este vetor, porém até a última posição significativa, desconsiderando lixos
    //de memória.Porém eu faço o reverse do vetor, pois a conversão binária é de trás para frente
    for(j = 0; j <= k; j++, i--)
    {
        ordemCorreta[j] = conversaoBin[i];
        printf("\n%d", ordemCorreta[j]);
    }

    return ordemCorreta;
}
