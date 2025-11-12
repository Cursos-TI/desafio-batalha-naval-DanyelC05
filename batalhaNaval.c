#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    int tabuleiro[10][10];  // Matriz 10x10 que representa o mar (0 = água, 3 = navio)
    int i, j;

    // Vetores que representam os dois navios (cada um com 3 posições)
    int navio1[3] = {3, 3, 3}; // navio horizontal
    int navio2[3] = {3, 3, 3}; // navio vertical

    // coordenadas iniciais dos navios
    int linhaNavio1 = 2;  // linha inicial do navio 1 (horizontal)
    int colunaNavio1 = 4; // coluna inicial do navio 1 (horizontal)

    int linhaNavio2 = 5;  // linha inicial do navio 2 (vertical)
    int colunaNavio2 = 7; // coluna inicial do navio 2 (vertical)

    // define todas as posições do tabuleiro como água (0)
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // posiciona o primeiro navio no tabuleiro
    for (i = 0; i < 3; i++) {
        // Verifica se está dentro do limite do tabuleiro
        if (colunaNavio1 + i < 10) {
            tabuleiro[linhaNavio1][colunaNavio1 + i] = navio1[i];
        }
    }

    // posiciona o segundo navio no tabuleiro
    for (i = 0; i < 3; i++) {
        // verifica se está dentro do limite do tabuleiro
        if (linhaNavio2 + i < 10) {
            // evita sobreposição com o navio 1
            if (tabuleiro[linhaNavio2 + i][colunaNavio2] == 0) {
                tabuleiro[linhaNavio2 + i][colunaNavio2] = navio2[i];
            }
        }
    }

    // mostra o tabuleiro no console
    printf(" Tabuleiro: \n\n");
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]); // imprime cada célula com espaço
        }
        printf("\n"); // quebra de linha a cada linha da matriz
    }

    return 0;
}