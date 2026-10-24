#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char produto[10][20];
char cliente[10][20];
float valor[10];
int quantidade[10];
int i = 0;

void cadastro() {
    char resp;
    
    do {
        system("cls");
        printf("\n***********************************");
        printf("\n ***** CADASTRO DE PRODUTOS *****");
        printf("\n***********************************\n");

        if (i >= 10) {
            printf("\nLimite maximo de produtos atingido (10/10)!\n");
            system("pause");
            break;
        }

        printf("\nInforme o produto: ");
        fgets(produto[i], 20, stdin);
        setbuf(stdin, NULL);

        printf("Informe o valor: R$ ");
        scanf("%f", &valor[i]);
        setbuf(stdin, NULL);

        printf("Informe a quantidade: ");
        scanf("%d", &quantidade[i]);
        setbuf(stdin, NULL);

        i++;

        printf("\nDeseja continuar o cadastro [S]im ou [N]ao? ");
        resp = getchar();
        resp = toupper(resp);
        setbuf(stdin, NULL);
    } while (resp != 'N');
}

void consulta() {
    char busca[20];
    int encontrado = 0;

    system("cls");
    printf("\n***********************************");
    printf("\n ***** CONSULTA DE PRODUTOS *****");
    printf("\n***********************************\n");

    if (i == 0) {
        printf("\nNenhum produto cadastrado no sistema.\n");
        system("pause");
        return;
    }

    printf("\nDigite o nome do produto para buscar: ");
    fgets(busca, 20, stdin);
    setbuf(stdin, NULL);

    system("pause");
}

void relatorio_produtos() {
    system("cls");
    printf("\n***************************************************");
    printf("\n************* RELATORIOS DOS PRODUTOS *************");
    printf("\n***************************************************\n");

    if (i == 0) {
        printf("\nNenhum produto cadastrado no sistema.\n");
        system("pause");
        return;
    }

    system("pause");
}

void venda() {
    system("cls");
    printf("\n***********************************");
    printf("\n **** VENDA E BAIXA DE PRODUTOS ***");
    printf("\n***********************************\n");

    if (i == 0) {
        printf("\nNenhum produto cadastrado para venda.\n");
        system("pause");
        return;
    }

    system("pause");
}

void relatorio_saida() {
    system("cls");
    printf("\n*****************************************************************");
    printf("\n ******************** RELATORIO DE SAIDAS ***********************");
    printf("\n*****************************************************************\n");
    
    system("pause");
}

int main() {
    int op;

    do {
        system("cls");
        printf("\n**************************************");
        printf("\n ** SISTEMA DE CONTROLE DE PRODUTOS **");
        printf("\n ****** CURSO DE ADS - FATEC AM ******");
        printf("\n**************************************");
        printf("\n [ 1 ] - CADASTRO DE PRODUTOS");
        printf("\n [ 2 ] - CONSULTA DE PRODUTOS");
        printf("\n [ 3 ] - RELATORIOS DOS PRODUTOS");
        printf("\n [ 4 ] - VENDA E BAIXA DE PRODUTOS");
        printf("\n [ 5 ] - RELATORIO DE SAIDA");
        printf("\n [ 0 ] - SAIR DO SISTEMA");
        printf("\n**************************************\n");
        printf("Escolha a opcao: ");
        scanf("%d", &op);
        setbuf(stdin, NULL);

        switch (op) {
            case 1:
                cadastro();
                break;
            case 2:
                consulta();
                break;
            case 3:
                relatorio_produtos();
                break;
            case 4:
                venda();
                break;
            case 5:
                relatorio_saida();
                break;
            case 0:
                printf("\nSaindo do sistema...\n");
                system("pause");
                break;
            default:
                printf("\nOpcao invalida.. tente novamente.\n");
                system("pause");
                break;
        }
        
    } while (op != 0);
}