#include <stdio.h>
#include <stdlib.h>
#include<locale.h>

int conversaoInteiro(int parteinteira);

int main()
{
    setlocale(LC_ALL, "");

    float numero, i;
    int parteInteira, l;

    printf("Digite um n�mero, com at� 2 casas decimais: ");
    scanf("%f", &numero);

    //pegando a parte inteira do n�
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

    //criei o vetor que ter� exatamente a msm quantidade de bits da convers�o
    int ordemCorreta[i];
    int j, k = i;

    //fa�o a c�pia para este vetor, por�m at� a �ltima posi��o significativa, desconsiderando lixos
    //de mem�ria.Por�m eu fa�o o reverse do vetor, pois a convers�o bin�ria � de tr�s para frente
    for(j = 0; j <= k; j++, i--)
    {
        ordemCorreta[j] = conversaoBin[i];
        printf("\n%d", ordemCorreta[j]);
    }

    return ordemCorreta;
}
