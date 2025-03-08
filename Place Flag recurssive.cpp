#include <iostream>
using namespace std;

#define N 4

bool isSafe(int board[N][N], int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i][col]) {
            return false;
        }
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j]) {
            return false;
        }
    }

    return true;
}

void placeFlags(int board[N][N], int row, int &maxFlags) {
    if (row >= N) {
        int count = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j]) {
                    count++;
                }
            }
        }
        maxFlags = max(maxFlags, count);
        return;
    }

    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 1;
            placeFlags(board, row + 1, maxFlags);
            board[row][col] = 0;
        }
    }
}

int main() {
    int board[N][N] = {0};
    int maxFlags = 0;

    placeFlags(board, 0, maxFlags);

    cout << "Maximum number of flags that can be placed: " << maxFlags << endl;

    return 0;
}
