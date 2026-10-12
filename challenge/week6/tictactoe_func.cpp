#include <iostream>
using namespace std;

const int NUM_CELL = 3;

bool isValidInput(char board[NUM_CELL][NUM_CELL], int x, int y) {
    if (x >= NUM_CELL || y >= NUM_CELL) {
        cout << x << ", " << y << ": x와 y 둘 중 하나가 칸을 벗어납니다." << endl;
        return false;
    }
    if (board[x][y] != '-') {
        cout << x << ", " << y << ": 이미 돌이 차있습니다." << endl;
        return false;
    }
    return true;
}

void printBoard(char board[NUM_CELL][NUM_CELL]) {
    for (int i = 0; i < NUM_CELL; i++) {
        cout << "| ";
        for (int j = 0; j < NUM_CELL; j++) {
            cout << board[i][j];
            if (j == NUM_CELL - 1) break;
            cout << " | ";
        }
        cout << " |" << endl;
    }
    cout << endl;
}

bool isBoardFull(char board[NUM_CELL][NUM_CELL]) {
    int checked = 0;
    for (int i = 0; i < NUM_CELL; i++)
        for (int j = 0; j < NUM_CELL; j++)
            if (board[i][j] == '-') checked++;
    return checked == 0;
}

bool checkWin(char board[NUM_CELL][NUM_CELL], char currentUser) {
    bool isWin = false;

    for (int i = 0; i < NUM_CELL; i++) {
        if (board[i][0] == currentUser && board[i][1] == currentUser && board[i][2] == currentUser) {
            cout << "가로에 모두 돌이 놓였습니다!: ";
            isWin = true;
        }
        if (board[0][i] == currentUser && board[1][i] == currentUser && board[2][i] == currentUser) {
            cout << "세로에 모두 돌이 놓였습니다!: ";
            isWin = true;
        }
    }

    if (board[0][0] == currentUser && board[1][1] == currentUser && board[2][2] == currentUser) {
        cout << "왼쪽 위에서 오른쪽 아래 대각선으로 모두 돌이 놓였습니다!: ";
        isWin = true;
    }
    if (board[0][2] == currentUser && board[1][1] == currentUser && board[2][0] == currentUser) {
        cout << "오른쪽 위에서 왼쪽 아래 대각선으로 모두 돌이 놓였습니다!: ";
        isWin = true;
    }

    return isWin;
}

int main() {
    char board[NUM_CELL][NUM_CELL]{};
    int x, y;

    for (int i = 0; i < NUM_CELL; i++)
        for (int j = 0; j < NUM_CELL; j++)
            board[i][j] = '-';

    int k = 0;
    char currentUser = 'X';

    while (true) {
        switch (k % 2) {
        case 0: cout << "첫번째 유저(X)의 차례입니다 -> "; currentUser = 'X'; break;
        case 1: cout << "두번째 유저(O)의 차례입니다 -> "; currentUser = 'O'; break;
        }

        cout << "(x, y) 좌표를 입력하세요: ";
        cin >> x >> y;

        if (!isValidInput(board, x, y)) continue;

        board[x][y] = currentUser;
        printBoard(board);

        if (isBoardFull(board)) {
            cout << "모든 칸이 다 찼습니다. 종료합니다" << endl;
            break;
        }

        if (checkWin(board, currentUser)) {
            cout << k % 2 + 1 << "번 유저(" << currentUser << ")의 승리입니다!" << endl;
            cout << "종료합니다" << endl;
            break;
        }

        k++;
    }

    return 0;
}
