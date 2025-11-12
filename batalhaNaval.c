#include <stdio.h>
#include <stdlib.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.


// inicializa tabuleiro 10x10
void inicializarTabuleiro(int tab[10][10]) {
    for (int r = 0; r < 10; r++)
        for (int c = 0; c < 10; c++)
            tab[r][c] = 0;
}

// posiciona 4 navios fixos de tamanho 3 (dois retos e dois diagonais)
void posicionarNavios(int tab[10][10]) {
    int i;

    // navio 1
    int ln1 = 2, cn1 = 1;
    for (i = 0; i < 3; i++) {
        int c = cn1 + i;
        if (ln1 >= 0 && ln1 < 10 && c >= 0 && c < 10)
            tab[ln1][c] = 3;
    }

    // navio 2
    int ln2 = 5, cn2 = 7;
    for (i = 0; i < 3; i++) {
        int r = ln2 + i;
        if (r >= 0 && r < 10 && cn2 >= 0 && cn2 < 10)
            tab[r][cn2] = 3;
    }

    // navio 3
    int ln3 = 0, cn3 = 0;
    for (i = 0; i < 3; i++) {
        int r = ln3 + i;
        int c = cn3 + i;
        if (r >= 0 && r < 10 && c >= 0 && c < 10)
            tab[r][c] = 3;
    }

    // navio 4
    int ln4 = 2, cn4 = 9;
    for (i = 0; i < 3; i++) {
        int r = ln4 + i;
        int c = cn4 - i;
        if (r >= 0 && r < 10 && c >= 0 && c < 10)
            tab[r][c] = 3;
    }
}

// cria dinamicamente a matriz 5x5 do "cone" (apex no topo, expande pra baixo)
// regra usada: em linha i (0..4) ativa colunas j em que abs(j-centro) <= i
void criarMatrizCone(int mat[5][5]) {
    int tamanho = 5;
    int centro = tamanho / 2; // 2
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            if (abs(j - centro) <= i) mat[i][j] = 1;
            else mat[i][j] = 0;
        }
    }
}

// Cria dinamicamente a matriz 5x5 da "cruz" (linha e coluna central = 1)
void criarMatrizCruz(int mat[5][5]) {
    int tamanho = 5;
    int centro = tamanho / 2; // 2
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            if (i == centro || j == centro) mat[i][j] = 1;
            else mat[i][j] = 0;
        }
    }
}

// cria dinamicamente a matriz 5x5 do "octaedro" visto frontal (losango/diamante)
// regra: abs(i-centro) + abs(j-centro) <= centro
void criarMatrizOctaedro(int mat[5][5]) {
    int tamanho = 5;
    int centro = tamanho / 2; // 2
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            if (abs(i - centro) + abs(j - centro) <= centro) mat[i][j] = 1;
            else mat[i][j] = 0;
        }
    }
}

// aplica (sobrepõe) a matriz de habilidade ao tabuleiro, centrando-a em (origemR, origemC).
// se a célula de habilidade == 1 e estiver dentro do tabuleiro, marca tab[r][c] = 5 (área afetada).
void aplicarHabilidade(int tab[10][10], int hab[5][5], int origemR, int origemC) {
    int tamanho = 5;
    int centro = tamanho / 2; // 2
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            if (hab[i][j] == 1) { // condicional que decide área afetada
                int r = origemR - centro + i;
                int c = origemC - centro + j;
                if (r >= 0 && r < 10 && c >= 0 && c < 10) { // verifica limites
                    tab[r][c] = 5; // marca como área afetada (sobrescreve navio se houver)
                }
            }
        }
    }
}

// exibe o tabuleiro
void exibirTabuleiro(int tabuleiro[10][10]) {
    printf(" Tabuleiro:\n\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[10][10];
    int cone[5][5], cruz[5][5], octaedro[5][5];

    // inicializa o tabuleiro
    inicializarTabuleiro(tabuleiro);

    // posiciona os navios
    posicionarNavios(tabuleiro);

    // cria as matrizes de habilidade
    criarMatrizCone(cone);
    criarMatrizCruz(cruz);
    criarMatrizOctaedro(octaedro);

    // Define pontos de origem (centro) no tabuleiro para cada habilidade
    int origConeR = 1, origConeC = 3;   // cone centrado em (1,3)
    int origCruzR = 6, origCruzC = 2;   // cruz centrada em (6,2)
    int origOctR  = 4, origOctC  = 7;   // octaedro centrado em (4,7)

    //  aplica habilidades (sobrepõe área marcada com 5)
    aplicarHabilidade(tabuleiro, cone, origConeR, origConeC);
    aplicarHabilidade(tabuleiro, cruz, origCruzR, origCruzC);
    aplicarHabilidade(tabuleiro, octaedro, origOctR, origOctC);

    // exibe tabuleiro final
    exibirTabuleiro(tabuleiro);

    return 0;
};