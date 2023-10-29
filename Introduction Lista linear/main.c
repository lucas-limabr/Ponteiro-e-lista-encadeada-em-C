#include <stdio.h>
#include <stdlib.h>
#include<locale.h>

struct estrutura
{
    int matricula;
    float nota;
    /*declarei mas ainda não aloquei espaço para o ponteiro*/
    char *nome;
};

typedef struct estrutura Aluno;


int main()
{
    setlocale(LC_ALL, "");

    Aluno *lista_alunos = (Aluno*)malloc(sizeof(Aluno) * 4);
    int i;
    float media = 0;

    for(i = 0; i < 4; i++)
    {
        printf("\nInforme a matrícula do aluno: ");
        scanf("%d", &(lista_alunos + i)->matricula);

        /*muito importante: preciso alocar um espaço de memória para cada ponteiro nome, aqui,
        o ponteiro nome terá 4 locais de memória diferentes, podendo armazenar 4 valores diferentes*/
        (lista_alunos+i)->nome = (char*)malloc(sizeof(char) * 20);
        printf("Digite o nome do aluno: ");
        /*preciso limpar o buffer do teclado*/
        setbuf(stdin, NULL);
        gets((lista_alunos + i)->nome);

        printf("Informe a nota: ");
        scanf("%f", &(lista_alunos + i)->nota);

        media += (lista_alunos + i)->nota;
    }

     media /= 4;

    printf("\nAlunos acima ou igual a média\n");
    for(i = 0; i < 4; i++){
       if((lista_alunos + i)->nota >= media){
            printf("\nMatrícula %d: %s", (lista_alunos+i)->matricula, (lista_alunos + i)->nome);
       }
    }
    printf("\n");
}
