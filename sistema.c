#include <stdio.h>
#include <stdlib.h>


void cadastrarAnimal() {
    printf("=== Cadastro de Animal ===\n");
    // Aqui você colocaria o código para cadastrar um animal
    printf("Animal cadastrado com sucesso!\n\n");
}

void registrarAdocao() {
    printf("=== Registro de Adoção ===\n");
    // Aqui você colocaria o código para registrar uma adoção
    printf("Adoção registrada com sucesso!\n\n");
}

void pesquisarAnimal() {
    printf("=== Pesquisa de Animal ===\n");
    // Aqui você colocaria o código para pesquisar um animal
    printf("Animal encontrado (exemplo)!\n\n");
}

void relatorioAdocoes() {
    printf("=== Relatório de Adoções ===\n");
    // Aqui você colocaria o código para imprimir relatório de adoções
    printf("Lista de adoções...\n\n");
}

void relatorioAnimaisDisponiveis() {
    printf("=== Relatório de Animais Disponíveis ===\n");
    // Aqui você colocaria o código para imprimir relatório de animais disponíveis
    printf("Lista de animais disponíveis...\n\n");
}

int main() {
    int opcao;

    do {
        printf("========= MENU =========\n");
        printf("1. Cadastrar animal\n");
        printf("2. Registrar adoção\n");
        printf("3. Pesquisar animal\n");
        printf("4. Imprimir relatório de adoções\n");
        printf("5. Imprimir relatório de animais disponíveis\n");
        printf("6. Sair\n");
        printf("========================\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        system("cls || clear"); // Limpa a tela no Windows (cls) ou Linux/Mac (clear)

        switch(opcao) {
            case 1:
                cadastrarAnimal();
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
                printf("Opção inválida! Tente novamente.\n\n");
        }

    } while(opcao != 6);

    return 0;
}
