#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 8
#define AVOID '*'
#define PASS '.'

int check(char threat);
void solve(char board[][MAX + 1], char ch, int row, int col);

int main() {
    int i, j;
    char board[MAX][MAX + 1];

    for (i = 0; i < MAX; i++) {
        scanf("%s", board[i]);
    }

    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            solve(board, board[i][j], i, j);
        }
        putchar('\n');
    }
    
    return 0;
}

int check(char threat) {
    if (threat == AVOID)
        return 1;
    return 0;
}

void solve(char board[][MAX + 1], char ch, int row, int col) {
    int count = 0;
    switch (ch) {
        case AVOID: putchar(AVOID); break;
        case PASS:
            if (row - 1 >= 0 && col - 2 >= 0 && check(board[row - 1][col - 2]))
                count++;
            if (row - 2 >= 0 && col - 1 >= 0 && check(board[row - 2][col - 1]))
                count++;
            if (row - 2 >= 0 && col + 1 < 8 && check(board[row - 2][col + 1]))
                count++;
            if (row - 1 >= 0 && col + 2 < 8 && check(board[row - 1][col + 2]))
                count++;
            if (row + 1 < 8 && col + 2 < 8 && check(board[row + 1][col + 2]))
                count++;
            if (row + 2 < 8 && col + 1 < 8 && check(board[row + 2][col + 1]))
                count++;
            if (row + 2 < 8 && col - 1 >= 0 && check(board[row + 2][col - 1]))
                count++;
            if (row + 1 < 8 && col - 2 >= 0 && check(board[row + 1][col - 2]))
                count++;
            printf("%d", count);
            break;
        default: putchar('K');
    }
}