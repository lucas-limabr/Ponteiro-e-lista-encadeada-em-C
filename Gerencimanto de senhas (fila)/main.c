#include <stdio.h>
#include<locale.h>
#include<stdlib.h>
#include <windows.h>

struct estrutura
{
    char senha[20];

    struct estrutura *prox;
};

typedef struct estrutura Senhas;

int *geraSenhas(Senhas *inicioFila, int num);
int *recuperaSenha(Senhas *inicioFila, int usuario);

int main()
{
    setlocale(NULL, "");

    int opcao, num = 1, usuario = 1;
    Senhas *inicioFila = NULL;


    printf("\n***********************************");
    printf("\nSISTEMA DE GERENCIAMENTO DE SENHAS");
    printf("\n***********************************\n");

    do
    {
        printf("\n[1] - Gerar senha");
        printf("\n[2] - Atender ao usuário");
        printf("\n[3] - Sair do sistema\n");
        scanf("%d", &opcao);

        if(opcao == 1)
        {
            inicioFila = geraSenhas(inicioFila, num);
            num++;
        }

        else if(opcao == 2)
        {
            inicioFila = recuperaSenha(inicioFila, usuario);
            usuario++;
        }
    }
    while(opcao != 3);
}

int *geraSenhas(Senhas *inicioFila, int num)
{
    Senhas *novaSenha = (Senhas*)malloc(sizeof(Senhas));
    Senhas *backupInicio = inicioFila;

    char string[20] = "IFET ";
    char conversao_int[2];

    //convertendo número para string
    sprintf(conversao_int, "%d", num);

    //para poder concatenar a string com o número convertido
    strcat(string, conversao_int);

    //copiando a string para o campo do struct
    strcpy(novaSenha->senha, string);

    if(inicioFila == NULL)
    {
        backupInicio = novaSenha;
    }

    else if(inicioFila != NULL)
    {
        while(inicioFila->prox != NULL)
        {
            inicioFila = inicioFila->prox;
        }
        inicioFila->prox = novaSenha;
    }

    printf("\n%s", novaSenha->senha);

    return backupInicio;
}

int *recuperaSenha(Senhas *inicioFila, int usuario)
{
    if(inicioFila == NULL)
    {
        printf("A fila está vazia");
    }
    else
    {

        printf("\nAtendimento do %d%c  usuário -> Senha: %s", usuario, 176, inicioFila->senha);

        Senhas *libera = inicioFila;
        inicioFila = inicioFila->prox;
        free(libera);
    }

    return inicioFila;
}
