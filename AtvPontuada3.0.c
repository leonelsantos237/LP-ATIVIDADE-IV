#include <stdio.h>
#include <string.h>
#include <locale.h>


struct Produto {
    char nome[333];
    float preco;
    int quantidadeEstoque;
};


float calcularValorTotal(struct Produto produto) {
    return produto.preco * produto.quantidadeEstoque;
}


void realizarCompra(struct Produto *produto) {
    int quantidadeCompra;

    printf("Digite a quantidade a ser comprada: ");
    scanf("%d", &quantidadeCompra);

    if (quantidadeCompra > 0 && quantidadeCompra <= produto->quantidadeEstoque) {
        produto->quantidadeEstoque -= quantidadeCompra;
        printf("Compra realizada com sucesso. Novo estoque: %d\n", produto->quantidadeEstoque);
    } else {
        printf("Quantidade invÃ¡lida. Compra nÃ£o realizada.\n");
    }
}

// FunÃ§Ã£o para consultar o estoque
void consultarEstoque(struct Produto produto) {
    printf("Nome do produto: %s\n", produto.nome);
    printf("Quantidade em estoque: %d\n", produto.quantidadeEstoque);
    printf("PreÃ§o por unidade: R$ %.2f\n", produto.preco);
    printf("Valor total em estoque: R$ %.2f\n", calcularValorTotal(produto));
}

// FunÃ§Ã£o para adicionar um novo produto
void adicionarProduto(struct Produto *produto) {
    printf("Digite o nome do produto: ");
    scanf("%s", produto->nome);
    printf("Digite a quantidade em estoque: ");
    scanf("%d", &produto->quantidadeEstoque);
    printf("Digite o preÃ§o por unidade: ");
    scanf("%f", &produto->preco);
}

int main() {
      setlocale(LC_ALL, "");
    struct Produto meuProduto;

    int escolha;

    do {
        printf("\n===== Menu =====\n");
        printf("1. Adicionar produto\n");
        printf("2. Realizar uma compra\n");
        printf("3. Consultar estoque\n");
        printf("4. Sair do programa\n");

        printf("Escolha uma opção: \n");
        scanf("%d", &escolha);
        fflush(stdin);
        switch (escolha) {
            case 1:
                adicionarProduto(&meuProduto);
                break;

            case 2:
                realizarCompra(&meuProduto);
                break;

            case 3:
                consultarEstoque(meuProduto);
                break;

            case 4:
                printf("Saindo do programa. AtÃ© logo!\n");
                break;

            default:
                printf("OpÃ§Ã£o invÃ¡lida. Tente novamente.\n");
        }

    } while (escolha != 4);

    return 0;
}
