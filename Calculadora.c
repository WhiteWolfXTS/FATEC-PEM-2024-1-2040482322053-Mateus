#include <stdio.h>

#define OPERACAO_SAIR 'S'

// Protótipos das funções
float realizarOperacao(char operacao, float num1, float num2);
char obterOperacao();
float obterNumero();

int main() {
    char operacao;
    float num1, num2, resultado;

    printf("Bem-vindo à calculadora\n");

    do {
        operacao = obterOperacao();

        if (operacao == OPERACAO_SAIR) {
            printf("Saindo...\n");
            break;
        }

        num1 = obterNumero();
        num2 = obterNumero();

        resultado = realizarOperacao(operacao, num1, num2);

        printf("Resultado: %.2f\n", resultado);

    } while (1);

    return 0;
}

float realizarOperacao(char operacao, float num1, float num2) {
    switch (operacao) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            if (num2 != 0)
                return num1 / num2;
            else {
                printf("Erro: Divisão por zero!\n");
                return 0;
            }
        default:
            printf("Operação inválida!\n");
            return 0;
    }
}

char obterOperacao() {
    char operacao;

    do {
        printf("Digite a operação desejada (+, -, *, / ou 'S' para sair): ");
        scanf(" %c", &operacao);
    } while (operacao != '+' && operacao != '-' && operacao != '*' && operacao != '/' && operacao != OPERACAO_SAIR);

    return operacao;
}

float obterNumero() {
    float num;

    printf("Digite um número: ");
    scanf("%f", &num);

    return num;
}
