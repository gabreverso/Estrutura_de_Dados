#include <stdio.h>

int main() {
    int N, fat;

    printf("\nQuantos fatoriais deseja calcular? ");
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        printf("Digite um numero: ");
        scanf("%d", &fat);

        if (fat < 0) {
            printf("Erro...\n");
            continue;
        }

        unsigned long long int resultado = 1;
        for (int j = 2; j <= fat; j++) {
            resultado *= j;
        }

        printf("%d! = %llu\n", fat, resultado);
    }

    return 0;
}
