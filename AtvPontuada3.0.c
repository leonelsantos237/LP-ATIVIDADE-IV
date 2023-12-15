#include <stdio.h>

struct Produto
{
    char nome[50];
    float preco;
    int quantidade;
};

float calcularTotal(struct Produto *produto)
{
    return produto->preco * produto->quantidade;
}

void realizarCompra(struct Produto *produto)
{
    int quantidadeCompra;
    printf("Informe a quantidade a ser comprada: ");
    scanf("%d", &quantidadeCompra);

    if (quantidadeCompra > 0 && quantidadeCompra <= produto->quantidade)
    {
        produto->quantidade -= quantidadeCompra;
        printf("Compra feita!\n");
    }
    else
    {
        printf("Quantidade inválida. Verifique o estoque.\n");
    }
}

int main()
{

    struct Produto meuProduto = {"Produto A", 10.0, 50};

    int opcao;

    do
    {

        printf("\nMenu:\n");
        printf("1. Fazer uma compra\n");
        printf("2. Olhar estoque\n");
        printf("3. Sair do programa\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            realizarCompra(&meuProduto);
            break;
        case 2:
            printf("Estoque disponível: %d unidades\n", meuProduto.quantidade);
            printf("Valor total em estoque: R$ %.2f\n", calcularTotal(&meuProduto));
            break;
        case 3:
            printf("Fechando Programa...\n");
            break;
        default:
            printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 3);

    return 0;
}