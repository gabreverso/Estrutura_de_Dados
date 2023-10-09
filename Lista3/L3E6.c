#include<stdio.h>
#include<string.h>

int contaPalavra(char frase[]){
    int count = 1;
    for(int i = 0; i<=strlen(frase); i++){
        if(frase[i] == ' '){
            count++;
        }
    }
    return count;
}

int main(){
    char frase[100];

    printf("Digite uma frase: ");
    gets(frase);

    int count = contaPalavra(frase);

    printf("A frase tem %d palavras. \n", count);

    
}