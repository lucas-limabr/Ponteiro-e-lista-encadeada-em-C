#include <stdio.h>
#include <stdlib.h>

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
//cria um nó, dado a informação e as duas subárvores
Arvore* criaNo(int n, Arvore* sae, Arvore* sad);
//libera a estrutura da árvore
Arvore* libera(Arvore* a);
//Determinar se uma informação se encontra ou não na árvore
int busca(Arvore* a, int n);
//imprime a informação de todos os nós da árvore
void imprime(Arvore* a);

int main()
{
    Arvore *D = criaNo(4, inicializa(), inicializa());
    Arvore *E = criaNo(5, inicializa(), inicializa());
    Arvore *F = criaNo(6, inicializa(), inicializa());
    Arvore *G = criaNo(7, inicializa(), inicializa());
    Arvore *B = criaNo(2, D, E);
    Arvore *C = criaNo(3, F, G);
    Arvore *A = criaNo(1, B, C);

    imprime(A);

    if (!busca(A, 6))
    {
        printf("\nInformacao INEXISTENTE!");
    }
    else
    {
        printf("\nInformacao ENCONTRADA COM SUCESSO!");
    }

    A = libera(A);

    imprime(A);

    return 0;
}

/* cria uma árvore vazia. */
Arvore* inicializa()
{
    return NULL;
}

/* cria um nó com a informação, a sae e a sad. */
Arvore* criaNo(int n, Arvore* sae, Arvore* sad)
{
    Arvore* p = (Arvore*) malloc(sizeof(Arvore));
    p->info = n;
    p->sae = sae;
    p->sad = sad;
    return p;
}

/* imprime a informação corresponde a cada nó da árvore. */
void imprime(Arvore* a)
{
    if(!estaVazia(a))
    {
        //PRÉ-ORDEM, ou seja, a visita ao nó, neste caso para printar na teça, é PRÉ chamadas recursivas
        printf("%d ", a->info); /* mostra raiz */
        imprime(a->sae); /* mostra sae */
        imprime(a->sad); /* mostra sad */
    }
}

/* verifica se a arvore está vazia. */
int estaVazia(Arvore* a)
{
    return a == NULL;
}

/* busca pela chave */
int busca(Arvore* a, int n)
{
    if(estaVazia(a))
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
            if (busca(a->sae, n))
            {
                return 1;
            }
            else
            {
                return busca(a->sad, n);
            }
        }
    }
}

/* Libera a árvore da memória */
Arvore* libera(Arvore* a)
{
    if(!estaVazia(a))
    {
        libera(a->sae); /* libera sae */
        libera(a->sad); /* libera sad */
        free(a); /* libera raiz */
    }
    return NULL;
}
