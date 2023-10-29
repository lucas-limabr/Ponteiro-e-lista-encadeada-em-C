#include <stdio.h>
#include <stdlib.h>
#include<locale.h>

struct estrutura
{
    int matricula;
    float nota;
    /*declarei mas ainda n�o aloquei espa�o para o ponteiro*/
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
        printf("\nInforme a matr�cula do aluno: ");
        scanf("%d", &(lista_alunos + i)->matricula);

        /*muito importante: preciso alocar um espa�o de mem�ria para cada ponteiro nome, aqui,
        o ponteiro nome ter� 4 locais de mem�ria diferentes, podendo armazenar 4 valores diferentes*/
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

    printf("\nAlunos acima ou igual a m�dia\n");
    for(i = 0; i < 4; i++){
       if((lista_alunos + i)->nota >= media){
            printf("\nMatr�cula %d: %s", (lista_alunos+i)->matricula, (lista_alunos + i)->nome);
       }
    }
    printf("\n");
}
