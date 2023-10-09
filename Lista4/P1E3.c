#include <stdio.h>
#include <string.h>

void dobraPalavras(char frase1[], char palavra[], int *cont) {
    int tamF = strlen(frase1);
    int tamP = strlen(palavra);
    int i = 0;

    while (i < tamF) {

        int j = 0;
        while (i < tamF && j < tamP && frase1[i] == palavra[j]) {
            i++;
            j++;
        }

        if (j == tamP) {
            (*cont)++;
        } else {
            i++;
        }
    }
}

int main() {
    char frase[100], palavra[20];
    int cont = 0;

    printf("frase: ");
    fflush(stdin);
    gets(frase);

    printf("\npalavra: ");
    scanf("%s", palavra);

    dobraPalavras(frase, palavra, &cont);

    printf("'%s' aparece %d vezes na frase.", palavra, cont);

    return 0;
}
