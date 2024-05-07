#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N = 8;
int count = 0;

/* Check if it’s safe to place a new Queen in the given position */
int isSafe(int board[N][N], int row, int col) {

    /*check up*/
    for (int i = 0; i < row; i++) {
        if(board[i][col]){  return 0;   }
    }
    
    /*check diagonal left up*/
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]){  return 0;   }
    }
    /*check diagonal right up*/
    for (int i = row, j = col; j < N && i >= 0; i--, j++){
        if (board[i][j]){  return 0;   }
    }
    return 1;

}

void printBoard(int board[N][N]){
    for (int y = 0; y < N; y++){
        for (int x = 0; x < N; x++){
            printf("%d", board[x][y]);
        }
        printf("\n");
    }
    printf("\n");
}

/*Try to place the N queens in the board and update the global variable ’count’ */
int solveNQueens(int board[N][N], int row) {
    if (row >= N) {
        printBoard(board);
        count++;
    }
    for (int i = 0; i < N; i++) {
        if (isSafe(board, row, i)){
            board[row][i] = 1;
            solveNQueens(board, row+1);
            /*if doesnt result in a solution*/
            board[row][i] = 0;
        }
    }
    return count;
    
}

int main() {
    int board[N][N];
    memset(board, 0, sizeof(board)); //initialize the board and fill with 0
    solveNQueens(board, 0);
    printf("total number of solutions: %d", count);
    return 0;
}