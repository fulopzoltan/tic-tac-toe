#include "tictactoe.h"

void TicTacToe::clearBoard() {
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      board[i][j] = ' ';
    }
  }
}

status TicTacToe::checkBoard() {
  // Checking for columns]
  for (int i = 0; i < 3; ++i) {
    if (board[0][i] != ' ' && board[1][i] == board[0][i] &&
        board[2][i] == board[0][i])
      return status::WON;
  }
  // Checking for rows
  for (int i = 0; i < 3; ++i) {
    if (board[i][0] != ' ' && board[i][1] == board[i][0] &&
        board[i][2] == board[i][0])
      return status::WON;
  }
  // Checking from left to right diagonal
  if (board[0][0] != ' ' && board[0][0] == board[1][1] &&
      board[1][1] == board[2][2]) {
    return status::WON;
  }
  // Checking from left to right diagonal
  if (board[0][2] != ' ' && board[0][2] == board[1][1] &&
      board[1][1] == board[2][0]) {
    return status::WON;
  }
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      if (board[i][j] == ' ')
        return status::CONTINUE;
    }
  }
  return status::TIE;
}

TicTacToe::TicTacToe() {}
