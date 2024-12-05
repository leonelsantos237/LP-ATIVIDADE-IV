#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() 
{
    setlocale(LC_ALL, "portuguese");

    int num1, num2, i, resultado;
    int opcao;

    // Exibe o menu de operações
    printf("Escolha uma operação:\n");
    printf("1 - Tabuada de multiplicação\n");
    printf("2 - Soma\n");
    printf("3 - Subtração\n");
    printf("4 - Multiplicação\n");
    printf("5 - Divisão\n");
    printf("Digite sua opção: ");
    scanf("%d", &opcao);

    switch (opcao) 
    {
        case 1:
            
            printf("Digite um numero para calcular a tabuada: ");
            scanf("%d", &num1);

            printf("Tabuada de %d:\n", num1);
            for (i = 1; i <= 10; i++) 
            {
                resultado = num1 * i;
                printf("%d x %d = %d\n", num1, i, resultado);
            }
            break;
        
        case 2:
           
            printf("Digite dois números para somar: ");
            scanf("%d %d", &num1, &num2);
            resultado = num1 + num2;
            printf("Resultado: %d + %d = %d\n", num1, num2, resultado);
            break;

        case 3:
           
            printf("Digite dois números para subtrair: ");
            scanf("%d %d", &num1, &num2);
            resultado = num1 - num2;
            printf("Resultado: %d - %d = %d\n", num1, num2, resultado);
            break;

        case 4:
           
            printf("Digite dois números para multiplicar: ");
            scanf("%d %d", &num1, &num2);
            resultado = num1 * num2;
            printf("Resultado: %d x %d = %d\n", num1, num2, resultado);
            break;

        case 5:
            
            printf("Digite dois números para dividir: ");
            scanf("%d %d", &num1, &num2);
            if (num2 != 0) {
                resultado = num1 / num2;
                printf("Resultado: %d ÷ %d = %d\n", num1, num2, resultado);
            } else {
                printf("Erro: Divisão por zero não permitida.\n");
            }
            break;

        default:
            printf("Opção inválida.\n");
    }

    return 0;
}
