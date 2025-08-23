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

void registrarAdocao(int Cod[10], int Status[10], int num_animais) {
    printf("=== Registro de Adoção ===\n");
    int codigoBusca;

    printf("Informe o codigo do animal a ser adotado: ");
    scanf("%d", &codigoBusca); //pede um código de busca, pra comparar com todos os códigos no vetor Cod.

    for (int i = 0; i < num_animais; i++) {
        if (Cod[i] == codigoBusca) {  //se encontrar o código equivalente, checa o status que está na mesma posição que o código (i).
            if (Status[i] == 0) {  // se o status estiver zerado ( não adotado) então muda pra um ( adotado)
                Status[i] = 1;
                printf("Adoção registrada com sucesso!\n\n");
            } else {   // se o status não for 0 ele passa pro else.
                printf("Erro: Este animal ja foi adotado.\n\n");
            }
            return; 
        }
    }

    // Se o laço terminou e a função chegou até aqui, o animal não foi encontrado.
    printf("Erro: Animal com este codigo não foi encontrado.\n\n");
}

void pesquisarAnimal() {
    printf("=== Pesquisa de Animal ===\n");
    // Aqui vocÃª colocaria o cÃ³digo para pesquisar um animal
    printf("Animal encontrado (exemplo)!\n\n");
}

void relatorioAdocoes() {
    printf("=== RelatÃ³rio de AdoÃ§Ãµes ===\n");
    // Aqui vocÃª colocaria o cÃ³digo para imprimir relatÃ³rio de adoÃ§Ãµes
    printf("Lista de adoÃ§Ãµes...\n\n");
}

void relatorioAnimaisDisponiveis() {
    printf("=== RelatÃ³rio de Animais DisponÃ­veis ===\n");
    // Aqui vocÃª colocaria o cÃ³digo para imprimir relatÃ³rio de animais disponÃ­veis
    printf("Lista de animais disponÃ­veis...\n\n");
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
                registrarAdocao();
                break;
            case 3:
                pesquisarAnimal();
                break;
            case 4:
                relatorioAdocoes();
                break;
            case 5:
                relatorioAnimaisDisponiveis();
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

