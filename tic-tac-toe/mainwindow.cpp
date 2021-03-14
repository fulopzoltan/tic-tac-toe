#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  this->setWindowTitle("Tic-Tac-Toe");
  info = ui->playerMove;
  info->setReadOnly(true);
  buttons[0] = ui->pushButton_1_1;
  buttons[1] = ui->pushButton_1_2;
  buttons[2] = ui->pushButton_1_3;
  buttons[3] = ui->pushButton_2_1;
  buttons[4] = ui->pushButton_2_2;
  buttons[5] = ui->pushButton_2_3;
  buttons[6] = ui->pushButton_3_1;
  buttons[7] = ui->pushButton_3_2;
  buttons[8] = ui->pushButton_3_3;
  updateGame();

  for (int i = 0; i < 9; ++i) {
    connect(buttons[i], &QPushButton::clicked, this,
            &MainWindow::playerClicked);
  }
  connect(ui->actionRestart, &QAction::triggered, this,
          &MainWindow::restartGame);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::updateGame() {
  info->setText(QString(moveMap[move]) + " moves");
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      QPushButton *currButton = buttons[i * 3 + j];
      currButton->setText(QString(ticTacToe.board[i][j]));
      switch (ticTacToe.board[i][j]) {
      case 'X': {
        currButton->setDisabled(true);
        currButton->setStyleSheet(
            "border:none; background-color:#133b5c;color:#e94560;");
        break;
      }
      case 'O': {
        currButton->setDisabled(true);
        currButton->setStyleSheet(
            "border:none; background-color:#133b5c;color:#fcdab7;");
        break;
      }
      case ' ': {
        currButton->setDisabled(false);
        break;
      }
      }
    }
  }
}

void MainWindow::playerClicked() {
  // GET WHICH BUTTON WAS CLICKED THEN UPDATE THE BOARD
  int i = sender()->objectName().split('_')[1].toInt();
  int j = sender()->objectName().split('_')[2].toInt();
  ticTacToe.board[i - 1][j - 1] = moveMap[move];
  move = move == 1 ? 2 : 1;
  info->setText(QString(moveMap[move]) + " moves");
  updateGame();
  switch (ticTacToe.checkBoard()) {
  case status::WON: {
    setButtonStatus(true);
    QMessageBox::about(this, "GAME FINISHED",
                       "Game finished " + QString(moveMap[move == 1 ? 2 : 1]) +
                           " WON");
    break;
  }
  case status::TIE: {
    setButtonStatus(true);
    QMessageBox::about(this, "GAME FINISHED", "Game finished as a TIE");
    break;
  }
  case status::CONTINUE:
    break;
  }
}

void MainWindow::restartGame() {
  setButtonStatus(false);
  move = 1;
  ticTacToe.clearBoard();
  updateGame();
}

void MainWindow::setButtonStatus(bool stat) {
  for (int i = 0; i < 9; ++i) {
    buttons[i]->setDisabled(stat);
  }
}
