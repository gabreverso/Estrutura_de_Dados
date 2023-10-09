#include<stdio.h>

struct Hora{
    int H;
    int M;
    int S;
};

struct Data{
    int D;
    int M; 
    int A;
};

struct compromisso{
    struct Hora horario;
    struct Data dia;
    char desc[400];
};

int main(){

    struct compromisso comp[3];

    for(int i=0; i<3; i++){
        printf("\nDia do compromisso: ");
        scanf("%d", &comp[i].dia.D);
        scanf("%d", &comp[i].dia.M);
        scanf("%d", &comp[i].dia.A);

        printf("\nHorario do compromisso: ");
        scanf("%d %d %d", &comp[i].horario.H, &comp[i].horario.M, &comp[i].horario.S);

        // Limpa o buffer do teclado após ler o horário para evitar problemas com o gets
        while (getchar() != '\n');

        printf("\nDescricao do compromisso: ");
        gets(comp[i].desc);

        printf("\nCompromisso Agendado!\n");
    }

    for(int i=0; i<3; i++){
        printf("\nData: %d/%d/%d", comp[i].dia.D, comp[i].dia.M, comp[i].dia.A);
        printf("\nHorario: %d:%d:%d", comp[i].horario.H, comp[i].horario.M, comp[i].horario.S);
        printf("\nDescricao: %s\n", comp[i].desc);
    }

    return 0;
}
