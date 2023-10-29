#include <stdio.h>
#include <stdlib.h>

float calculaFaturamento(float *valor_vendas, int qtd_vendas);

int main()
{
    int qtd_vendas, i;

    printf("Qual e a quantidade de vendas? ");
    scanf("%d", &qtd_vendas);

    float *p = (float*) malloc(sizeof(float) * qtd_vendas);

    for(i = 0; i<qtd_vendas; i++){
        printf("Digite o valor da %d venda: ", i + 1);
        scanf("%f", p + i); //&*(p + i)
    }

    printf("\nO faturamento total foi de R$%.2f reais", calculaFaturamento(p, qtd_vendas));
}

float calculaFaturamento(float *valor_vendas, int qtd_vendas){

    int i;
    float faturamento_total = 0;


    for(i = 0; i < qtd_vendas; i++){
        faturamento_total += *(valor_vendas + i);
    }

    return faturamento_total;
}
