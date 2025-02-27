#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

// const para garantir que o array tenha um tamanho fixo
const int TAMANHO_TABULEIRO = 10;  // Tamanho do tabuleiro
const int TAMANHO_NAVIO = 3;       // Tamanho dos navios

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para posicionar o navio horizontalmente
int posicionarNavioHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        return 0; // Não cabe
    }
    for (int i = coluna; i < coluna + TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha][i] != 0) {
            return 0; // Há sobreposição
        }
    }
    for (int i = coluna; i < coluna + TAMANHO_NAVIO; i++) {
        tabuleiro[linha][i] = 3; // Marca a posição do navio
    }
    return 1;
}

// Função para posicionar o navio verticalmente
int posicionarNavioVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        return 0; // Não cabe
    }
    for (int i = linha; i < linha + TAMANHO_NAVIO; i++) {
        if (tabuleiro[i][coluna] != 0) {
            return 0; // Há sobreposição
        }
    }
    for (int i = linha; i < linha + TAMANHO_NAVIO; i++) {
        tabuleiro[i][coluna] = 3; // Marca a posição do navio
    }
    return 1;
}

int main() {

     // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.


    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Posiciona o navio horizontal
    int linhaHorizontal = 2, colunaHorizontal = 1;
    if (posicionarNavioHorizontal(tabuleiro, linhaHorizontal, colunaHorizontal)) {
        printf("Navio horizontal posicionado com sucesso!\n");
    } else {
        printf("Erro ao posicionar o navio horizontal.\n");
    }

    // Posiciona o navio vertical
    int linhaVertical = 5, colunaVertical = 3;
    if (posicionarNavioVertical(tabuleiro, linhaVertical, colunaVertical)) {
        printf("Navio vertical posicionado com sucesso!\n");
    } else {
        printf("Erro ao posicionar o navio vertical.\n");
    }

    // Exibe o tabuleiro
    printf("\nTabuleiro:\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}

int main() {
   

    // Inicializa o tabuleiro com água (0)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Posiciona o navio horizontal
    int linhaHorizontal = 2, colunaHorizontal = 1;
    if (posicionarNavioHorizontal(tabuleiro, linhaHorizontal, colunaHorizontal)) {
        printf("Navio horizontal posicionado com sucesso!\n");
    } else {
        printf("Erro ao posicionar o navio horizontal.\n");
    }

    // Posiciona o navio vertical
    int linhaVertical = 5, colunaVertical = 3;
    if (posicionarNavioVertical(tabuleiro, linhaVertical, colunaVertical)) {
        printf("Navio vertical posicionado com sucesso!\n");
    } else {
        printf("Erro ao posicionar o navio vertical.\n");
    }

    // Exibe o tabuleiro
    printf("\nTabuleiro:\n");
    exibirTabuleiro(tabuleiro);

    return 0;

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0


}











   