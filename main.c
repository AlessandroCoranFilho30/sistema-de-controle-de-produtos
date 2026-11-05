#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char produto[10][20];
char cliente[20][20];
float valor[10];
int quantidade[10];
int i = 0;

char venda_produto[20][20];
int venda_qtd[20];
float venda_total[20];
int num_vendas = 0;

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void cadastro() {
    char resp = 'N';

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
        produto[i][strcspn(produto[i], "\n")] = '\0';

        printf("Informe o valor: R$ ");
        scanf("%f", &valor[i]);
        limpar_buffer();

        printf("Informe a quantidade: ");
        scanf("%d", &quantidade[i]);
        limpar_buffer();

        i++;

        printf("\nDeseja continuar o cadastro [S]im ou [N]ao? ");
        scanf(" %c", &resp);
        resp = toupper(resp);
        limpar_buffer();
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
    busca[strcspn(busca, "\n")] = '\0';

    printf("\n--- RESULTADO DA BUSCA ---\n");

    for (int j = 0; j < i; j++) {
        if (strcmp(produto[j], busca) == 0) {
            printf("\nProduto: %s\n", produto[j]);
            printf("Valor: R$ %.2f\n", valor[j]);
            printf("Quantidade: %d\n", quantidade[j]);
            encontrado++;
        }
    }

    if (encontrado == 0) {
        printf("\nProduto nao encontrado!\n");
    }

    system("pause");
}

void relatorio_produtos() {
    float total_estoque = 0;

    system("cls");
    printf("\n***************************************************");
    printf("\n************* RELATORIOS DOS PRODUTOS *************");
    printf("\n***************************************************\n");

    if (i == 0) {
        printf("\nNenhum produto cadastrado no sistema.\n");
        system("pause");
        return;
    }

    printf("\n%-15s %10s %8s %14s\n", "PRODUTO", "VALOR", "QTD", "SUBTOTAL");
    printf("---------------------------------------------------\n");

    for (int j = 0; j < i; j++) {
        printf("%-15s %10.2f %8d %14.2f\n", produto[j], valor[j], quantidade[j], valor[j] * quantidade[j]);
        total_estoque = total_estoque + (valor[j] * quantidade[j]);
    }

    printf("---------------------------------------------------\n");
    printf("VALOR TOTAL EM ESTOQUE: R$ %.2f\n", total_estoque);

    system("pause");
}

void venda() {
    char busca[20];
    int pos = -1;
    int qtd_vendida = 0;
    float total;

    system("cls");
    printf("\n***********************************");
    printf("\n **** VENDA E BAIXA DE PRODUTOS ***");
    printf("\n***********************************\n");

    if (i == 0) {
        printf("\nNenhum produto cadastrado para venda.\n");
        system("pause");
        return;
    }

    if (num_vendas >= 20) {
        printf("\nLimite maximo de vendas atingido (20/20)!\n");
        system("pause");
        return;
    }

    printf("\n--- PRODUTOS DISPONIVEIS ---\n");
    for (int j = 0; j < i; j++) {
        printf("%-15s | %d un. | R$ %.2f\n", produto[j], quantidade[j], valor[j]);
    }

    printf("\nNome do produto a vender: ");
    fgets(busca, 20, stdin);
    busca[strcspn(busca, "\n")] = '\0';

    for (int j = 0; j < i; j++) {
        if (strcmp(produto[j], busca) == 0) {
            pos = j;
        }
    }

    if (pos == -1) {
        printf("\nProduto nao encontrado!\n");
        system("pause");
        return;
    }

    printf("Quantidade a vender: ");
    scanf("%d", &qtd_vendida);
    limpar_buffer();

    if (qtd_vendida <= 0) {
        printf("\nQuantidade invalida!\n");
        system("pause");
        return;
    }

    if (qtd_vendida > quantidade[pos]) {
        printf("\nEstoque insuficiente! Disponivel: %d un.\n", quantidade[pos]);
        system("pause");
        return;
    }

    printf("Nome do cliente: ");
    fgets(cliente[num_vendas], 20, stdin);
    cliente[num_vendas][strcspn(cliente[num_vendas], "\n")] = '\0';

    total = qtd_vendida * valor[pos];

    quantidade[pos] = quantidade[pos] - qtd_vendida;

    strcpy(venda_produto[num_vendas], produto[pos]);
    venda_qtd[num_vendas] = qtd_vendida;
    venda_total[num_vendas] = total;
    num_vendas++;

    printf("\n--- VENDA REALIZADA COM SUCESSO ---\n");
    printf("Produto: %s\n", produto[pos]);
    printf("Cliente: %s\n", cliente[num_vendas - 1]);
    printf("Quantidade: %d\n", qtd_vendida);
    printf("Total: R$ %.2f\n", total);
    printf("Estoque atualizado: %d un.\n", quantidade[pos]);

    if (quantidade[pos] == 0) {
        printf("\nAtencao: estoque de %s zerado!\n", produto[pos]);
    }

    system("pause");
}

void relatorio_saida() {
    float total_geral = 0;

    system("cls");
    printf("\n*****************************************************************");
    printf("\n ******************** RELATORIO DE SAIDAS ***********************");
    printf("\n*****************************************************************\n");

    if (num_vendas == 0) {
        printf("\nNenhuma venda registrada no sistema.\n");
        system("pause");
        return;
    }

    printf("\n%-15s %-15s %8s %12s\n", "PRODUTO", "CLIENTE", "QTD", "TOTAL");
    printf("-----------------------------------------------------------------\n");

    for (int j = 0; j < num_vendas; j++) {
        printf("%-15s %-15s %8d %12.2f\n", venda_produto[j], cliente[j], venda_qtd[j], venda_total[j]);
        total_geral = total_geral + venda_total[j];
    }

    printf("-----------------------------------------------------------------\n");
    printf("TOTAL GERAL DE VENDAS: R$ %.2f\n", total_geral);

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
        printf("\n [ 5 ] - RELATORIO DE SAIDAS");
        printf("\n [ 0 ] - SAIR DO SISTEMA");
        printf("\n**************************************\n");
        printf("Escolha a opcao: ");

        if (scanf("%d", &op) != 1) {
            op = -1;
        }
        limpar_buffer();

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
