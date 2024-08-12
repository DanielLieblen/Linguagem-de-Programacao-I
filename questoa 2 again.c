#include <stdio.h>
#include <string.h>


int checagemS(char *string){
    int j=0, quant=0;
    int flag=0;
    int flag2=0;

    for(int i=0; i<strlen(string)-1; i++){
        if(string[i]=='L'){
                flag=1;
                j=i+1;
            }
        if(flag ==1 && string[j]=='P'){
            j++;
            if(string[j]=='1'){
            quant++;
            j++;
            }
        }


        }
    return quant;

}

int main(){
    char string[10];
    int quant=0;

    //le a string
    fgets(string, 10, stdin);
    //limpa o buffer da memoria
    getchar();

    int aqui = checagemS(string);


    printf("%d", quant);


}
