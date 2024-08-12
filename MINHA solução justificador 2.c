#include <stdio.h>
#include <string.h>
#include <ctype.h>

void main()
{
    int n, p = 0;
    int tamAux = 0;

    scanf("%d", &n);
    getchar();

    // char texto[n][60];
    // char textoAux[60], resultado[60];
    // int tam[n];

    while (n != 0)
    {
        if (n == 0)
        {
            break;
        }

        char texto[n][60];
        char textoAux[60], resultado[60];
        int tam[n];
        int maiorTam = 0;

        // Lendo as linhas do texto
        for (int i = 0; i < n; i++)
        {
            fgets(texto[i], 51, stdin);
        }
        // armazena a porcaria do tamanho da
        // string dentro dessa variavel tam

        for (int i = 0; i < n; i++)
        { // percorre todas as linhas
            // remover os espa os da string
            //  e colocar no vetor auxiliar sem os espa os extras
            // isalpha   pra verificar se tem uma letra antes do espa o

            tam[i] = strlen(texto[i]);
            for (int j = 0; j < tam[i]; j++) // percorre todas as letras
            {

                if ((isspace(texto[i][j]) && isalpha(texto[i][j - 1])) || (isalpha(texto[i][j])))
                { // isalpha ja faz a comparacao pra ver se o bagulho
                    // anterior   uma letra
                    textoAux[p] = texto[i][j];

                    // nova variavel pra mudar a posicao do vetor auxiliar
                    p++;
                }
            }

            int contador = strlen(textoAux);

            while (!isalpha(textoAux[contador]))
            {
                textoAux[contador] = '\0';
                contador--;
            }

            p = 0;
            contador = 0;

            strcpy(texto[i], textoAux);
            // copia o valor de uma string pra dentro da outra
            // o primeiro recebe o valor do segundo
            // mas nesse caso a string original   reescrita
            // pra receber o valor modificado com os espa os corretos

            // zerar a string
            for (int m = 0; m < sizeof(textoAux); m++)
            {
                textoAux[m] = '\0';
            }
        }

        for (int i = 0; i < n; i++)
        {
            tam[i] = strlen(texto[i]);
        }

        // descobrir qual   a maior linha da matriz
        for (int k = 0; k < n; k++)
        {
            if (tam[k] > maiorTam)
            {
                // se o vetor de tamanho for maior do que a variavel
                // a variavel maior_tamanho recebe o valor
                // do tamanho daquela linha
                maiorTam = tam[k];
            }
        }

        for (int l = 0; l < n; l++)
        {
            for (int i = 0; i < (maiorTam - tam[l]); i++)
            {
                printf(" ");
            }
            printf("%s\n", texto[l]);
        }
    }
}
