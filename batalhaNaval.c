#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.


int main() {
    int tabuleiro[10][10];  // matriz 10x10 que representa o mar (0 = água, 3 = navio)
    int i, j;

    // vetores que representam os navios (cada um com 3 posições)
    int navio1[3] = {3, 3, 3}; // navio horizontal
    int navio2[3] = {3, 3, 3}; // navio vertical
    int navio3[3] = {3, 3, 3}; // navio diagonal principal (↘)
    int navio4[3] = {3, 3, 3}; // navio diagonal secundária (↙)

    // coordenadas iniciais dos navios
    int linhaNavio1 = 2;  // linha inicial do navio 1 (horizontal)
    int colunaNavio1 = 4; // coluna inicial do navio 1 (horizontal)

    int linhaNavio2 = 5;  // linha inicial do navio 2 (vertical)
    int colunaNavio2 = 7; // coluna inicial do navio 2 (vertical)

    int linhaNavio3 = 1;  // linha inicial do navio 3 (diagonal ↘)
    int colunaNavio3 = 1; // coluna inicial do navio 3 (diagonal ↘)

    int linhaNavio4 = 2;  // linha inicial do navio 4 (diagonal ↙)
    int colunaNavio4 = 8; // coluna inicial do navio 4 (diagonal ↙)

    // define todas as posições do tabuleiro como água (0)
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // posiciona o primeiro navio (horizontal)
    for (i = 0; i < 3; i++) {
        if (colunaNavio1 + i < 10) {
            tabuleiro[linhaNavio1][colunaNavio1 + i] = navio1[i];
        }
    }

    // posiciona o segundo navio (vertical)
    for (i = 0; i < 3; i++) {
        if (linhaNavio2 + i < 10) {
            if (tabuleiro[linhaNavio2 + i][colunaNavio2] == 0) {
                tabuleiro[linhaNavio2 + i][colunaNavio2] = navio2[i];
            }
        }
    }

    // posiciona o terceiro navio (diagonal principal ↘)
    for (i = 0; i < 3; i++) {
        if (linhaNavio3 + i < 10 && colunaNavio3 + i < 10) {
            if (tabuleiro[linhaNavio3 + i][colunaNavio3 + i] == 0) {
                tabuleiro[linhaNavio3 + i][colunaNavio3 + i] = navio3[i];
            }
        }
    }

    // posiciona o quarto navio (diagonal secundária ↙)
    for (i = 0; i < 3; i++) {
        if (linhaNavio4 + i < 10 && colunaNavio4 - i >= 0) {
            if (tabuleiro[linhaNavio4 + i][colunaNavio4 - i] == 0) {
                tabuleiro[linhaNavio4 + i][colunaNavio4 - i] = navio4[i];
            }
        }
    }

    // mostra o tabuleiro no console
    printf(" Tabuleiro:\n\n");
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]); // imprime cada célula com espaço
        }
        printf("\n"); // quebra de linha a cada linha da matriz
    }

    return 0;
}