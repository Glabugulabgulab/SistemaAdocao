#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int cadastrarAnimal(char E[10][20], char C[10][20], int ID[10], int Cod[10], int Status[10], int num_animais){
    printf("=== Cadastro de Animal ===\n");
    printf("Informe a especie: ");
    scanf("%s", E[num_animais]);
    printf("Informe a idade: ");
    scanf("%d", &ID[num_animais]);
    printf("Informe a cor: ");
    scanf("%s", C[num_animais]);
    printf("Informe o codigo: ");
    scanf("%d", &Cod[num_animais]);
    Status[num_animais] = 0; // Inicializa status como disponÃ­vel
    
    printf("Animal cadastrado com sucesso!\n");
    return num_animais + 1; //retorna total atualizado
}

void registrarAdocao(char E[10][20], char C[10][20], int ID[10], int Cod[10], int Status[10], int num_animais) {
    printf("=== Registro de Adoção ===\n");
    int codigoBusca;

    printf("Informe o codigo do animal a ser adotado: ");
    scanf("%d", &codigoBusca); //pede um código de busca, pra comparar com todos os códigos no vetor Cod.
    
    for (int i = 0; i < num_animais; i++) {
        if (Cod[i] == codigoBusca) {  //se encontrar o código equivalente, checa o status que está na mesma posição que o código (i).
            if (Status[i] == 0) {  // se o status estiver zerado ( não adotado) então muda pra um ( adotado)
                Status[i] = 1;
                printf("Adoção registrada com sucesso!\n\n");
                printf("Espécie: %s | Idade: %d | Cor: %s | Código: %d\n\n", E[i], ID[i], C[i], Cod[i]);
            } else {   // se o status não for 0 ele passa pro else.
                printf("Erro: Este animal ja foi adotado.\n\n");
            }
            return; 
        }
    }
    printf("Erro: Animal com este codigo não foi encontrado.\n\n");
}

void pesquisarAnimal(char E[10][20], char C[10][20], int ID[10], int Cod[10], int num_animais) {
    printf("=== Pesquisa de Animal ===\n");
    int codigoBusca;
    printf("Informe o código do animal: ");
    scanf("%d", &codigoBusca);

    for (int i = 0; i < num_animais; i++) {
        if (Cod[i] == codigoBusca) {
            printf("\nAnimal encontrado:\n");
            printf("Espécie: %s | Idade: %d | Cor: %s | Código: %d\n\n", E[i], ID[i], C[i], Cod[i]);
            return;
        }
    }
    printf("Animal não encontrado!\n\n");
}

void relatorioAdocoes(char E[10][20], char C[10][20], int ID[10], int Cod[10], int Status[10], int num_animais) {
    printf("=== Relatório de Adoções ===\n");
    int encontrou = 0;
    for (int i = 0; i < num_animais; i++) {
        if (Status[i] == 1) {
            printf("Espécie: %s | Idade: %d | Cor: %s | Código: %d\n", E[i], ID[i], C[i], Cod[i]);
            encontrou = 1;
        }
    }
    if (!encontrou) {
        printf("Nenhum animal adotado.\n");
    }
    printf("\n");
}

void relatorioAnimaisDisponiveis(char E[10][20], char C[10][20], int ID[10], int Cod[10], int Status[10], int num_animais) {
    printf("=== Relatório de Animais Disponíveis ===\n");
    int encontrou = 0;
    for (int i = 0; i < num_animais; i++) {
        if (Status[i] == 0) {
            printf("Espécie: %s | Idade: %d | Cor: %s | Código: %d\n", E[i], ID[i], C[i], Cod[i]);
            encontrou = 1;
        }
    }
    if (!encontrou) {
        printf("Nenhum animal disponível.\n");
    }
    printf("\n");
}

int main() {
    int opcao;
    char E[10][20];
    char C[10][20];
    int ID[10];
    int Cod[10];
    int Status[10] = {0};
    int num_animais = 0;

    do {
        printf("========= MENU =========\n");
        printf("1. Cadastrar animal\n");
        printf("2. Registrar adoÃ§Ã£o\n");
        printf("3. Pesquisar animal\n");
        printf("4. Imprimir relatÃ³rio de adoÃ§Ãµes\n");
        printf("5. Imprimir relatÃ³rio de animais disponÃ­veis\n");
        printf("6. Sair\n");
        printf("========================\n");
        printf("Escolha uma opÃ§Ã£o: ");
        scanf("%d", &opcao);

        system("cls || clear"); // Limpa a tela no Windows (cls) ou Linux/Mac (clear)

        switch(opcao) {
            case 1:
                num_animais = cadastrarAnimal(E, C, ID, Cod, Status, num_animais);
                break;
            case 2:
                registrarAdocao(E, C, ID, Cod, Status, num_animais);
                break;
            case 3:
                pesquisarAnimal(E, C, ID, Cod, num_animais);
                break;
            case 4:
                relatorioAdocoes(E, C, ID, Cod, Status, num_animais);
                break;
            case 5:
                relatorioAnimaisDisponiveis(E, C, ID, Cod, Status, num_animais);
                break;
            case 6:
                printf("Saindo...\n");
                break;
            default:
                printf("OpÃ§Ã£o invÃ¡lida! Tente novamente.\n\n");
        }

    } while(opcao != 6);

    return 0;
}




