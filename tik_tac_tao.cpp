#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void printBoard(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; i++) {
        cout << "| ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " | ";
        }
        cout << endl << "---|---|---\n";
    }
}


bool checkWin(const vector<vector<char>>& board, char c) {

    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == c && board[i][1] == c && board[i][2] == c) ||
            (board[0][i] == c && board[1][i] == c && board[2][i] == c)) {
            return true;
        }
    }

    if ((board[0][0] == c && board[1][1] == c && board[2][2] == c) ||
        (board[0][2] == c && board[1][1] == c && board[2][0] == c)) {
        return true;
    }

    return false;
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, '-'));
    int move = 0;
    while (true) {
        printBoard(board);
        int row, col;
        if (move % 2 == 0) {
            cout << "Player 1's turn. Enter row and column (0-2): ";
            cin >> row >> col;
            board[row][col] = 'X';
            if (checkWin(board, 'X')) {
                cout << "Player 1 wins!" << endl;
                break;
            }
        } else {
            cout << "Player 2's turn. Enter row and column (0-2): ";
            cin >> row >> col;
            board[row][col] = 'O';
            if (checkWin(board, 'O')) {
                cout << "Player 2 wins!" << endl;
                break;
            }
        }
        if (move == 8) {
            cout << "It's a tie!" << endl;
            break;
        }
        move++;
    }
    return 0;
}
