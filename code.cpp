#include <iostream>
#include <vector>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <string>
#include <sstream>

using namespace std;

const int SIZE = 3;
const char EMPTY = ' ';
const char PLAYER_X = 'X';
const char PLAYER_O = 'O';

void printBoard(const vector<vector<char>>& board) {
    cout << "\033[1;36m"; 
    cout << "  1 2 3\n";
    for (int i = 0; i < SIZE; ++i) {
        cout << i + 1 << " ";
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == PLAYER_X) {
                cout << "\033[1;31m" << board[i][j] << "\033[1;36m"; 
            } else if (board[i][j] == PLAYER_O) {
                cout << "\033[1;34m" << board[i][j] << "\033[1;36m"; 
            } else {
                cout << board[i][j];
            }
            if (j < SIZE - 1) cout << " ";
        }
        cout << endl;
    }
    cout << "\033[0m"; 
}

bool isBoardFull(const vector<vector<char>>& board) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == EMPTY) {
                return false;
            }
        }
    }
    return true;
}

bool isWinner(const vector<vector<char>>& board, char player) {
    for (int i = 0; i < SIZE; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;
    return false;
}

void getPlayerMove(vector<vector<char>>& board, char player) {
    int row, col;
    string input;
    while (true) {
        cout << "\033[1;33mPlayer " << player << ", enter your move (row and column): \033[0m";
        getline(cin, input);

        stringstream ss(input);
        string temp;
        vector<int> numbers;
        while (getline(ss, temp, ' ')) {
            if (temp.length() == 1 && isdigit(temp[0])) {
                numbers.push_back(temp[0] - '0');
            } else if (temp.length() == 2 && isdigit(temp[0]) && isdigit(temp[1])) {
                numbers.push_back(temp[0] - '0');
                numbers.push_back(temp[1] - '0');
            }
        }

        if (numbers.size() == 2) {
            row = numbers[0];
            col = numbers[1];
        } else if (numbers.size() == 1) {
            row = numbers[0] / 10;
            col = numbers[0] % 10;
        } else {
            row = 0;
            col = 0;
        }

        if (row >= 1 && row <= SIZE && col >= 1 && col <= SIZE && board[row - 1][col - 1] == EMPTY) {
            break;
        } else {
            cout << "\033[1;31mInvalid move. Try again.\033[0m" << endl; 
        }
    }
    board[row - 1][col - 1] = player;
}

void getAIMove(vector<vector<char>>& board, char player) {
    int row, col;
    srand(time(0));
    while (true) {
        row = rand() % SIZE;
        col = rand() % SIZE;
        if (board[row][col] == EMPTY) {
            board[row][col] = player;
            break;
        }
    }
}

void playGame(bool vsAI) {
    vector<vector<char>> board(SIZE, vector<char>(SIZE, EMPTY));
    char currentPlayer = PLAYER_X;
    while (true) {
        printBoard(board);
        if (currentPlayer == PLAYER_X || !vsAI) {
            getPlayerMove(board, currentPlayer);
        } else {
            getAIMove(board, currentPlayer);
        }
        if (isWinner(board, currentPlayer)) {
            printBoard(board);
            cout << "\033[1;32mPlayer " << currentPlayer << " wins!\033[0m" << endl; 
            return;
        }
        if (isBoardFull(board)) {
            printBoard(board);
            cout << "\033[1;35mThe game is a draw!\033[0m" << endl; 
            return;
        }
        currentPlayer = (currentPlayer == PLAYER_X) ? PLAYER_O : PLAYER_X;
    }
}

int main() {
    char mode;
    cout << "\033[1;36mWelcome to Tic-Tac-Toe!\033[0m" << endl;
    cout << "In this game, you need to get three of your marks in a row to win.\n";
    cout << "You can enter your move as two numbers separated by space or as a two-digit number.\n";
    cout << "For example, to mark the top left corner, you can enter '1 1' or '11'.\n";
    cout << "Select mode: (1) Two-player (2) Player vs AI: ";
    cin >> mode;
    cin.ignore(); 

    try {
        if (mode == '1') {
            playGame(false);
        } else if (mode == '2') {
            playGame(true);
        } else {
            throw invalid_argument("Invalid mode selected.");
        }
    } catch (const exception& e) {
        cerr << "\033[1;31m" << e.what() << "\033[0m" << endl; 
    }

    return 0;
}
