#include <stdio.h>

int main()
{

    int competidor, qntvolta, vencedor, soma = 0, menor = 500;

    scanf("%d", &competidor);
    scanf("%d", &qntvolta);

    for (int i = 0; i < competidor; i++)
    {
        soma = 0;
        for (int j = 0; j < qntvolta; j++)
        {
            int tempo;
            scanf("%d", &tempo);
            soma += tempo;
        }
        if (soma < menor)
        {
            menor = soma;
            vencedor = i + 1;
        }
    }

    printf("%d\n", vencedor);
}
