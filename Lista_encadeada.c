#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include <windows.h>

struct estrutura
{
    int matricula;
    float nota;
    char *nome;

    /*ponteiro que apontará para o próximo nó da lista, que é do tipo de mesma estrutura*/
    struct estrutura *next;
};

typedef struct estrutura Aluno;

/*função que retorna um ponteiro do tipo Aluno para atualizar na função main, o primeiro nó da lista, já que eu estou
inserindo um nó no início
Passo como parâmetro o ponteiro que aponta para a cabeça(1° item) da lista e também os dados que serão inseridos neste novo nó que é do tipo struct
*/
Aluno *insereInicio(Aluno *atual, Aluno no);

//para apenas imprimir, como eu não estou adicionando nenhum novo nó, essa função não tem retorno nenhum
void imprime(Aluno *atual);
Aluno *insereFinal(Aluno *atual, Aluno no);
Aluno *libera(Aluno *atual);
Aluno *busca(Aluno *atual, int matricula);
Aluno *remover(Aluno *atual, int matricula);

int main()
{

    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    // Define codificação como sendo UTF-8
    SetConsoleOutputCP(CPAGE_UTF8);

    /*este é o ponteiro, declarado na main que a sua funçaõ é smp apontar para a cabeça da lista, ele começa como NULL, ou seja, lista vazia*/
    Aluno *listaAlunos = NULL;
    //nó buscado para ser alterado
    Aluno *alteraNota = NULL;

    Aluno no;
    no.matricula = 2022;
    no.nome = "João";
    no.nota = 8;

    /*o ponteiro listaAlunos precisa atualizar e receber o novo primeiro nó da lista, quando a inserção é feita no início e para a função
    é fundamental que ela saiba onde começa a lista, por isso, que ela recebe como parâmetro o ponteiro que aponta para o início da lista atualmente, além do nó que é o dado a ser preechido*/
    listaAlunos = insereInicio(listaAlunos, no);

    no.matricula = 2023;
    no.nome = "Lucas";
    no.nota = 5;

    listaAlunos = insereInicio(listaAlunos, no);

    no.matricula = 2024;
    no.nome = "Rodrick";
    no.nota = 9;

    listaAlunos = insereInicio(listaAlunos, no);

    //key a ser procurada para ser removida
    int matricula = 2022;
    listaAlunos = remover(listaAlunos, matricula);

    //matrícula a ser buscada para ter a nota alterada
    matricula = 2023;
    alteraNota = busca(listaAlunos, matricula);

    if(alteraNota == NULL){
        printf("Número de matrícula não encontrado!");
    }
    else{
       alteraNota->nota = 10;
    }

    no.matricula = 2025;
    no.nome = "André";
    no.nota = 6;

    listaAlunos = insereFinal(listaAlunos, no);

    //passo o primeiro nó para a função, ou seja, a cabeça da lista
    imprime(listaAlunos);

    SetConsoleOutputCP(CPAGE_DEFAULT);
}

Aluno *insereInicio(Aluno *atual, Aluno no)
{

    /*a função retorna o novo ponteiro e nó que será agora a cabeça da lista e apontará para o próximo nó da lista*/
    Aluno *novo = (Aluno*)malloc(sizeof(Aluno));

    /*o ponteiro novo aponta para cada campo da struct e a partir daí o parâmetro recebido nesta função é passado para cada campo da struct*/
    novo->matricula = no.matricula;
    novo->nome = no.nome;
    novo->nota = no.nota;

    if (atual == NULL) //lista vazia
    {
        //se a lista estava vazia, o ponteiro que aponta para o próximo nó depois deste novo é vazio
        novo->next = NULL;
    }
    else
    {
        //senão, o ponteiro que aponta para o próximo nó, apontará para o nó que até aqui era o primeiro da lista, e a partir desta linha será o segundo
        novo->next = atual;
    }

    //aqui é o retorno deste nó que eu acabei de inserir na lista, que agr é a cabeça e terá lá na main o ponteiro listaAlunos apontando para ele
    return novo;
}

void imprime(Aluno *atual)
{
    if (atual == NULL)
    {
        printf("A lista está vazia!");
    }
    printf("\n");
    //enquanto tiver nó na lista
    while(atual != NULL)
    {
        printf("\nMatrícula: %d", atual->matricula);
        printf("\nNome: %s", atual->nome);
        printf("\nNota: %.2f", atual->nota);
        printf("\n");

        //o ponteiro atual precisa receber o endereço que o next aponta, que é para o próximo nó da lista, agora, atual irá referenciar o próximo nó
        atual = atual->next;
    }
}

Aluno *remover(Aluno *atual, int matricula)
{
    //preciso do nó anterior
    Aluno *ant = NULL;
    //backup do início da Lista
    Aluno *inicio = atual;

    //percurso de lista para enquanto não chegar no final da lista e eu não tiver achado a matrícula
    //a ser removida, eu avanço um nó
    while((atual != NULL) && (atual->matricula != matricula))
    {
        ant = atual;
        atual = atual->next;
    }
    //se não tiver achado a matrícula a ser removida
    if(atual == NULL)
    {
        return inicio;
    }

    //nó atual será excluído posteriormente
    Aluno *exclui = atual;
    //quero descobrir agr se este nó é o início ou não da lista
    if(ant == NULL)
    {
        atual = atual->next;
        inicio = atual;
    }
    //se não for, o pr´ximo nó do anterior apontará para o próximo do atual
    else
    {
        ant->next = atual->next;
    }
    //agr sim eu posso remover
    free(exclui);
    return inicio;

}

Aluno *insereFinal(Aluno *atual, Aluno no)
{
    Aluno *novo = (Aluno*)malloc(sizeof(Aluno));
    //importantíssimo o backup da cabeça da lista, pois smp é ele que eu vou retornar
    Aluno *backup_head = atual;

    novo->matricula = no.matricula;
    novo->nome = no.nome;
    novo->nota = no.nota;

    if(atual == NULL){
        backup_head = novo;
    }

    else{
        //não posso chegar no NULL, e sim no último nó da lista, por isso, utilizo o próximo
        //do atual e não o atual em si
        while(atual->next != NULL){

            atual = atual->next;
        }
        atual->next = novo;
    }

    novo->next = NULL;
    return backup_head;
}

Aluno *busca(Aluno *atual, int matricula)
{
    if(atual == NULL)
    {
        printf("Lista vazia");
    }
    else
    {
       while(atual != NULL){
        if(atual->matricula == matricula){
            break;
        }

        atual = atual->next;
       }
       return atual;
    }
}
