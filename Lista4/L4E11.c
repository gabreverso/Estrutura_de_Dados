#include<stdio.h>
#include<string.h>

int verificaVogal(char vog){
    if(vog == 'a' || vog == 'e' || vog == 'i' || vog == 'o' || vog == 'u'){
        return 1;
    }

    else{
        return 0;
    }
}

int contaVogal(char p1[]){

    int j = 0;

    for(int i=0; i<strlen(p1); i++){
        if(verificaVogal(p1[i]) == 1){
            j+=1;
        }
    }
    
    return j;

}



int main(){
    char p1[20], p2[20];

    printf("Primeira palavra: ");
    fflush(stdin);
    gets(p1);
    

    printf("Segunda palavra: ");
    fflush(stdin);
    gets(p2);
    
    printf("Quantidade de Vogais: ");
    
    printf("%d", contaVogal(p1)+contaVogal(p2));
}