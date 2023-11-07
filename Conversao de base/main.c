#include <stdio.h>
#include <stdlib.h>
#include<locale.h>

int conversaoInteiro(int parteinteira, float numero);

int main()
{
    setlocale(LC_ALL, "");

    float numero, i;
    int parteInteira;

    printf("Digite um n�mero, com at� 2 casas decimais: ");
    scanf("%f", &numero);

    //pegando a parte inteira do n�
    parteInteira = numero;

    conversaoInteiro(parteInteira, numero);
}

int conversaoInteiro(int parteinteira, float numero)
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
    //backup que ser� usado posteriormente
    int l = k;

    //fa�o a c�pia para este vetor, por�m at� a �ltima posi��o significativa, desconsiderando lixos
    //de mem�ria.Por�m eu fa�o o reverse do vetor, pois a convers�o bin�ria � de tr�s para frente
    for(j = 0; j <= k; j++, i--)
    {
        ordemCorreta[j] = conversaoBin[i];
        printf("\n%d", ordemCorreta[j]);
    }

    //DECIMAL
    float parteDecimal = numero - parteinteira;

    printf("\nDecimal (base 10): %.2f", parteDecimal);

    float result_parcial = parteDecimal;

    k++;
    int mantissa = 23 - k;
    int conversaoBinDecimal[mantissa];

    for(i = 0; i < mantissa || result_parcial == 1; i++){
        if(result_parcial > 1){
            result_parcial -= 1.00;
        }
        result_parcial = result_parcial * 2;

        if(result_parcial < 1.00){
            conversaoBinDecimal[i] = 0;
        }
        else{
            conversaoBinDecimal[i] = 1;
        }

        printf("\n%d", conversaoBinDecimal[i]);
    }

    //BIAS
    //EXP. REPRESENTADO = EXP. REAL + BIAS(127)
    int exp_real = 0;
    j = 0;
    for(i = 1; ordemCorreta[j] != 1; j++){
        i++;
    }
    exp_real = k - i;

    int exp_representado = exp_real + 127;

    int bitSinal[8];
    quociente = exp_representado;

    for(i = 0; quociente >= 2 && i < 8; i++)
    {
        bitSinal[i] = quociente % 2;
        quociente = quociente / 2;
    }
    bitSinal[i] = quociente;

    int ordemCorreta2[i];
    k = i;

    for(j = 0; j <= k; j++, i--)
    {
        ordemCorreta2[j] = bitSinal[i];
        printf("\nExpoente: %d", ordemCorreta2[j]);
    }

    //UNINDO OS VETORES DA PARTE INTEIRA COM A DECIMAL
    //ordemCorreta E conversaoBinDecimal
    int mantissaCompleta[23];

    l++;
    printf("\n l: %d", l);
    for(i = 0; i < l; i++){
        mantissaCompleta[i] = ordemCorreta[i];
    }

    j = 0;
    for(i = l; i < 23; i++, j++){
        mantissaCompleta[i] = conversaoBinDecimal[j];
    }

    printf("\nMantissona\n");
    for(i = 0; i < 23; i++){
        printf("%d", mantissaCompleta[i]);
    }
    printf("\n");

    return ordemCorreta;
}
