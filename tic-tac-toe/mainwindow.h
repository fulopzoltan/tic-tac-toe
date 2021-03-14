#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLineEdit>
#include <QMainWindow>
#include <QMessageBox>
#include <QPushButton>
#include <map>
#include <tictactoe.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private:
  Ui::MainWindow *ui;
  QPushButton *buttons[9];
  QLineEdit *info;
  TicTacToe ticTacToe;
  void updateGame();
  std::map<int, char> moveMap = {{1, 'X'}, {2, 'O'}};
  int move = 1; // 1 = 'X' 2='O',
public slots:
  void playerClicked();
  void restartGame();
  void setButtonStatus(bool stat);
};
#endif // MAINWINDOW_H
