#include <stdio.h>

int main()
{

    int valor, quantidade, nota;
    int notas[7] = {100, 50, 20, 10, 5, 2, 1};

    scanf("%d", &valor);
    printf("%d\n", valor); // imprime o valor dado

    for (int i = 0; i < 7; i++)
    {
        // entra no loop pra poder começar
        nota = notas[i];           // stoca o valor do vetor no nota
        quantidade = valor / nota; // faz o calculo da valor (dado) pelo valor guardado no vetor
        valor = valor % nota;      // atualiza o valor para o resto da divisao garantindo q o proximo loop vai ser do resto da divisao incial, ou seja, 576%100 = 76

        printf("%d nota(s) de R$ %d,00\n", quantidade, nota); // imprime a quantidade de notas seguida da nota
    }

    return 0;
}