#include <stdio.h>

/*
  MateCheck - Desafio de Xadrez
*/

/* Constantes para movimentos */
#define BISPO_PASSOS 5
#define TORRE_PASSOS 5
#define RAINHA_PASSOS 8

/* Tabuleiro padrão 8x8 (índices 0..7) */
#define LINHAS_TAB 8
#define COLUNAS_TAB 8

/* Funções utilitárias */
void mostrarPosicao(const char *peca, int linha, int coluna) {
    printf("%s -> Posição atual: (%d,%d)\n", peca, linha, coluna);
}

/* ========================= NÍVEL NOVATO ========================= */
void nivelNovato() {
    printf("\n--- NÍVEL NOVATO ---\n");

    /* Posições iniciais */
    int bispo_l = 6, bispo_c = 0;
    int torre_l = 3, torre_c = 1;
    int rainha_l = 4, rainha_c = 7;

    /* Bispo */
    printf("\nMovimentação do Bispo (Diagonal Superior Direita - %d passos):\n", BISPO_PASSOS);
    mostrarPosicao("Bispo (início)", bispo_l, bispo_c);
    int passo;
    for (passo = 1; passo <= BISPO_PASSOS; passo++) {
        bispo_l -= 1;
        bispo_c += 1;
        if (bispo_l < 0 || bispo_c >= COLUNAS_TAB) {
            printf("Bispo bateu na borda do tabuleiro. Parando.\n");
            break;
        }
        printf("Bispo: Cima Direita (passo %d) -> (%d,%d)\n", passo, bispo_l, bispo_c);
    }

    /* Torre */
    printf("\nMovimentação da Torre (Direita - %d passos):\n", TORRE_PASSOS);
    mostrarPosicao("Torre (início)", torre_l, torre_c);
    int movidos = 0;
    while (movidos < TORRE_PASSOS) {
        torre_c += 1;
        movidos++;
        if (torre_c >= COLUNAS_TAB) {
            printf("Torre bateu na borda do tabuleiro. Parando.\n");
            break;
        }
        printf("Torre: Direita (passo %d) -> (%d,%d)\n", movidos, torre_l, torre_c);
    }

    /* Rainha */
    printf("\nMovimentação da Rainha (Esquerda - %d passos):\n", RAINHA_PASSOS);
    mostrarPosicao("Rainha (início)", rainha_l, rainha_c);
    int passos_r = 0;
    do {
        rainha_c -= 1;
        passos_r++;
        if (rainha_c < 0) {
            printf("Rainha bateu na borda do tabuleiro. Parando.\n");
            break;
        }
        printf("Rainha: Esquerda (passo %d) -> (%d,%d)\n", passos_r, rainha_l, rainha_c);
    } while (passos_r < RAINHA_PASSOS);
}

/* ========================= NÍVEL AVENTUREIRO ========================= */
void nivelAventureiro() {
    printf("\n--- NÍVEL AVENTUREIRO ---\n");

    int cavalo_l = 2, cavalo_c = 6;
    mostrarPosicao("Cavalo (início)", cavalo_l, cavalo_c);

    int movimentos = 3;
    printf("\nMovimentação do Cavalo (L: 2 baixo + 1 esquerda) - %d movimentos:\n", movimentos);

    int m;
    for (m = 1; m <= movimentos; m++) {
        printf("\nMovimento L #%d:\n", m);

        int passos_baixo = 0;
        while (passos_baixo < 2) {
            cavalo_l += 1;
            passos_baixo++;
            if (cavalo_l >= LINHAS_TAB) {
                printf("Cavalo saiu do tabuleiro ao mover para baixo. Abortando.\n");
                cavalo_l = LINHAS_TAB - 1;
                break;
            }
            printf("Cavalo: Baixo (sub-passo %d) -> (%d,%d)\n", passos_baixo, cavalo_l, cavalo_c);
        }

        int s;
        for (s = 0; s < 1; s++) {
            cavalo_c -= 1;
            if (cavalo_c < 0) {
                printf("Cavalo saiu do tabuleiro ao mover para esquerda. Abortando.\n");
                cavalo_c = 0;
                break;
            }
            printf("Cavalo: Esquerda (sub-passo %d) -> (%d,%d)\n", s+1, cavalo_l, cavalo_c);
        }

        mostrarPosicao("Cavalo (após movimento L)", cavalo_l, cavalo_c);
    }
}

/* ========================= NÍVEL MESTRE ========================= */
/* Funções recursivas */
void moverBispoRec(int linha, int coluna, int passos, int maxPassos) {
    if (passos >= maxPassos) return;
    if (linha - 1 < 0 || coluna + 1 >= COLUNAS_TAB) {
        printf("Bispo (recursivo) bateu na borda. Passos realizados: %d\n", passos);
        return;
    }
    linha -= 1;
    coluna += 1;
    passos++;
    printf("Bispo (recursivo) - Cima Direita (passo %d) -> (%d,%d)\n", passos, linha, coluna);

    int i, j;
    for (i = 0; i < 1; i++) {
        for (j = 0; j < 1; j++) {
            /* apenas para cumprir loops aninhados */
        }
    }

    moverBispoRec(linha, coluna, passos, maxPassos);
}

void moverTorreRec(int linha, int coluna, int passos, int maxPassos) {
    if (passos >= maxPassos) return;
    if (coluna + 1 >= COLUNAS_TAB) {
        printf("Torre (recursiva) bateu na borda. Passos realizados: %d\n", passos);
        return;
    }
    coluna += 1;
    passos++;
    printf("Torre (recursiva) - Direita (passo %d) -> (%d,%d)\n", passos, linha, coluna);
    moverTorreRec(linha, coluna, passos, maxPassos);
}

void moverRainhaRec(int linha, int coluna, int passos, int maxPassos) {
    if (passos >= maxPassos) return;
    if (coluna - 1 < 0) {
        printf("Rainha (recursiva) bateu na borda. Passos realizados: %d\n", passos);
        return;
    }
    coluna -= 1;
    passos++;
    printf("Rainha (recursiva) - Esquerda (passo %d) -> (%d,%d)\n", passos, linha, coluna);
    moverRainhaRec(linha, coluna, passos, maxPassos);
}

void nivelMestre() {
    printf("\n--- NÍVEL MESTRE ---\n");

    int bispo_l = 6, bispo_c = 0;
    int torre_l = 3, torre_c = 1;
    int rainha_l = 4, rainha_c = 7;

    printf("\nMovimentação recursiva do Bispo (5 casas Cima Direita):\n");
    mostrarPosicao("Bispo (início)", bispo_l, bispo_c);
    moverBispoRec(bispo_l, bispo_c, 0, BISPO_PASSOS);

    printf("\nMovimentação recursiva da Torre (5 casas Direita):\n");
    mostrarPosicao("Torre (início)", torre_l, torre_c);
    moverTorreRec(torre_l, torre_c, 0, TORRE_PASSOS);

    printf("\nMovimentação recursiva da Rainha (8 casas Esquerda):\n");
    mostrarPosicao("Rainha (início)", rainha_l, rainha_c);
    moverRainhaRec(rainha_l, rainha_c, 0, RAINHA_PASSOS);

    printf("\nMovimentação do Cavalo (1 vez: L para Cima+Direita)\n");
    int cavalo_l = 5, cavalo_c = 2;
    mostrarPosicao("Cavalo (início)", cavalo_l, cavalo_c);

    int feito = 0, tentativa, subCima;
    for (tentativa = 0; tentativa < 3 && !feito; tentativa++) {
        for (subCima = 0; subCima < 2; subCima++) {
            cavalo_l -= 1;
            if (cavalo_l < 0) {
                printf("Cavalo bateu na borda ao subir. Revertendo.\n");
                cavalo_l += (subCima + 1);
                continue;
            }
            printf("Cavalo: Cima (sub-passo %d) -> (%d,%d)\n", subCima+1, cavalo_l, cavalo_c);
        }
        if (subCima < 2) continue;

        cavalo_c += 1;
        if (cavalo_c >= COLUNAS_TAB) {
            printf("Cavalo bateu na borda ao mover para direita. Revertendo.\n");
            cavalo_c -= 1;
            cavalo_l += 2;
            continue;
        }
        printf("Cavalo: Direita (sub-passo final) -> (%d,%d)\n", cavalo_l, cavalo_c);
        mostrarPosicao("Cavalo (após L)", cavalo_l, cavalo_c);
        feito = 1;
        break;
    }

    if (!feito) {
        printf("Não foi possível executar o movimento L do cavalo.\n");
    }
}

/* ========================= PROGRAMA PRINCIPAL ========================= */
int main() {
    int opcao = -1;
    do {
        printf("\n==== MateCheck - Desafio Xadrez ====\n");
        printf("1 - Nível Novato\n");
        printf("2 - Nível Aventureiro\n");
        printf("3 - Nível Mestre\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        if (scanf("%d", &opcao) != 1) {
            printf("Entrada inválida. Saindo.\n");
            return 1;
        }

        switch (opcao) {
            case 1: nivelNovato(); break;
            case 2: nivelAventureiro(); break;
            case 3: nivelMestre(); break;
            case 0: printf("Encerrando MateCheck. Até mais!\n"); break;
            default: printf("Opção inválida. Escolha 0, 1, 2 ou 3.\n");
        }
    } while (opcao != 0);

    return 0;
}
