#include <stdio.h>

int main() {
    // Define o tamanho do tabuleiro
    int tamanho = 8;

    // Tabuleiro representado como uma matriz de caracteres
    char tabuleiro[tamanho][tamanho];

    // Inicializa o tabuleiro com espaços em branco
    for (int linha = 0; linha < tamanho; linha++) {
        for (int coluna = 0; coluna < tamanho; coluna++) {
            tabuleiro[linha][coluna] = ' ';
        }
    }

    // Define as peças brancas
    char torreBranca = 'R';
    char cavaloBranco = 'N';
    char bispoBranco = 'B';
    char reiBranco = 'K';
    char rainhaBranca = 'Q';
    char peaoBranco = 'P';

    // Define as peças pretas
    char torrePreta = 'r';
    char cavaloPreto = 'n';
    char bispoPreto = 'b';
    char reiPreto = 'k';
    char rainhaPreta = 'q';
    char peaoPreto = 'p';

    // Colocando peças nas posições iniciais
    for (int i = 0; i < tamanho; i++) {
        tabuleiro[1][i] = peaoBranco;
        tabuleiro[6][i] = peaoPreto;
    }

    // Peças brancas
    tabuleiro[0][0] = tabuleiro[0][7] = torreBranca;
    tabuleiro[0][1] = tabuleiro[0][6] = cavaloBranco;
    tabuleiro[0][2] = tabuleiro[0][5] = bispoBranco;
    tabuleiro[0][3] = reiBranco;
    tabuleiro[0][4] = rainhaBranca;

    // Peças pretas
    tabuleiro[7][0] = tabuleiro[7][7] = torrePreta;
    tabuleiro[7][1] = tabuleiro[7][6] = cavaloPreto;
    tabuleiro[7][2] = tabuleiro[7][5] = bispoPreto;
    tabuleiro[7][3] = reiPreto;
    tabuleiro[7][4] = rainhaPreta;

    // Variáveis para controle de linhas e colunas
    int linha, coluna;

    // Loop para percorrer linhas
    for (linha = 0; linha < tamanho; linha++) {
        // Loop para percorrer colunas
        for (coluna = 0; coluna < tamanho; coluna++) {
            // Alterna entre as cores das casas
            if ((linha + coluna) % 2 == 0) {
                printf("\033[47m"); // Fundo branco
            } else {
                printf("\033[40m"); // Fundo preto
            }
            printf("%c ", tabuleiro[linha][coluna]); // Imprime o caractere representando a peça
            printf("\033[0m"); // Reseta a cor
        }
        printf("\n"); // Nova linha para começar próxima fileira
    }

    return 0;
}
