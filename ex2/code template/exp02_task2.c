#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N = 8;
int count = 0;

void printBoard(int board[N][N]) {
    printf("Solution %d:\n", count);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c ", board[i][j] ? 'Q' : '.');
        }
        printf("\n");
    }
    printf("\n");
}

/**
 * Check if it's safe to place a new Queen in the given position
*/
int isSafe(int board[N][N], int row, int col) {
    int i, j;

    // Check this row on left side
    for (i = 0; i < col; i++)
        if (board[row][i])
            return 0;

    // Check upper diagonal on left side
    for (i=row, j=col; i>=0 && j>=0; i--, j--)
        if (board[i][j])
            return 0;

    // Check lower diagonal on left side
    for (i=row, j=col; j>=0 && i<N; i++, j--)
        if (board[i][j])
            return 0;

    return 1;
}

/**
 * Try to place N queens in the board 
 * and update the global variable 'count'
*/
void solveNQueens(int board[N][N], int col) {
    // base case: If all queens are placed
    if (col >= N) {
        printBoard(board);
        count++;
        return;
    }

    // Consider this column and try placing this queen in all rows one by one
    for (int i = 0; i < N; i++) {
        // Check if the queen can be placed on board[i][col]
        if (isSafe(board, i, col)) {
            // Place this queen in board[i][col]
            board[i][col] = 1;

            // recur to place rest of the queens
            solveNQueens(board, col + 1);

            // If placing queen in board[i][col] doesn't lead to a solution, then remove queen from board[i][col]
            board[i][col] = 0; // BACKTRACK
        }
    }
}
int main() {
    int board[N][N];
    memset(board, 0, sizeof(board));

    // try to place the queen row by row
    solveNQueens(board, 0);
    
    printf("Total solutions: %d\n", count);

    return 0;
}