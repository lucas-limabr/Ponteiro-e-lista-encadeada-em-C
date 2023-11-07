#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

struct estrutura
{
    int matricula;
    float nota;
    char *nome;

    struct estrutura *next;
};

typedef struct estrutura Alunos;

Alunos *insereInicio(Alunos *atual, Alunos no);
void imprime(Alunos *atual);
Alunos *insereFinal(Alunos *atual, Alunos no);
Alunos *busca(Alunos *atual, int matricula);
float Media(Alunos *atual);

int main()
{
    //para rodar português na IDE Visual Studio Code
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    // Define codificação como sendo UTF-8
    SetConsoleOutputCP(CPAGE_UTF8);

    Alunos *listaAlunos = NULL;

    Alunos no;

    no.matricula = 2020;
    no.nome = "Lucas";
    no.nota = 10;

    listaAlunos = insereInicio(listaAlunos, no);

    no.matricula = 2022;
    no.nome = "André";
    no.nota = 8;

    listaAlunos = insereFinal(listaAlunos, no);

    no.matricula = 2021;
    no.nome = "João";
    no.nota = 6;

    listaAlunos = insereInicio(listaAlunos, no);

    imprime(listaAlunos);

    int matricula = 2020;
    Alunos *matriculaBuscada = NULL;
    matriculaBuscada = busca(listaAlunos, matricula);

    if(matriculaBuscada == NULL){
        printf("Matrícula não encontrada");
    }
    else{
        printf("\nDados da busca realizada");
        printf("\nMatrícula: %d", matriculaBuscada->matricula);
        printf("\nNome: %s", matriculaBuscada->nome);
        printf("\nNota: %.2f\n", matriculaBuscada->nota);
    }

    printf("\nA média aritmética das notas dos alunos é de %.2f\n", Media(listaAlunos));

    SetConsoleOutputCP(CPAGE_DEFAULT);
}

Alunos *insereInicio(Alunos *atual, Alunos no)
{
    Alunos *novo = (Alunos *)malloc(sizeof(Alunos));

    novo->matricula = no.matricula;
    novo->nome = no.nome;
    novo->nota = no.nota;

    if (atual == NULL)
    {
        novo->next = NULL;
    }
    else
    {
        novo->next = atual;
    }

    return novo;
}

Alunos *insereFinal(Alunos *atual, Alunos no){
    Alunos *novo = (Alunos*)malloc(sizeof(Alunos));
    //backup da cabeça da lista
    Alunos *inicio = atual;

    novo->matricula = no.matricula;
    novo->nome = no.nome;
    novo->nota = no.nota;

    if(atual == NULL){
        inicio = novo;
    }
    else{
        while (atual->next != NULL)
        {
             atual = atual->next;
        }
        atual->next = novo;
    }
    novo->next = NULL;

    return inicio;
}

Alunos *busca(Alunos *atual, int matricula){
    if(atual == NULL){
        printf("A lista está vazia");
    }
    else{
        while (atual != NULL)
        {
            if (atual->matricula == matricula)
            {
                break;
            }

            atual = atual->next;
        }

        return atual;
    }
}

float Media(Alunos *atual)
{
    float media = 0;
    int qtdAlunos = 0;

    if(atual == NULL){
        printf("A lista está vazia, nenhum dado de nota encontrado");
    }
    else{
        while (atual != NULL)
        {
            media += atual->nota;

            atual = atual->next;
            qtdAlunos++;
        }

        media /= qtdAlunos;
    }

    return media;
}

void imprime(Alunos *atual)
{
    if (atual == NULL)
    {
        printf("A lista esta vazia");
    }
    else
    {
        while (atual != NULL)
        {
            printf("\nMatricula: %d\n", atual->matricula);
            printf("Nome: %s\n", atual->nome);
            printf("Nota: %.2f\n", atual->nota);

            atual = atual->next;
        }
    }
}
