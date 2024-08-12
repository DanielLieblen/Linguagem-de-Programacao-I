#include <stdio.h>

int main()
{
    int album, figurinhasQ, cont = 0, figurinhas;

    // le a quantidade de figurinhas totais no album
    scanf("%d", &album);
    // cria e inicializa o vetor do album de figurinhas + 1 posicao
    int vetor[album + 1];

    for (int k = 1; k <= album; k++)
    {
        vetor[k] = 0; // inicializa o album com zero
    }

    scanf("%d", &figurinhasQ); // le a quantidade de figurinhas compradas
    // adiciona o numero total de espaços vazios do album ao cont pra depois decrescer conforme forem compradas figurinhas
    cont = album;
    // le as figurinhas e acha a posicao delas dentro do vetor

    for (int i = 0; i < figurinhasQ; i++)
    {
        scanf("%d", &figurinhas);
        // pega vetor na posicao de figurinhas e troca o zero pelo 1(quantidade) tendo certeza de nao colocar figurinhas repetidas
        if (vetor[figurinhas] == 0)
        {
            vetor[figurinhas] = 1;
            cont--;
        }
    }
    printf("%d", cont);
}
