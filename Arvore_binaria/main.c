#include<stdio.h>
#include<stdlib.h>

struct TipoArvore
{
    int info;
    struct TipoArvore* sae;
    struct TipoArvore* sad;
};

typedef struct TipoArvore Arvore;

Arvore* inicializa();
int estaVazia(Arvore* a);
Arvore* criaNo(int n, Arvore* sae, Arvore* sad);
Arvore* libera(Arvore* a);
int busca(Arvore* a, int n);
void imprimePre(Arvore* a);
void imprimeIn(Arvore* a);
void imprimePos(Arvore* a);
void ordemDecrescente(Arvore* a);
Arvore* inserir(Arvore* a, int c);

int main()
{
    Arvore *A = inicializa();
    A = inserir(A, 3);
    A = inserir(A, 5);
    A = inserir(A, 4);
    A = inserir(A, 6);
    A = inserir(A, 1);
    A = inserir(A, 2);
    A = inserir(A, 0);

    //imprimePre(A);
    printf("\nEm ordem crescente: ");
    imprimeIn(A);
    //printf("\n");
    //imprimePos(A);

    if (!busca(A, 4))
    {
        printf("\nInformacao INEXISTENTE!");
    }
    else
    {
        printf("\nInformacao ENCONTRADA COM SUCESSO!");
    }

    printf("\nEm ordem decrescente: ");
    ordemDecrescente(A);

    A = libera(A);
    //imprimePre(A);
    //printf("\n");
    //imprimeIn(A);
    //printf("\n");
    //imprimePos(A);

    return 0;
}

Arvore* inicializa()
{
    return NULL;
}

int estaVazia(Arvore* a)
{
    return a == NULL;
}

Arvore* inserir(Arvore* a, int c){
    if(estaVazia(a)){
        return criaNo(c, inicializa(), inicializa());
    }
    else{
        if(c < a->info){
            a->sae = inserir(a->sae, c);
        }
        if(c > a->info){
             a->sad = inserir(a->sad, c);
        }
        return a; //nó a ser inserido já existe, nada muda!
    }
}

Arvore* criaNo(int n, Arvore* sae, Arvore* sad)
{
    Arvore* p = (Arvore*) malloc(sizeof(Arvore));
    p->info = n;
    p->sae = sae;
    p->sad = sad;
    return p;
}

Arvore* libera(Arvore* a)
{
    if (!estaVazia(a))
    {
        libera(a->sae); /* libera sae */
        libera(a->sad); /* libera sad */
        free(a); /* libera raiz */
    }
    return NULL;
}

int busca(Arvore* a, int n)
{
    if (estaVazia(a))
    {
        return 0;
    }
    else
    {
        if (a->info == n)
        {
            return 1;
        }
        else
        {
            if (n < a->info)
            {
                busca(a->sae, n);
            }
            else if(n > a->info)
            {
                 busca(a->sad, n);
            }
        }
    }
}

void imprimePre(Arvore* a)
{
    if (!estaVazia(a))
    {
        printf("%d ", a->info); /* mostra raiz */
        imprimePre(a->sae); /* mostra sae */
        imprimePre(a->sad); /* mostra sad */
    }
}

void imprimeIn(Arvore* a)
{
    if (!estaVazia(a))
    {
        imprimeIn(a->sae); /* mostra sae */
        printf("%d ", a->info); /* mostra raiz */
        imprimeIn(a->sad); /* mostra sad */
    }
}

void ordemDecrescente(Arvore* a)
{
    if (!estaVazia(a))
    {
        ordemDecrescente(a->sad); /* mostra sae */
        printf("%d ", a->info); /* mostra raiz */
        ordemDecrescente(a->sae); /* mostra sad */
    }
}

void imprimePos(Arvore* a)
{
    if (!estaVazia(a))
    {
        imprimePos(a->sae); /* mostra sae */
        imprimePos(a->sad); /* mostra sad */
        printf("%d ", a->info); /* mostra raiz */
    }
}
