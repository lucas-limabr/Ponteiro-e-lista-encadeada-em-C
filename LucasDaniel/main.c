#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

struct TipoArvore
{
    int info;
    struct TipoArvore* sae;
    struct TipoArvore* sad;
};

typedef struct TipoArvore Arvore;

//cria uma árvore vazia
Arvore* inicializa();

//verifica se a arvore está vazia
int estaVazia(Arvore* a);

//cria um nó dadas a informação e as duas subárvores
Arvore* insereNo(Arvore* a, int n);

//libera a estrutura da árvore
void libera(Arvore* a);

//Determinar se uma informação se encontra ou não na árvore
int busca(Arvore* a, int n);

//imprime a informação de todos os nós da árvore em Pre-Ordem
void imprimePre(Arvore* a);

//imprime a informação de todos os nós da árvore em In-Ordem
void imprimeIn(Arvore* a);

//imprime a informação de todos os nós da árvore em Pos-Ordem
void imprimePos(Arvore* a);

int buscaMaior(Arvore* a);

//Determinar o menor elemento armazenado na árvore
int buscaMenor(Arvore* a);

int getNosFolhas(Arvore* a);

Arvore *criano(int n);

// ImprimeDescendenteOrdem(Arvore *a);
//void ImprimeAscendenteOrdem(Arvore *a);

int main()
{
    setlocale(LC_ALL, "");

    Arvore *A = inicializa();

    A = insereNo(A, 3);
    A = insereNo(A, 5);
    A = insereNo(A, 4);
    A = insereNo(A, 6);
    A = insereNo(A, 1);
    A = insereNo(A, 2);
    A = insereNo(A, 0);

    //imprimePre(A);
    printf("\n");
    //imprimeIn(A);
    //imprimePos(A);
    ImprimeAscendenteOrdem(A);
    printf("\n");
    ImprimeDescendenteOrdem(A);

    //busca maior
    if(!buscaMaior(A))
    {
        printf("Árvore vazia");
    }
    else
    {
        printf("\n\nMaior valor: %d", buscaMaior(A));
    }

    //busca menor
    if(!buscaMenor(A))
    {
        printf("Árvore vazia");
    }
    else
    {
        printf("\nMenor valor: %d", buscaMenor(A));
    }


    printf("\nNós folhas: %d", getNosFolhas(A));

    if (!busca(A, 4))
    {
        printf("\n\nInformacao INEXISTENTE!\n");
    }
    else
    {
        printf("\n\nInformacao ENCONTRADA COM SUCESSO!\n");
    }

    libera(A);

    return 0;
}

//cria uma árvore vazia
Arvore* inicializa()
{
    return NULL;
}

//verifica se a arvore está vazia
int estaVazia(Arvore* a)
{
    return a == NULL;
}

Arvore *criano(int n)
{

    Arvore *a = (Arvore*)malloc(sizeof(Arvore));
    a->info = n;
    a->sae = NULL;
    a->sad = NULL;

    return a;
}

//Determinar o maior elemento armazenado na árvore
int buscaMaior(Arvore* a)
{
    if (estaVazia(a))
    {
        return 0;
    }

    if(a->sad != NULL)
    {
        return buscaMaior(a->sad);
    }
    if(a->sad == NULL)
    {
        return a->info;
    }
}

int buscaMenor(Arvore* a)
{
    if (estaVazia(a))
    {
        return 0;
    }

    if(a->sae != NULL)
    {
        return buscaMenor(a->sae);
    }
    if(a->sae == NULL)
    {
        return a->info;
    }
}

int getNosFolhas(Arvore* a)
{
    if(estaVazia(a))
    {
        return 0;
    }
    if(a->sae == NULL && a->sad == NULL)
    {
        return 1;
    }
    else
    {
        return getNosFolhas(a->sae) + getNosFolhas(a->sad);
    }
}

//cria um nó dada a informação e as duas subárvores
Arvore* insereNo(Arvore* a, int n)
{
    if (estaVazia(a))
    {
        a = criano(n);
    }
    else if (n < a->info)
    {
        a->sae = insereNo(a->sae, n);
    }
    else if (n > a->info)
    {
        a->sad = insereNo(a->sad, n);
    }
    return a;
}

//libera a estrutura da árvore
void libera(Arvore* a)
{
    if (a != NULL)
    {
        libera(a->sae);
        libera(a->sad);
        free(a);
    }
}

//Determinar se uma informação se encontra ou não na árvore
int busca(Arvore* a, int n)
{
    if (a == NULL)
    {
        return 0;
    }
    else if (a->info == n)
    {
        return 1;
    }
    else if (n < a->info)
    {
        return busca(a->sae, n);
    }
    else
    {
        return busca(a->sad, n);
    }
}

//imprime a informação de todos os nós da árvore em Pre-Ordem
void imprimePre(Arvore* a)
{
    if (!estaVazia(a))
    {
        printf("%d ", a->info);
        imprimePre(a->sae);
        imprimePre(a->sad);
    }
}

//imprime a informação de todos os nós da árvore em In-Ordem
void imprimeIn(Arvore* a)
{
    if (!estaVazia(a))
    {
        imprimeIn(a->sae);
        printf("%d ", a->info);
        imprimeIn(a->sad);
    }
}

//imprime a informação de todos os nós da árvore em Pos-Ordem
void imprimePos(Arvore* a)
{
    if (!estaVazia(a))
    {
        imprimePos(a->sae);
        imprimePos(a->sad);
        printf("%d ", a->info);
    }
}

void ImprimeDescendenteOrdem(Arvore *a)
{
    if (!estaVazia(a))
    {
        ImprimeDescendenteOrdem(a->sad);
        printf("%d ", a->info);
        ImprimeDescendenteOrdem(a->sae);
    }
}

void ImprimeAscendenteOrdem(Arvore *a)
{
    if (!estaVazia(a))
    {
        ImprimeAscendenteOrdem(a->sae);
        printf("%d ", a->info);
        ImprimeAscendenteOrdem(a->sad);
    }
}
