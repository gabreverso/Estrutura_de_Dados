#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char rua[60], bairro[60], cidade[60], estado[60];
    int numero;
}endereco;

typedef struct{
    int dia, mes, ano;
}data;

typedef struct cadastroAluno{
    char nome[60];
    char matricula[15];
    char curso[50];
    endereco end;
    data nascimento;
    struct cadastroAluno *prox, *ant;
} cadastroAluno;

typedef struct cadastroAluno student;

typedef struct cadastroLivro{
    long int isbn;
    char titulo[60];
    char autor[50];
    char editora[50];
    data ano;
    int quant;
    struct cadastroLivro *prox, *ant;
} cadastroLivro;

typedef struct cadastroLivro book;

typedef struct cadastroEmprestimo{
    char matriculaE[15];
    long int isbnE;
    struct cadastroEmprestimo *prox, *ant;
} cadastroEmprestimo;

typedef struct cadastroEmprestimo loan;

void menuPrincipal();
void menuSecundario();
int valiDate(int dia, int mes, int ano);
void insertStudent(student **inicio, student s);
void insertBook(book **inicio, book b);
void insertLoan(loan **inicioE, book **inicioL, student *inicioA, loan l);
void changeStudent(student **inicio);
void changeBook(book **inicio);
void changeLoan(loan **inicio);
void removeStudent(student **inicio);
void removeBook(book **inicio);
void removeLoan(loan **inicio, book **inicioL); 
void findStudent(student *inicio);
void findBook(book *inicio);
void findLoan(loan *inicio);
void listStudent(student *inicio);
void listBook(book *inicio);
void listLoan(loan *inicio);
void amountLoan(loan *inicio);
void quantityBooks(book *inicio);
void loadFile(student **inicioAluno, book **inicioLivro);
void saveFile(student *inicioAluno, book *inicioLivro, loan *inicioEmprestimo);

int main() {
    int dia, mes, ano;

    int opMP, opMS;
    student *inicioAluno = NULL;
    book *inicioLivro = NULL;   
    loan *inicioEmprestimo = NULL;
    student s;
    book b;
    loan l; 

    do {
        menuPrincipal();
        scanf("%d", &opMP);

        switch (opMP) {
            case 1: {
                do {
                    menuSecundario();
                    scanf("%d", &opMS);

                    switch (opMS) {
                        case 1: {
                            //cadastrar aluno
                            printf("Digite a matricula do aluno: ");
                            fflush(stdin);
                            gets(s.matricula);
                            printf("Digite o nome do aluno: ");
                            fflush(stdin);
                            gets(s.nome);
                            printf("Curso: ");
                            fflush(stdin);
                            gets(s.curso);

                            printf("Endereco do discente:\n");
                            printf("Rua: ");
                            fflush(stdin);
                            gets(s.end.rua);
                            printf("Numero: ");
                            scanf("%d", &s.end.numero);
                            printf("Bairro: ");
                            fflush(stdin);
                            gets(s.end.bairro);
                            printf("Cidade: ");
                            fflush(stdin);
                            gets(s.end.cidade);
                            printf("Estado: ");
                            fflush(stdin);
                            gets(s.end.estado);
                            
                            printf("Data de nascimento: \n");
                            printf("Dia: ");
                            scanf("%d", &s.nascimento.dia);
                            printf("Mes: ");
                            scanf("%d", &s.nascimento.mes);
                            printf("Ano: ");
                            scanf("%d", &s.nascimento.ano);

                            while (!valiDate(dia, mes, ano)){
                                printf("Digite a data de nascimento novamente: \n");
                                printf("Dia: ");
                                scanf("%d", &dia);
                                printf("Mes: ");
                                scanf("%d", &mes);
                                printf("Ano: ");
                                scanf("%d", &ano);
                            }
                
                            insertStudent(&inicioAluno, s);
                            break;
                        }
                        case 2: {
                            //cadastrar livro
                            printf("Digite o ISBN do livro: ");
                            scanf("%ld", &b.isbn);
                            printf("Digite o titulo do livro: ");
                            fflush(stdin);
                            gets(b.titulo);
                            printf("Digite o autor do livro: ");
                            fflush(stdin);
                            gets(b.autor);
                            printf("Digite a editora do livro: ");
                            fflush(stdin);
                            gets(b.editora);
                            printf("Digite o ano do livro: ");
                            scanf("%d", &b.ano.ano);
                            printf("Digite a quantidade de livros: ");
                            scanf("%d", &b.quant);
                            insertBook(&inicioLivro, b);
                            break;
                        }
                        case 3: {
                            //cadastrar emprestimo
                            printf("Digite a matricula do aluno: ");
                            fflush(stdin);
                            gets(l.matriculaE);
                            printf("Digite o ISBN do livro: ");
                            scanf("%ld", &l.isbnE);
                            insertLoan(&inicioEmprestimo, &inicioLivro, inicioAluno, l);
                            break;
                        }
                    
                        case 4:{
                            printf("Voltando ao Menu Principal.\n");
                            break;
                        }

                        default:
                            printf("Opcao invalida!\n");
                            break;
                    }
                } while (opMS != 4); 
                break;
            }
            case 2: {
                do {
                    menuSecundario();
                    scanf("%d", &opMS);

                    switch (opMS) {
                        case 1: {
                            //alterar aluno
                            changeStudent(&inicioAluno);
                            break;
                        }
                        case 2: {
                            //alterar livro
                            changeBook(&inicioLivro);
                            break;
                        }
                        case 3:{
                            //alterar emprestimo
                            changeLoan(&inicioEmprestimo);
                            break;
                        }
                        case 4:
                            printf("Voltando ao Menu Principal.\n");
                            break;
                        default:
                            printf("Opcao invalida!\n");
                            break;
                    }
                } while(opMS != 4);
                break;
            }
            case 3:{
                do{
                    menuSecundario();
                    scanf("%d", &opMS);

                    switch(opMS){
                        case 1:{
                            //procura aluno
                            findStudent(inicioAluno);
                            break;
                        }

                        case 2:{
                            //procura livro
                            findBook(inicioLivro);
                            break;
                        }

                        case 3:{
                            //procura emprestimo
                            findLoan(inicioEmprestimo);
                            break;
                        }

                        case 4:
                            printf("Voltando ao Menu Principal.\n");
                            break;

                        default:
                            printf("Opcao invalida!\n");
                            break;
                    }
                }while(opMS != 4);

            }
                
            case 4:{
                do{
                    menuSecundario();
                    scanf("%d", &opMS);

                    switch (opMS) {
                        case 1: {
                            //deleta aluno
                            removeStudent(&inicioAluno);
                            break;
                        }
                        case 2: {
                            //deleta livro
                            removeBook(&inicioLivro);
                            break;
                        }
                        case 3: {
                            //deleta emprestimo
                            removeLoan(&inicioEmprestimo, &inicioLivro);
                            break;
                        }
                        case 4:
                            break;
                        default:
                            printf("Opcao invalida!\n");
                            break;
                    }
                } while (opMS != 4); 
                break;
            }
                
            case 5:{
                do{
                    menuSecundario();
                    scanf("%d", &opMS);

                    switch (opMS) {
                        case 1: {
                            //lista alunos
                            listStudent(inicioAluno);
                            break;
                        }
                        case 2: {
                            //lista livros
                            listBook(inicioLivro);
                            break;
                        }
                        case 3: {
                            //lista emprestimos
                            listLoan(inicioEmprestimo);
                            break;
                        }
                        case 4:
                            break;
                        default:
                            printf("Opcao invalida!\n");
                            break;
                    }
                } while (opMS != 4);
                break;
            }
            case 6:{
                //salvar
                saveFile(inicioAluno, inicioLivro, inicioEmprestimo);
                break;
            }
            case 7:{
                //carregar
                loadFile(&inicioAluno, &inicioLivro);
                break;
            }
            case 8:{
                //comparar emprestimos
                amountLoan(inicioEmprestimo);
                break;
            }
            case 9:{
                //verificar quantidade de livros
                quantityBooks(inicioLivro);
                break;
            }
            case 10:{
                printf("finalizando...\n");
                break;
            }
            default:{
                printf("Opcao invalida!\n");
                break;
            }
        }
    } while(opMP != 8);
}

int valiDate(int dia, int mes, int ano) {
    if (ano < 0) {
        return 0;
    }
    if (mes < 1 || mes > 12) {
        return 0;
    }
    if (dia < 1 || dia > 31) {
        return 0;
    }
    if (mes == 2) {
        if (ano % 4 == 0) {
            if (dia > 29) {
                return 0;
            }
        } else {
            if (dia > 28) {
                return 0;
            }
        }
    }
    if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        if (dia > 30) {
            return 0;
        }
    }
    return 1;
}

void insertStudent(student **inicio, student s){
    student *novo = (student *)malloc(sizeof(student)); //aloca memoria para cadastrar novo aluno
    //verifica se exise memoria disponivel
    if(!novo){
        printf("Sem memoria disponivel!\n");
        exit(1);
    }
    student *aux = *inicio;
    while(aux != NULL){
        if(strcmp(s.matricula, aux->matricula) == 0){
            printf("Aluno ja cadastrado! Cadastro negado.\n");
            return;
        }
        aux = aux->prox;
    }
    
    strcpy(novo->matricula, s.matricula);
    strcpy(novo->nome, s.nome);
    strcpy(novo->curso, s.curso);
    strcpy(novo->end.rua, s.end.rua);
    strcpy(novo->end.bairro, s.end.bairro);
    strcpy(novo->end.cidade, s.end.cidade);
    strcpy(novo->end.estado, s.end.estado);
    novo->end.numero = s.end.numero;    
    novo->nascimento.dia = s.nascimento.dia;
    novo->nascimento.mes = s.nascimento.mes;
    novo->nascimento.ano = s.nascimento.ano;
    
    novo->prox = novo->ant = NULL;

    if (*inicio == NULL || strcmp(s.matricula, (*inicio)->matricula) < 0){
        novo->prox = *inicio;
        if (*inicio != NULL) {
            (*inicio)->ant = novo;
        }
        *inicio = novo;
    } else {
        student *aux = *inicio;
        while (aux->prox != NULL && strcmp(s.matricula, aux->prox->matricula) > 0){
            aux = aux->prox;
        }
        novo->prox = aux->prox;
        novo->ant = aux;
        if (aux->prox != NULL) {
            aux->prox->ant = novo;
        }
        aux->prox = novo;
    }
    printf("Aluno cadastrado com sucesso.\n");
}

void insertBook(book **inicio, book b){
    book *novo = (book *)malloc(sizeof(book));
    if (!novo) {
        printf("Sem memoria disponivel!\n");
        exit(1);
    }

    book *aux = *inicio;
    while(aux != NULL){
        if(b.isbn == aux->isbn){
            printf("Livro ja cadastrado! Cadastro negado.\n");
            return;
        }
        aux = aux->prox;
    }

    novo->isbn = b.isbn;
    strcpy(novo->titulo, b.titulo);
    strcpy(novo->autor, b.autor);
    strcpy(novo->editora, b.editora);
    novo->ano = b.ano;
    novo->quant = b.quant;
    novo->prox = novo->ant = NULL;

    if (*inicio == NULL || strcmp(b.titulo, (*inicio)->titulo) < 0) {
        novo->prox = *inicio;
        if (*inicio != NULL) {
            (*inicio)->ant = novo;
        }
        *inicio = novo;
    } else {
        book *aux = *inicio;
        while (aux->prox != NULL && strcmp(b.titulo, aux->prox->titulo) > 0) {
            aux = aux->prox;
        }
        novo->prox = aux->prox;
        novo->ant = aux;
        if (aux->prox != NULL){
            aux->prox->ant = novo;
        }
        aux->prox = novo;
    }
}

void insertLoan(loan **inicioE, book **inicioL, student *inicioA, loan l){
    loan *auxEmprestimo = *inicioE;

    //verifica se aluno ja pegou o livro emprestado
    while(auxEmprestimo != NULL){
        if (strcmp(l.matriculaE, auxEmprestimo->matriculaE) == 0 && auxEmprestimo->isbnE == l.isbnE){
            printf("Aluno ja pegou este livro emprestado.\n");
            return; // retorna para indicar que o empréstimo não foi feito
        }
        auxEmprestimo = auxEmprestimo->prox;
    }

    //verificar se o livro ta disponivel para empréstimo
    book *auxLivro = *inicioL;
    int livroEncontrado = 0;
    while (auxLivro != NULL) {
        if (auxLivro->isbn == l.isbnE) {
            livroEncontrado = 1;
            return;
        }
        auxLivro = auxLivro->prox;
    }

    if(!livroEncontrado) {
        printf("Livro nao encontrado!\n");
        return;
    }

    if(auxLivro->quant == 0){
        printf("Livro nao disponivel para emprestimo!\n");
        return;
    }

    //verificar se o aluno existe
    student *auxAluno = inicioA;
    int alunoEncontrado = 0;
    while(auxAluno != NULL){
        if (strcmp(l.matriculaE, auxAluno->matricula) == 0) {
            alunoEncontrado = 1;
            break;
        }
        auxAluno = auxAluno->prox;
    }

    if (!alunoEncontrado) {
        printf("Aluno nao encontrado.\n");
        return;
    }

    loan *novo = (loan *)malloc(sizeof(loan));
    if (!novo) {
        printf("Sem memoria disponivel!\n");
        exit(1);
    }

    strcpy(novo->matriculaE, l.matriculaE);
    novo->isbnE = l.isbnE;
    novo->prox = novo->ant = NULL;

    if (*inicioE == NULL) {
        *inicioE = novo;
    } else {
        novo->prox = *inicioE;
        (*inicioE)->ant = novo;
        *inicioE = novo;
    }

    auxLivro->quant--;

    printf("Emprestimo cadastrado com sucesso.\n");
}

void changeStudent(student **inicio){
    student *aux = *inicio;
    char matriculaAux[15];

    printf("Informe a matricula do aluno: ");
    fflush(stdin);
    gets(matriculaAux);
    while(aux != NULL && strcmp(matriculaAux, aux->matricula) != 0){
        aux = aux->prox;
    }
    if(aux == NULL){
        printf("Matricula nao encontrada!\n");
    } else {
        printf("Digite o novo nome do aluno: ");
        fflush(stdin);
        gets(aux->nome);
        printf("Digite a nova rua do aluno: ");
        fflush(stdin);  
        gets(aux->end.rua);
        printf("Digite o novo numero do aluno: ");
        scanf("%d", &aux->end.numero);
        printf("Digite o novo bairro do aluno: ");
        fflush(stdin);
        gets(aux->end.bairro);
        printf("Digite a nova cidade do aluno: ");
        fflush(stdin);
        gets(aux->end.cidade);
        printf("Digite o novo estado do aluno: ");
        fflush(stdin);
        gets(aux->end.estado);
    }
}

void changeBook(book **inicio){
    book *aux = *inicio;
    long int isbnAux;
    printf("Informe o codigo do livro: ");
    scanf("%ld", &isbnAux);

    while(aux != NULL && isbnAux != aux->isbn){
        aux = aux->prox;
    }
    if(aux == NULL){
        printf("Livro nao encontrado!\n");
    } else {
        printf("Digite o novo titulo do livro: ");
        fflush(stdin);
        gets(aux->titulo);
        printf("Digite o novo autor do livro: ");
        fflush(stdin);
        gets(aux->autor);
        printf("Digite a nova editora do livro: ");
        fflush(stdin);
        gets(aux->editora);
        printf("Digite o novo ano do livro: ");
        scanf("%d", &aux->ano.ano);
    }
}

void changeLoan(loan **inicio){
    loan *aux = *inicio;
    char matriculaE[15];
    long int isbnE;

    printf("Informe a matricula do aluno: ");
    fflush(stdin);
    gets(matriculaE);
    printf("Informe o ISBN do livro: ");
    scanf("%ld", &isbnE);

    while(aux != NULL && strcmp(matriculaE, aux->matriculaE) != 0 && isbnE != aux->isbnE){
        aux = aux->prox;
    }
    if(aux == NULL){
        printf("Emprestimo nao encontrado!\n");
    } else {
        printf("Digite a nova matricula do aluno: ");
        fflush(stdin);
        gets(aux->matriculaE);
        printf("Digite o novo ISBN do livro: ");
        scanf("%ld", &aux->isbnE);
    }
}

void removeStudent(student **inicio){
    student *aux = *inicio;

    char matricula[15];
    printf("Informe a matricula do aluno: ");
    fflush(stdin);
    gets(matricula);

    //verifica se matricula existe
    while(aux != NULL && strcmp(matricula, aux->matricula) != 0){
        aux = aux->prox;
    }
    if(aux == NULL){
        printf("Matricula nao encontrada!\n");
        return;
    } 
    else {
        if(aux->ant == NULL){
            *inicio = aux->prox;
        } else {
            aux->ant->prox = aux->prox;
        }
        if(aux->prox != NULL){
            aux->prox->ant = aux->ant;
        }
        free(aux);
        printf("Aluno deletado!\n");
    }
}

void removeBook(book **inicio){
    book *aux = *inicio;

    long int isbn;
    printf("Informe o codigo do livro: ");
    scanf("%ld", &isbn);
    
    while(aux != NULL && isbn != aux->isbn){
        aux = aux->prox;
    }
    if(aux == NULL){
        printf("Livro nao encontrado!\n");
        return;
    } 
    else {
        if(aux->ant == NULL){
            *inicio = aux->prox;
        } else {
            aux->ant->prox = aux->prox;
        }
        if(aux->prox != NULL){
            aux->prox->ant = aux->ant;
        }
        free(aux);
        aux->quant++;
        printf("Livro excluido!\n");
    }
}

void removeLoan(loan **inicio, book **inicioL){
    loan *aux = *inicio;
    book *auxL = *inicioL;

    char matriculaE[15];
    long int isbnE;
    printf("Informe a matricula do aluno: ");
    fflush(stdin);
    gets(matriculaE);
    printf("Informe o codigo do livro: ");
    scanf("%ld", &isbnE);

    while(aux != NULL && strcmp(matriculaE, aux->matriculaE) != 0 && isbnE != aux->isbnE){
        aux = aux->prox;
    }
    if(aux == NULL){
        printf("Aluno nao possui emprestimo para este livro!\n");
        return;
    } 
    else {
        if(aux->ant == NULL){
            *inicio = aux->prox;
        } else {
            aux->ant->prox = aux->prox;
        }
        if(aux->prox != NULL){
            aux->prox->ant = aux->ant;
        }
        free(aux);
        printf("Emprestimo removido!\n");
        auxL->quant++;
    }
}

void findStudent(student *inicio){
    student *aux = inicio;

    char matricula[15];
    printf("Informe a matricula do aluno: ");
    fflush(stdin);
    gets(matricula);

    while(aux != NULL && strcmp(matricula, aux->matricula) != 0){
        aux = aux->prox;
    }
    if(aux == NULL){
        printf("Matricula nao encontrada!\n");
    } else {
        printf("Matricula: %s\n", aux->matricula);
        printf("Nome: %s\n", aux->nome);
        printf("Curso: %s\n", aux->curso);  
        printf("Endereco: %s, %d - %s / %s - %s\n", aux->end.rua, aux->end.numero, aux->end.bairro, aux->end.cidade, aux->end.estado);
        printf("Data de nascimento: %d/%d/%d\n", aux->nascimento.dia, aux->nascimento.mes, aux->nascimento.ano);
        printf("\n");
    }
}

void findBook(book *inicio){
    book *aux = inicio;

    long int isbn;
    printf("Informe o codigo do livro: ");
    scanf("%ld", &isbn);

    while(aux != NULL && isbn != aux->isbn){
        aux = aux->prox;
    }
    if(aux == NULL){
        printf("Livro nao encontrado!\n");
    } else {
        printf("ISBN: %ld\n", aux->isbn);
        printf("Titulo: %s\n", aux->titulo);
        printf("Autor: %s\n", aux->autor);
        printf("Editora: %s\n", aux->editora);
        printf("Ano: %d\n", aux->ano.ano);
        printf("Quantidade Disponivel: %d\n", aux->quant);
        printf("\n");
    }
}

void findLoan(loan *inicio){
    loan *aux = inicio;

    char matriculaE[15];
    long int isbnE;
    printf("Informe a matricula do aluno: ");
    fflush(stdin);
    gets(matriculaE);
    printf("Informe o codigo do livro: ");
    scanf("%ld", &isbnE);

    while(aux != NULL && strcmp(matriculaE, aux->matriculaE) != 0 && isbnE != aux->isbnE){
        aux = aux->prox;
    }
    if(aux == NULL){
        printf("Emprestimo nao encontrado!\n");
    } else {
        printf("Matricula: %s\n", aux->matriculaE);
        printf("ISBN: %ld\n", aux->isbnE);
        printf("\n");
    }
}

void listStudent(student *inicio){
    student *aux = inicio;
    while(aux != NULL){
        printf("Matricula: %s\n", aux->matricula);
        printf("Nome: %s\n", aux->nome);
        printf("Curso: %s\n", aux->curso);
        printf("Endereco: %s, %d - %s / %s - %s\n", aux->end.rua, aux->end.numero, aux->end.bairro, aux->end.cidade, aux->end.estado);
        printf("Data de nascimento: %d/%d/%d\n", aux->nascimento.dia, aux->nascimento.mes, aux->nascimento.ano);
        aux = aux->prox;
        printf("\n");
    }
}

void listBook(book *inicio){
    book *aux = inicio;
    while(aux != NULL){
        printf("ISBN: %ld\n", aux->isbn);
        printf("Titulo: %s\n", aux->titulo);
        printf("Autor: %s\n", aux->autor);
        printf("Editora: %s\n", aux->editora);
        printf("Ano: %d\n", aux->ano.ano);
        printf("Quantidade Disponivel: %d\n", aux->quant);
        aux = aux->prox;
        printf("\n");
    }
}

void listLoan(loan *inicio){
    loan *aux = inicio;
    while(aux != NULL){
        printf("Matricula: %s\n", aux->matriculaE);
        printf("ISBN: %ld\n", aux->isbnE);
        aux = aux->prox;
        printf("\n");
    }
}

void loadFile(student **inicioAluno, book **inicioLivro){
    FILE *arqAluno = fopen("alunos.txt", "r");
    FILE *arqLivro = fopen("livros.txt", "r");
    FILE *arqEmprestimo = fopen("emprestimos.txt", "r");

    if (arqAluno == NULL || arqLivro == NULL || arqEmprestimo == NULL) {
        printf("Erro ao abrir arquivo!\n");
        exit(1);
    }

    student s;
    book b;
    loan l;

    while (fscanf(arqAluno, "%s %s %s %s %s %s %s %d %d %d %d", s.matricula, s.nome, s.curso, s.end.rua, s.end.bairro, s.end.cidade, s.end.estado, &s.end.numero, &s.nascimento.dia, &s.nascimento.mes, &s.nascimento.ano) != EOF) {
        insertStudent(inicioAluno, s);
    }

    while (fscanf(arqLivro, "%ld %s %s %s %d %d", &b.isbn, b.titulo, b.autor, b.editora, &b.ano.ano, &b.quant) != EOF) {
        insertBook(inicioLivro, b);
    }

    while (fscanf(arqEmprestimo, "%s %ld", l.matriculaE, &l.isbnE) != EOF) {
        void insertLoan(loan **inicioE, book **inicioL, student *inicioA, loan l);
    }

    fclose(arqAluno);
    fclose(arqLivro);
    fclose(arqEmprestimo);
}

void amountLoan(loan *inicio){
    loan *aux = inicio;
    int cont = 0, contE = 0;
    int quant = 0;        

    printf("Informe a quantidade de emprestimos que deseja verificar: ");
    scanf("%d", &quant);

    while(aux != NULL){
        if(aux->matriculaE == aux->matriculaE){
            cont++;
            aux = aux->prox;
        }
        if(cont > quant){
            contE++;
        }
    }
    printf("%d estudantes com mais de %d emprestimos.\n", contE, quant);
}

void quantityBooks(book *inicio){
    book *aux = inicio;
    int quant = 0;

    printf("Informe a quantidade de livros que deseja verificar: ");
    scanf("%d", &quant);

    while(aux != NULL){
        if(aux->quant > quant){
            printf("ISBN: %ld\n", aux->isbn);
            printf("Titulo: %s\n", aux->titulo);
            printf("Autor: %s\n", aux->autor);
            printf("Editora: %s\n", aux->editora);
            printf("Ano: %d\n", aux->ano.ano);
            printf("Quantidade: %d\n", aux->quant);
        }
        aux = aux->prox;
    }
}

void saveFile(student *inicioAluno, book *inicioLivro, loan *inicioEmprestimo){
    FILE *arqAluno = fopen("alunos.txt", "w");
    FILE *arqLivro = fopen("livros.txt", "w");
    FILE *arqEmprestimo = fopen("emprestimos.txt", "w");

    if (arqAluno == NULL || arqLivro == NULL || arqEmprestimo == NULL) {
        printf("Erro ao abrir arquivo!\n");
        perror("Erro detalhado:");
        exit(1);
    }

    student *auxAluno = inicioAluno;
    book *auxLivro = inicioLivro;
    loan *auxEmprestimo = inicioEmprestimo;

    while (auxAluno != NULL) {
        fprintf(arqAluno, "%s %s %s %s %s %s %s %d %d %d %d\n", auxAluno->matricula, auxAluno->nome, auxAluno->curso, auxAluno->end.rua, auxAluno->end.bairro, auxAluno->end.cidade, auxAluno->end.estado, auxAluno->end.numero, auxAluno->nascimento.dia, auxAluno->nascimento.mes, auxAluno->nascimento.ano);
        auxAluno = auxAluno->prox;
    }

    printf("Debug: Loop de alunos concluído.\n");

    while (auxLivro != NULL) {
        fprintf(arqLivro, "%ld %s %s %s %d %d\n", auxLivro->isbn, auxLivro->titulo, auxLivro->autor, auxLivro->editora, auxLivro->ano.ano, auxLivro->quant);
        auxLivro = auxLivro->prox;
    }

    printf("Debug: Loop de livros concluído.\n");

    while (auxEmprestimo != NULL) {
        fprintf(arqEmprestimo, "%s %ld\n", auxEmprestimo->matriculaE, auxEmprestimo->isbnE);
        auxEmprestimo = auxEmprestimo->prox;
    }

    printf("Debug: Loop de empréstimos concluído.\n");

    fclose(arqAluno);
    fclose(arqLivro);
    fclose(arqEmprestimo);
}

void menuPrincipal() {
    printf("Menu:\n");
    printf("1. CADASTRAR\n");
    printf("2. ALTERAR\n");
    printf("3. CONSULTAR\n");
    printf("4. DELETAR\n");
    printf("5. LISTAR\n");
    printf("6. Salvar\n");
    printf("7. Carregar\n");
    printf("8. COMPARAR EMPRESTIMOS\n");
    printf("9. VERIFICAR QUANTIDADES DE LIVROS\n");
    printf("10. Sair\n");
    printf("Escolha uma opcao: ");
}

void menuSecundario(){
    printf("Menu:\n");
    printf("1. ALUNO\n");
    printf("2. LIVRO\n");
    printf("3. EMPRESTIMO\n");
    printf("4. Sair\n");
    printf("Escolha uma opcao: ");
}
