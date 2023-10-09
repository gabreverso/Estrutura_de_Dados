#include<stdio.h>
#include<string.h>

int dobra(char str1[], char str2[]){
    int j;
    char aux[100];
    for(int i=0; i < str1['\0']; i++){
        while(str1[i] != '\0'){
            if(str1[i] != ' '){
                aux[i] = str1[i];
                str2[j] = aux[i];
                j++;
            }
            if(str1[i] == ' '){
                aux[i] = str1[i];
                str2[j] = aux[i];
                j++;
                str2[j] = aux[i];
                j++;    
            }

            
        }
    }   
    printf("%s", str2);
}

int main(){

    char str1[100], str2[200];

    printf("Frase: \n");
    setbuf(stdin, NULL);
    gets(str1);

    dobra(str1, str2);

    puts(str2);

}