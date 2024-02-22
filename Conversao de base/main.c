#include <stdio.h>
#include <stdlib.h>
#include<locale.h>
#include<math.h>

int conversaoInteiro(int parteinteira, float numero);

int main()
{
    setlocale(LC_ALL, "");

    float numero, i;
    int parteInteira, continuar;

    printf("\tConversor de n�mero decimal em um bin�rio de PFPS (Ponto flutunate de precis�o simples) - 32bits");
    printf("\n\t---------------------------------------------------------------------------------------------\n\n");

    do
    {
        printf("\tDigite um n�mero, com at� 2 casas decimais: ");
        scanf("%f", &numero);

        //pegando a parte inteira do n�
        parteInteira = numero;

        conversaoInteiro(parteInteira, numero);

        printf("\n\tVc quer continuar? [1]Sim / [0]N�o: ");
        scanf("%d", &continuar);
    }while(continuar == 1);

}

int conversaoInteiro(int parteinteira, float numero)
{
    //fazendo o m�dulo da parte inteira
    int conversaoBin[22], i, quociente = abs(parteinteira);

    //CONVERS�O BIN�RIA DA PARTE INTEIRA
    for(i = 0; quociente >= 2; i++)
    {
        conversaoBin[i] = quociente % 2;
        quociente = quociente / 2;
    }
    conversaoBin[i] = quociente;

    int j, k = i;
    //backup que ser� usado posteriormente
    int l = k;

    if(abs(parteinteira) == 1)
    {
        //incremento apenas para declarar o vetor
        i++;
    }
    //criei o vetor que ter� exatamente a msm quantidade de bits da convers�o
    int ordemCorreta[i];

    j = 0;
    if(abs(parteinteira) == 1)
    {
        ordemCorreta[0] = conversaoBin[0];
    }
    else
    {

        //fa�o a c�pia para este vetor, por�m at� a �ltima posi��o significativa, desconsiderando as
        //posi��es que n�o foram preechidas no vetor conversaoBin.Por�m eu fa�o o reverse do vetor,
        //pois a convers�o bin�ria � de tr�s para frente
        for(j; j <= k; j++, i--)
        {
            ordemCorreta[j] = conversaoBin[i];
        }
    }

    //CONVERS�O BIN�RIA DA PARTE DECIMAL
    float parteDecimal = fabs(numero) - (abs(parteinteira));

    //IMPORTANT�SSIMO: delimitar que s�o 2 casas decimais, pois o C gera lixo nas
    //  �ltimas casas decimais de um n�mero
    parteDecimal = roundf(parteDecimal * 100) / 100;

    float result_parcial = fabs(parteDecimal);

    int mantissa = 23 - k;
    int conversaoBinDecimal[mantissa];

    for(i = 0; i < mantissa; i++)
    {
        if(result_parcial == 1.00)
        {
            for(i; i < mantissa; i++)
            {
                conversaoBinDecimal[i] = 0;
            }
            break;
        }

        if(result_parcial > 1)
        {
            result_parcial -= 1.00;
        }
        result_parcial = result_parcial * 2;

        if(result_parcial < 1.00)
        {
            conversaoBinDecimal[i] = 0;
        }
        else
        {
            conversaoBinDecimal[i] = 1;
        }
    }

    //BIAS
    //EXP. REPRESENTADO = EXP. REAL + BIAS(127)
    int exp_real = 0;
    j = 0;

    if(abs(parteinteira))
    {
        for(i = 0; ordemCorreta[j] != 1; j++)
        {
            i++;
        }
    }
    else
    {
        for(i = 0; conversaoBinDecimal[j] != 1; j++)
        {
            i++;
        }
        i++;
    }

    //backup de i mais um, ser� usado posteriormente
    int auxiliar = (i + 1);
    exp_real = k - i;

    int exp_representado = exp_real + 127;

    int bitSinal[8];
    quociente = exp_representado;

    for(i = 0; quociente >= 2 && i < 7; i++)
    {
        bitSinal[i] = quociente % 2;
        quociente = quociente / 2;
    }
    bitSinal[i] = quociente;

    if(i == 6)
    {
        i++;
        bitSinal[i] = 0;
    }

    int ordemCorreta2[8];

    if(numero >= 0)
    {
        printf("\n\tBIT DE SINAL = 0");
    }
    else
    {
        printf("\n\tBIT DE SINAL = 1");
    }

    printf("\n\tBITS DE EXPOENTE(8) = ");
    for(j = 0; j < 8; j++, i--)
    {
        ordemCorreta2[j] = bitSinal[i];
        printf("%d", ordemCorreta2[j]);
    }

    //UNINDO OS VETORES DA PARTE INTEIRA COM A DECIMAL
    //ordemCorreta E conversaoBinDecimal
    int mantissaCompleta[23];
    j = 0;

    for(i = auxiliar; i <= l; i++, j++)
    {
        mantissaCompleta[j] = ordemCorreta[i];
    }
    printf("\n");

    i = 0;

    for(j; j < 23; j++, i++)
    {
        mantissaCompleta[j] = conversaoBinDecimal[i];
    }

    printf("\tBITS DA MANTISSA(23) = ");
    i = 0;

    while(i < 23)
    {
        printf("%d", mantissaCompleta[i]);
        i++;
    }

    //UNINDO MANTISSA, BITS DO EXPOENTE E BIT DO SINAL
    // mantissaCompleta e ordemCorreta2
    int mantissa_e_sinal[32];


    if(numero >= 0)
    {
        mantissa_e_sinal[0] = 0;
    }
    else
    {
        mantissa_e_sinal[0] = 1;
    }

    j = 0;
    i = 1;

    while(j < 8)
    {
        mantissa_e_sinal[i] = ordemCorreta2[j];
        j++;
        i++;
    }

    j = 0;

    while(i < 32)
    {
        mantissa_e_sinal[i] = mantissaCompleta[j];
        i++;
        j++;
    }

    printf("\n\tBIN�RIO DE 32 BITS CORRESPONDENTE = ");
    for(i = 0; i < 32; i++)
    {
        printf("%d", mantissa_e_sinal[i]);
    }

    printf("\n");

    return ordemCorreta;
}
