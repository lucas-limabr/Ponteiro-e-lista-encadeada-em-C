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

    printf("Digite a quantidade de números primos que o vetor irá armazenar sequencialmente: ");
    scanf("%d", &qtd_primos);

    int *numeros_primos = (int*)malloc(sizeof(int) * qtd_primos);
    geraNumerosPrimos(numeros_primos, qtd_primos);

    printf("\nAgora, escolha um número para pesquisar se ele existe dentro deste vetor, ");
    printf("o que significa que se tiver, vc descobriu que este é um número primo E está dentro");
    printf(" da quantidade de valores que vc escolheu para este vetor");

    while(resp =='s' || resp == 'S')
    {
        printf("\nDigite: ");
        scanf("%d", &key);

        int key_procurada = buscaBinaria(key, numeros_primos, qtd_primos);
        if (key_procurada == -1)
        {
            printf("Key não encontrada\n");
        }
        else
        {
            printf("Key encontrada: %d\n", key_procurada);
        }

        exibirPrimos(numeros_primos, qtd_primos);
        printf("\nVc deseja procurar uma outra chave neste intervalo que vc escolheu? [n] p/ não e [s] p/ sim: ");
        resp = getche();
    }
}

void geraNumerosPrimos(int *numeros_primos, int qtd_primos)
{
    //i será incrementado a cada iteração e representa o divisor
    //j será incrementado a cada iteração e representa o dividendo
    int i, j, k = 0, divisores;

    //zerando todas os valores em cada endereço de memória do ponteiro, isso será útil
    //masis adiante
    for(i = 0; i < qtd_primos; i++)
    {
        *(numeros_primos + i) = 0;
    }

    //essa iteração acontecerá enquanto a ultima posição do ponteiro for igual a 0, pois
    //quando for diferente, é sinal que o vetor está preenchido até a última posição
    //i representa o dividendo
    for(i = 2; *(numeros_primos + (qtd_primos - 1)) == 0; i++)
    {
        //todo número é divisível por ele msm, por isso divisores já tem 1
        divisores = 1;

        //j é o divisor
        //qualquer número não é divisível por um número maior que a sua metade, então,
        //eu testo só até a metade do dividendo
        for(j = 1; j <= (i / 2); j++)
        {
            //se a dvisão der exato, eu incremento divisores em 1, assim o limite de divisores
            //que i pode ter para ser um primo já foi atingido
            if(i % j == 0)
            {
                divisores++;

                //se a execução entrar pelo menos 2 vezes na condicional acima, o numeros de
                //divisores passará a ser 3, assim, eu não preciso continuar dividindo i por j
                //pois ele será primo
                if(divisores > 2)
                {
                    //dessa forma, eu quebro a execução do for interno
                    break;
                }
            }
        }

        //preciso dessa condicional, pois divisores sendo menor ou igual a 2, eu vou
        //preencher o ponteiro de forma sequencial, para isso, eu utilizei a variável k
        //incrementando após o vetor ser preenchido
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

    printf("Vc deseja exibir os números primos que estão no intervalo que vc escolheu? [n] p/ não e [s] p/ sim: ");
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
