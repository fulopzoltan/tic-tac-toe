#ifndef TICTACTOE_H
#define TICTACTOE_H
enum class status { WON, TIE, CONTINUE };
class TicTacToe {

public:
  char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
  void clearBoard();
  status checkBoard();

  TicTacToe();
};

#endif // TICTACTOE_H
