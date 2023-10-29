#include <stdio.h>
#include <stdlib.h>
#include<locale.h>

void geraNumerosPrimos(int *numeros_primos, int qtd_primos);
int buscaBinaria(int key, int *numeros_primos, int qtd_primos);
void exibirPrimos(int *numeros_primos, int qtd_primos);

int main()
{
    setlocale(LC_ALL, "");
    int qtd_primos, key;
    char resp = 's';

    printf("Digite a quantidade de n�meros primos que o vetor ir� armazenar sequencialmente: ");
    scanf("%d", &qtd_primos);

    int *numeros_primos = (int*)malloc(sizeof(int) * qtd_primos);
    geraNumerosPrimos(numeros_primos, qtd_primos);

    printf("\nAgora, escolha um n�mero para pesquisar se ele existe dentro deste vetor, ");
    printf("o que significa que se tiver, vc descobriu que este � um n�mero primo E est� dentro");
    printf(" da quantidade de valores que vc escolheu para este vetor");

    while(resp =='s' || resp == 'S')
    {
        printf("\nDigite: ");
        scanf("%d", &key);

        int key_procurada = buscaBinaria(key, numeros_primos, qtd_primos);
        if (key_procurada == -1)
        {
            printf("Key n�o encontrada\n");
        }
        else
        {
            printf("Key encontrada: %d\n", key_procurada);
        }

        exibirPrimos(numeros_primos, qtd_primos);
        printf("\nVc deseja procurar uma outra chave neste intervalo que vc escolheu? [n] p/ n�o e [s] p/ sim: ");
        resp = getche();
    }
}

void geraNumerosPrimos(int *numeros_primos, int qtd_primos)
{
    //i ser� incrementado a cada itera��o e representa o divisor
    //j ser� incrementado a cada itera��o e representa o dividendo
    int i, j, k = 0, divisores;

    //zerando todas os valores em cada endere�o de mem�ria do ponteiro, isso ser� �til
    //masis adiante
    for(i = 0; i < qtd_primos; i++)
    {
        *(numeros_primos + i) = 0;
    }

    //essa itera��o acontecer� enquanto a ultima posi��o do ponteiro for igual a 0, pois
    //quando for diferente, � sinal que o vetor est� preenchido at� a �ltima posi��o
    //i representa o dividendo
    for(i = 2; *(numeros_primos + (qtd_primos - 1)) == 0; i++)
    {
        //todo n�mero � divis�vel por ele msm, por isso divisores j� tem 1
        divisores = 1;

        //j � o divisor
        //qualquer n�mero n�o � divis�vel por um n�mero maior que a sua metade, ent�o,
        //eu testo s� at� a metade do dividendo
        for(j = 1; j <= (i / 2); j++)
        {
            //se a dvis�o der exato, eu incremento divisores em 1, assim o limite de divisores
            //que i pode ter para ser um primo j� foi atingido
            if(i % j == 0)
            {
                divisores++;

                //se a execu��o entrar pelo menos 2 vezes na condicional acima, o numeros de
                //divisores passar� a ser 3, assim, eu n�o preciso continuar dividindo i por j
                //pois ele ser� primo
                if(divisores > 2)
                {
                    //dessa forma, eu quebro a execu��o do for interno
                    break;
                }
            }
        }

        //preciso dessa condicional, pois divisores sendo menor ou igual a 2, eu vou
        //preencher o ponteiro de forma sequencial, para isso, eu utilizei a vari�vel k
        //incrementando ap�s o vetor ser preenchido
        if(divisores <= 2)
        {
            *(numeros_primos + k) = i;
            k++;
        }
    }
}

int buscaBinaria(int key, int *numeros_primos, int qtd_primos)
{
    int inicio = 0, meio = 0, fim = qtd_primos;

    while(inicio <= fim)
    {
        meio = (inicio + fim) / 2;

        if(key > *(numeros_primos + meio))
        {
            inicio = meio + 1;
        }
        else if(key < *(numeros_primos + meio))
        {
            fim = meio - 1;
        }
        else
        {
            return *(numeros_primos + meio);
        }
    }

    return -1;
}

void exibirPrimos(int *numeros_primos, int qtd_primos)
{
    char resp;
    int k;

    printf("Vc deseja exibir os n�meros primos que est�o no intervalo que vc escolheu? [n] p/ n�o e [s] p/ sim: ");
    resp = getche();

    if(resp == 's' || resp == 'S')
    {
        for(k = 0; k < qtd_primos; k++)
        {
            printf("\n%d", *(numeros_primos + k));
        }
        printf("\n");
    }
}
