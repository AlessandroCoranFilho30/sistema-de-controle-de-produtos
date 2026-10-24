#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char produto[10][20];
float valor[10];
int quantidade[10];
char cliente[10][20];
int i = 0;

void cadastro() {
    char resp;
    
    do {
        printf("\n***********************************");
        printf("\n **** CADASTRO DE PRODUTOS *****");
        printf("\n***********************************\n");

        if (i >= 10) {
            printf("\nLimite maximo de produtos atingido (10/10)!\n");
            system("pause");
            break;
        }

        printf("\nInforme o produto: ");
        fgets(produto[i], 20, stdin);
        setbuf(stdin, NULL);

        printf("Informe o valor: ");
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

int main() {
    int op;

    do {
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
                printf("\nFuncao a ser desenvolvida.\n");
                system("pause");
                break;
            case 3:
                printf("\nFuncao a ser desenvolvida.\n");
                system("pause");
                break;
            case 4:
                printf("\nFuncao a ser desenvolvida.\n");
                system("pause");
                break;
            case 5:
                printf("\nFuncao a ser desenvolvida.\n");
                system("pause");
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

    return 0;
}

