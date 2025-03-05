#include <stdio.h>
#include <stdlib.h>


// Definições globais
#define TAMANHO_TABULEIRO 10  // Tamanho do tabuleiro 10x10
#define TAMANHO_NAVIO 3       // Tamanho fixo dos navios

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("   ");
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("%d ", j); // Índices das colunas
    }
    printf("\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d  ", i); // Índices das linhas
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para verificar se todas as posições do navio estão livres
int verificarPosicoesLivres(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int navio[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        int linha = navio[i * 2];        // Linha da i-ésima parte do navio
        int coluna = navio[i * 2 + 1];   // Coluna da i-ésima parte do navio
        
        // Verifica se a posição está dentro do tabuleiro e se está livre
        if (linha < 0 || linha >= TAMANHO_TABULEIRO || coluna < 0 || coluna >= TAMANHO_TABULEIRO || tabuleiro[linha][coluna] != 0) {
            return 0; // Posição fora dos limites ou já ocupada
        }
    }
    return 1; // Todas as posições estão livres
}

// Função para posicionar um navio baseado em um array de coordenadas
int posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int navio[], int tamanho, int id) {
    // Verifica se todas as posições estão livres antes de posicionar
    if (!verificarPosicoesLivres(tabuleiro, navio, tamanho)) {
        printf("Falha: Posição já ocupada ou fora dos limites.\n");
        return 0; // Se alguma posição não estiver livre, falha no posicionamento
    }
    
    // Se passou em todas as verificações, marca as posições no tabuleiro
    for (int i = 0; i < tamanho; i++) {
        int linha = navio[i * 2];
        int coluna = navio[i * 2 + 1];
        tabuleiro[linha][coluna] = id; // Define como parte do navio
    }
    
    return 1; // Navio posicionado com sucesso
}

//////////////////////////////////////////////////////////
// Aplica a habilidade Cruz
void aplicarHabilidadeCruz(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int x, int y) {
    // Padrão da Cruz (5s no centro e nas linhas)
    int padrao[3][5] = {
        {0, 0, 5, 0, 0},  // Linha acima do centro
        {5, 5, 5, 5, 5},  // Linha do meio
        {0, 0, 5, 0, 0}   // Linha abaixo do centro
    };

    // Aplica o padrão da cruz no tabuleiro
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            int novoX = x + i - 1;  // Ajuste para centralizar a cruz no ponto (x, y)
            int novoY = y + j - 2;  // Ajuste para centralizar a cruz no ponto (x, y)

            // Verifica se a nova posição está dentro dos limites do tabuleiro
            if (novoX >= 0 && novoX < TAMANHO_TABULEIRO && novoY >= 0 && novoY < TAMANHO_TABULEIRO) {
                tabuleiro[novoX][novoY] = padrao[i][j];  // Aplica o valor do padrão
            }
        }
    }
}

// Aplica a habilidade Octaedro
void aplicarHabilidadeOctaedro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int x, int y) {
    int padrao[3][5] = {
        {0, 0, 5, 0, 0},
        {0, 5, 5, 5, 0},
        {0, 0, 5, 0, 0}
    };

    // Aplica o padrão do Octaedro no tabuleiro
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            int novoX = x + i - 1;  // Ajuste para centralizar o padrão no ponto (x, y)
            int novoY = y + j - 2;  // Ajuste para centralizar o padrão no ponto (x, y)

            // Verifica se a nova posição está dentro dos limites do tabuleiro
            if (novoX >= 0 && novoX < TAMANHO_TABULEIRO && novoY >= 0 && novoY < TAMANHO_TABULEIRO) {
                tabuleiro[novoX][novoY] = padrao[i][j];  // Aplica o valor do padrão
            }
        }
    }
}

void aplicarHabilidadeCone(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int x, int y) {
    int padrao[3][5] = {
        {0, 0, 5, 0, 0},  // Linha acima do centro
        {0, 5, 5, 5, 0},  // Linha do meio
        {5, 5, 5, 5, 5}   // Linha abaixo do centro
    };

    // Aplica o padrão do Cone no tabuleiro
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            int novoX = x + i - 1;  // Ajuste para centralizar o padrão no ponto (x, y)
            int novoY = y + j - 2;  // Ajuste para centralizar o padrão no ponto (x, y)

            // Verifica se a nova posição está dentro dos limites do tabuleiro
            if (novoX >= 0 && novoX < TAMANHO_TABULEIRO && novoY >= 0 && novoY < TAMANHO_TABULEIRO) {
                tabuleiro[novoX][novoY] = padrao[i][j];  // Aplica o valor do padrão
            }
        }
    }
}


////////////////////////////////////////////////////////////
int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0}; // Inicializa o tabuleiro com 0s

    // Define as coordenadas dos quatro navios conforme as posições fornecidas
    int navio_horizontal[] = {8, 1, 8, 2, 8, 3}; // ID 1
    int navio_vertical[] = {5, 3, 6, 3, 7, 3};   // ID 2
    int navio_diagonal_crescente[] = {0, 9, 1, 8, 2, 7}; // ID 3
    int navio_diagonal_decrescente[] = {7, 0, 6, 1, 5, 2}; // ID 4

    // Posiciona os navios no tabuleiro
    if (posicionarNavio(tabuleiro, navio_horizontal, TAMANHO_NAVIO, 3)) { // ID 1
        printf("Navio horizontal posicionado com sucesso!\n");
    } else {
        printf("Erro ao posicionar o navio horizontal.\n");
    }

    if (posicionarNavio(tabuleiro, navio_vertical, TAMANHO_NAVIO, 3)) {// ID 2
        printf("Navio vertical posicionado com sucesso!\n");
    } else {
        printf("Erro ao posicionar o navio vertical.\n");
    }

    if (posicionarNavio(tabuleiro, navio_diagonal_crescente, TAMANHO_NAVIO, 3)) { // ID 3
        printf("Navio diagonal crescente posicionado com sucesso!\n");
    } else {
        printf("Erro ao posicionar o navio diagonal crescente.\n");
    }

    if (posicionarNavio(tabuleiro, navio_diagonal_decrescente, TAMANHO_NAVIO, 3)) { // ID 4
        printf("Navio diagonal decrescente posicionado com sucesso!\n");
    } else {
        printf("Erro ao posicionar o navio diagonal decrescente.\n");
    }

    // Aplica as habilidades nas posições corretas
    aplicarHabilidadeCruz(tabuleiro, 8, 7);
    aplicarHabilidadeOctaedro(tabuleiro, 1, 2);
    aplicarHabilidadeCone(tabuleiro, 4, 7);

    // Exibe o tabuleiro atualizado
    printf("\nTabuleiro:\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}







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

    