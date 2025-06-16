#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // Constantes para o tamanho do tabuleiro e dos navios
    const int BOARD_SIZE = 10;  // Tabuleiro 10x10
    const int SHIP_SIZE = 3;    // Cada navio ocupa 3 posições

    // Matriz que representa o tabuleiro, iniciada com 0 (água)
    int board[BOARD_SIZE][BOARD_SIZE];
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 0;
        }
    }

    /* 
       Definição das coordenadas dos navios (definidas diretamente no código).
       Navio Horizontal: será posicionado na linha 2, coluna 3, ocupando as posições:
         board[2][3], board[2][4] e board[2][5]
       Navio Vertical: será posicionado na linha 6, coluna 5, ocupando as posições:
         board[6][5], board[7][5] e board[8][5]
    */
    int h_row = 2;   // Linha para o navio horizontal
    int h_col = 3;   // Coluna inicial para o navio horizontal

    int v_row = 6;   // Linha inicial para o navio vertical
    int v_col = 5;   // Coluna para o navio vertical

    // Validação para garantir que os navios se encaixam no tabuleiro
    if (h_col + SHIP_SIZE > BOARD_SIZE) {
        printf("Erro: O navio horizontal ultrapassa os limites do tabuleiro.\n");
        return 1;
    }
    if (v_row + SHIP_SIZE > BOARD_SIZE) {
        printf("Erro: O navio vertical ultrapassa os limites do tabuleiro.\n");
        return 1;
    }

    // Posicionamento do navio horizontal com validação simplificada de sobreposição
    for (int i = 0; i < SHIP_SIZE; i++) {
        if (board[h_row][h_col + i] != 0) {  // Se já estiver ocupado, há sobreposição
            printf("Erro: Sobreposição detectada para o navio horizontal.\n");
            return 1;
        }
        board[h_row][h_col + i] = 3;  // Marca a posição com 3 (parte do navio)
    }

    // Posicionamento do navio vertical com validação simplificada de sobreposição
    for (int i = 0; i < SHIP_SIZE; i++) {
        if (board[v_row + i][v_col] != 0) {  // Se já estiver ocupado, há sobreposição
            printf("Erro: Sobreposição detectada para o navio vertical.\n");
            return 1;
        }
        board[v_row + i][v_col] = 3;  // Marca a posição com 3
    }

    // Exibe o tabuleiro no console: 0 representa água e 3 representa parte de um navio
    printf("Tabuleiro de Batalha Naval:\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");  // Quebra de linha após cada linha do tabuleiro
    }

    return 0;
}
