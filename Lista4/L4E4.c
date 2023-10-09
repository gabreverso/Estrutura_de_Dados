#include <stdio.h>
#include <string.h>

void contaPalavras(char palavras[][30], int *vet, int *tamanhoVetor, int n) {
    int i;

    for (i = 0; i < n; i++) {
        if (palavras[i][0] == palavras[i][strlen(palavras[i]) - 1]) {
            vet[*tamanhoVetor] = i;
            (*tamanhoVetor)++;
        }
    }
}

int main() {
    int n;
    char palavras[20][30];
    int vet[20], tamanhoVetor = 0;

    printf("Quantidade de Palavras: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        gets(palavras[i]);
        while(getchar() != '\n');
    }

    contaPalavras(palavras, vet, &tamanhoVetor, n);

    printf("Linhas:\n");
    for (int i = 0; i < tamanhoVetor; i++) {
        printf("%d\n", vet[i]);
    }

    return 0;
}
