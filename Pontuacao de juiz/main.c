#include <stdio.h>
#include <stdlib.h>
#include<locale.h>

struct estrutura{
    float media, maior_nota, pior_nota, porcentagem_acima_media, porcentagem_abaixo_media,
    juizes_maior_nota, juizes_menor_nota;
};

typedef struct estrutura indicesAtleta;

indicesAtleta calculaPontuacao(float *nota, int qtd_juiz);

int main()
{
    setlocale(LC_ALL, "");
    indicesAtleta indices_atleta;

    int qtd_juiz, i;

    printf("São quantos juízes? ");
    scanf("%d", &qtd_juiz);

    float *nota = (float*)malloc(sizeof(float)*qtd_juiz);

    for(i = 0; i < qtd_juiz; i++){
        printf("Juíz %d: Digite a sua nota [0-10] para o atleta: ", i + 1);
        scanf("%f", nota + i);
    }

    indices_atleta = calculaPontuacao(nota, qtd_juiz);
    printf("\n");
    printf("Média; %f \n", indices_atleta.media);
    printf("Maior nota: %.2f \n", indices_atleta.maior_nota);
    printf("Pior nota: %.2f \n", indices_atleta.pior_nota);
    printf("Porcentagem acima da média: %.2f \n", indices_atleta.porcentagem_acima_media);
    printf("Porcentagem abaixo da média: %.2f \n", indices_atleta.porcentagem_abaixo_media);
    printf("Qtd de juízes que derão a maior nota: %.2f \n", indices_atleta.juizes_maior_nota);
    printf("Qtd de juízes que derão a pior nota: %.2f \n", indices_atleta.juizes_menor_nota);
}

indicesAtleta calculaPontuacao(float *nota, int qtd_juiz){

    int i;
    indicesAtleta indices_atleta;
    indices_atleta.media = 0, indices_atleta.maior_nota = *(nota), indices_atleta.pior_nota = *(nota);


    for(i = 0; i < qtd_juiz; i++){
        indices_atleta.media += *(nota + i);

        if(*(nota + i) > indices_atleta.maior_nota){
            indices_atleta.maior_nota = *(nota + i);
        }

        if(*(nota + i) < indices_atleta.pior_nota){
            indices_atleta.pior_nota = *(nota + i);
        }
    }

    indices_atleta.media /= qtd_juiz;

    for(i = 0; i < qtd_juiz; i++){
        if(*(nota + i) > indices_atleta.media){
            indices_atleta.porcentagem_acima_media++;
        }
        else if (*(nota + i) < indices_atleta.media){
            indices_atleta.porcentagem_abaixo_media++;
        }

        if(indices_atleta.maior_nota == *(nota + i)){
            indices_atleta.juizes_maior_nota++;
        }
        if(indices_atleta.pior_nota == *(nota + i)){
            indices_atleta.juizes_menor_nota++;
        }
    }

    indices_atleta.porcentagem_acima_media *= 100 / qtd_juiz;
    indices_atleta.porcentagem_abaixo_media = 100 - indices_atleta.porcentagem_acima_media;

    return indices_atleta;
}
