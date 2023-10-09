#include<stdio.h>
#define tam 2

typedef struct {
    char nome[50];
    char sexo;
    int idade;
} Pessoa;

typedef struct {
    int homens;
    int maioresDe15;
} Resultados;

Resultados lerPessoas(Pessoa pessoas[]) {
    Resultados resultados = {0, 0}; // Inicializa os resultados com zero

    for(int i = 0; i < tam; i++) {
        printf("Nome: ");
        gets(pessoas[i].nome);

        printf("Sexo (M/F): ");
        scanf("%c", &pessoas[i].sexo);

        printf("Idade: ");
        scanf("%d", &pessoas[i].idade);

        if (pessoas[i].sexo == 'M') {
            resultados.homens++;
        }

        if (pessoas[i].idade > 15) {
            resultados.maioresDe15++;
        }

        printf("\n");
    }

    printf("Quantidade de homens: %d\n", resultados.homens);

    return resultados;
}

int main() {

    Pessoa pessoas[tam];
    
    printf("Digite as informacoes de ate 10 pessoas:\n");
    Resultados resultados = lerPessoas(pessoas);
    
    printf("Quantidade de pessoas com idade maior que 15: %d\n", resultados.maioresDe15);

    return 0;
}
