#include <stdio.h>

int main() {
    int vetor[10];
    int tam = 0;

    printf("Insira 10 valores no vetor (sem repetições):\n");

    while (tam < 10) {
        int novoValor;
        int repetido = 0;

        printf("[%d]: ", tam + 1);
        scanf("%d", &novoValor);

        for (int i = 0; i < tam; i++) {
            if (vetor[i] == novoValor) {
                repetido = 1;
                printf("Valor repetido. Insira um novo valor.\n");
                break;
            }
        }

        if (!repetido) {
            vetor[tam] = novoValor;
            tam++;
            printf("Valor inserido com sucesso.\n");
        }
    }

    printf("Vetor preenchido com sucesso:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}
