#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<locale.h>

void geraCotacao(float *euro_para_real, float *euro_para_dolar);
int cotacaoMediaReal(float *euro_para_real);
int cotacaoMediaDolar(float *euro_para_dolar);

int main()
{
    setlocale(LC_ALL, "");

    //ponteiro para armazenar a cota��o di�ria do euro em rela��o ao real em 5 anos
    //365 * 5 = 1825 dias
    float *euro_para_real = (float*)malloc(sizeof(float) * 1825);

    //ponteiro para armazenar a cota��o di�ria do euro em rela��o ao d�lar em 5 anos
    float *euro_para_dolar = (float*)malloc(sizeof(float) * 1825);

    if(euro_para_real == NULL || euro_para_dolar == NULL)
    {
        printf("\nN�o foi poss�vel alocar endere�o de mem�ria");
    }
    else
    {

        geraCotacao(euro_para_real, euro_para_dolar);
        int real_acima_media = cotacaoMediaReal(euro_para_real);
        int dolar_acima_media = cotacaoMediaDolar(euro_para_dolar);

        printf("\n\t----- Programa que calcula os dias que a cota��o do real e do d�lar estiveram acima de suas m�dias -----\t\n");
        printf("\tA quantidade de dias em que a cota��o do real em rela��o ao euro esteve acima da m�dia foi de %d dias\t\n", real_acima_media);
        printf("\tA quantidade de dias em que a cota��o do d�lar em rela��o ao euro esteve acima da m�dia foi de %d dias\n", dolar_acima_media);
    }
}

void geraCotacao(float *euro_para_real, float *euro_para_dolar)
{
    int i;

    //vou preencher cada ponteiro com valores rand�micos, pois a entrada de dados � muito grande
    srand(time(NULL));

    for(i = 0; i < 1825; i++)
    {
        //para manter uma certa cor�ncia com a realidade da cota��o, primeiro  eu restringi a sortear
        //n�meros, exatamente no intervalo de 3 a 6 e ap�s isso, eu multipliquei o resultado por um
        //n�mero decimal qualquer, pois na cota��o da realidade sempre aparece pelo menos 2 n�meros
        //ap�s a v�rgula
        *(euro_para_real + i) = (rand() % 4 + 3) * 1.07;
        //printf("\n%.2f", *(euro_para_real + i));

        //aqui, eu sortiei n�meros no intervalo de 1 a 3 e multipliquei por 0,67
        *(euro_para_dolar + i) = (rand() % 3 + 1) * 0.67;
        //printf("\n%.2f", *(euro_para_dolar + i));
    }
}

int cotacaoMediaReal(float *euro_para_real)
{
    int i, dias_acima_media = 0;
    float media = 0;

    for(i = 0; i < 1825; i++)
    {
        media += *(euro_para_real + i);
    }
    media /= 1825;
    //printf("\nM�dia: %.2f", media);

    for(i = 0; i < 1825; i++)
    {
        if(*(euro_para_real + i) > media)
        {
            dias_acima_media++;
        }
    }

    return dias_acima_media;
}

int cotacaoMediaDolar(float *euro_para_dolar)
{
    int i, dias_acima_media = 0;
    float media = 0;

    for(i = 0; i < 1825; i++)
    {
        media += *(euro_para_dolar + i);
    }
    media /= 1825;
    //printf("\nM�dia: %.2f", media);

    for(i = 0; i < 1825; i++)
    {
        if(*(euro_para_dolar + i) > media)
        {
            dias_acima_media++;
        }
    }

    return dias_acima_media;
}
