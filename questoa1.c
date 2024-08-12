#include <stdio.h>

int main(){

    float A, G, vant1=0.0, vant2=0.0, flag;
    int N;
    char E, M;

    //da a quantidade de estados na pesquisa
    scanf("%d", &N);

        for (int i=0; i<N; i++){
            //le o estado
            scanf(" %c", &E);
            //valor alcool
            scanf("%f", &A);
            //valor gasolina
            scanf("%f", &G);
            //flag pra saber a vantagem
            vant1=7.0*G;
            if(A/G == vant1){
                M = E;
            }else{
            }


        }

    printf(" %c", M);

}
