#include <stdio.h>

void imprimirTabuleiro(char tabuleiro[8][8]) {
    printf("  a b c d e f g h\n"); // Letras das colunas
    for (int i = 0; i < 8; i++) {
        printf("%d ", 8 - i); // Números das linhas
        for (int j = 0; j < 8; j++) {
            if ((i + j) % 2 == 0) {
                printf("\033[47m"); // Casas brancas
            } else {
                printf("\033[40m"); // Casas pretas
            }
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\033[0m\n"); // Resetar a cor após cada linha
    }
}

int main() {
    char tabuleiro[8][8] = {
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}
    };

    imprimirTabuleiro(tabuleiro);

    // Jogada #1
    printf("\nJogada #1:\n");
    printf("Brancas jogam Peão do Rei (e2) para (e4)\n");
    tabuleiro[4][4] = 'P';
    tabuleiro[6][4] = '.';
    tabuleiro[5][4] = '.';
    imprimirTabuleiro(tabuleiro);
    printf("\nPretas jogam Peão do Rei (e7) para (e5)\n");
    tabuleiro[3][4] = 'p';
    tabuleiro[1][4] = '.';
    tabuleiro[2][4] = '.';
    tabuleiro[6][4] = ' ';
    tabuleiro[5][4] = ' ';
    imprimirTabuleiro(tabuleiro);

    // Jogada #2
    printf("\nJogada #2:\n");
    printf("Brancas jogam Bispo do Rei (f1) para (c4)\n");
    tabuleiro[4][2] = 'B';
    tabuleiro[7][5] = '.';
    tabuleiro[6][4] = '.';
    tabuleiro[5][3] = '.';
    tabuleiro[1][4] = ' ';
    tabuleiro[2][4] = ' ';
    imprimirTabuleiro(tabuleiro);
    printf("\nPretas jogam Cavalo da Dama (b8) para (c6)\n");
    tabuleiro[2][2] = 'n';
    tabuleiro[0][1] = '.';
    tabuleiro[2][1] = '.';
    tabuleiro[7][5] = ' ';
    tabuleiro[6][4] = ' ';
    tabuleiro[5][3] = ' ';
    imprimirTabuleiro(tabuleiro);

    // Jogada #3
    printf("\nJogada #3:\n");
    printf("Brancas jogam Dama (d1) para (h5)\n");
    tabuleiro[3][7] = 'Q';
    tabuleiro[7][3] = '.';
    tabuleiro[6][4] = '.';
    tabuleiro[5][5] = '.';
    tabuleiro[4][6] = '.';
    tabuleiro[0][1] = ' ';
    tabuleiro[2][1] = ' ';
    imprimirTabuleiro(tabuleiro);
    printf("\nPretas jogam Cavalo do Rei (g8) para (f6)\n");
    tabuleiro[2][5] = 'n';
    tabuleiro[0][6] = '.';
    tabuleiro[2][6] = '.';
    tabuleiro[7][3] = ' ';
    tabuleiro[6][4] = ' ';
    tabuleiro[5][5] = ' ';
    tabuleiro[4][6] = ' ';
    imprimirTabuleiro(tabuleiro);

    // Jogada #4
    printf("\nJogada #4: Xeque Mate\n");
    printf("Brancas capturam Peão do Rei (f7) e dão Xeque Mate\n");
    tabuleiro[1][5] = 'Q';
    tabuleiro[3][7] = '.';
    tabuleiro[0][6] = ' ';
    imprimirTabuleiro(tabuleiro);

    return 0;
}