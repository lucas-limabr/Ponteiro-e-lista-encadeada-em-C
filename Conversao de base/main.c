#include <stdio.h>
#include <stdlib.h>
#include<locale.h>
#include<math.h>

int conversaoInteiro(int parteinteira, float numero);

int main()
{
    setlocale(LC_ALL, "");

    float numero, i;
    int parteInteira;

    printf("Digite um número, com até 2 casas decimais: ");
    scanf("%f", &numero);

    //pegando a parte inteira do nº
    parteInteira = numero;

    conversaoInteiro(parteInteira, numero);
}

int conversaoInteiro(int parteinteira, float numero)
{
    //fazendo o módulo da parte inteira
    int conversaoBin[22], i, quociente = abs(parteinteira);

    //CONVERSÃO BINÁRIA DA PARTE INTEIRA
    for(i = 0; quociente >= 2; i++)
    {
        conversaoBin[i] = quociente % 2;
        quociente = quociente / 2;
    }
    conversaoBin[i] = quociente;

    int j, k = i;
    //backup que será usado posteriormente
    int l = k;

    if(parteinteira == 1)
    {
        i++;
    }
    //criei o vetor que terá exatamente a msm quantidade de bits da conversão
    int ordemCorreta[i];

    //faço a cópia para este vetor, porém até a última posição significativa, desconsiderando as
    //posições que não foram preechidas no vetor conversaoBin.Porém eu faço o reverse do vetor,
    //pois a conversão binária é de trás para frente
    for(j = 0; j <= k; j++, i--)
    {
        ordemCorreta[j] = conversaoBin[i];
        printf("\n%d", ordemCorreta[j]);
    }



    //CONVERSÃO BINÁRIA DA PARTE DECIMAL
    float parteDecimal = fabs(numero) - (abs(parteinteira));

    //IMPORTANTÍSSIMO: delimitar que são 2 casas decimais, pois o C gera lixo nas
    //  últimas casas decimais de um número
    parteDecimal = floorf(parteDecimal * 1000) / 1000;

    printf("\nDecimal (base 10): %.2f", parteDecimal);

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

    //APENAS PARA EXIBIÇÃO
    for(i = 0; i < mantissa; i++)
    {
        printf("\nConversão da parte decimal: %d", conversaoBinDecimal[i]);
    }

    //BIAS
    //EXP. REPRESENTADO = EXP. REAL + BIAS(127)
    int exp_real = 0;
    j = 0;
    for(i = 0; ordemCorreta[j] != 1; j++)
    {
        i++;
    }
    //backup de i mais um, será usado posteriormente
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

    for(j = 0; j < 8; j++, i--)
    {
        ordemCorreta2[j] = bitSinal[i];
        printf("\nExpoente: %d", ordemCorreta2[j]);
    }

    //UNINDO OS VETORES DA PARTE INTEIRA COM A DECIMAL
    //ordemCorreta E conversaoBinDecimal
    int mantissaCompleta[23];

    printf("\n l: %d", l);
    j = 0;
    for(i = auxiliar; i < l; i++, j++)
    {
        mantissaCompleta[j] = ordemCorreta[i];
    }

    i = 0;
    for(j; j < 23; j++, i++)
    {
        mantissaCompleta[j] = conversaoBinDecimal[j];
    }

    printf("\nMantissona\n");
    for(i = 0; i < 23; i++)
    {
        printf("%d", mantissaCompleta[i]);
    }
    printf("\n");

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

    for(i = 0; i < 32; i++)
    {
        printf("\nMantissa e expoente: %d", mantissa_e_sinal[i]);
    }

    return ordemCorreta;
}
