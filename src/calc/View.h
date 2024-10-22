#ifndef VIEW_H
#define VIEW_H

#include <QApplication>
#include <QDoubleValidator>
#include <QMainWindow>
#include <QPainter>
#include <QPushButton>
#include <QTimer>
#include <QVector>
#include <QWidget>
#include <QtMath>
#include <iostream>
#include <limits>
#include "ui_mainwindow.h"
#include <QRegularExpressionValidator>
#include <QValidator>
#include <QVBoxLayout>
#include "Controller.h"
#include <stack>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit MainWindow(s21::Controller *controller ,QWidget *parent = nullptr);
  ~MainWindow();

private:
  Ui::MainWindow *ui;
  s21::Controller *controller;


  double xBegin, xEnd, yBegin, yEnd, h, X;
  int zoom_left, zoom_right;
  int error_skobka;
  int error;
  int N;
  int credit_flag;

  QVector<double> x, y;



private slots:
  void digits_numbers();
  void on_pushHistory_clicked();
  void on_pushButton_AC_clicked();
  void on_pushButton_plus_clicked();
  void on_pushButton_minus_clicked();
  void on_pushButton_ymnog_clicked();
  void on_pushButton_del_clicked();
  void on_pushButton_tochka_clicked();
  void on_pushButton_exp_clicked();
  void sum_clicked();
  void on_pushButton_backspace_clicked();
  void on_pushButton_mod_clicked();
  void on_pushButton_grafic_2_clicked();
  void zoom_clicked();
};

std::string getValueXandInputStr(QString input, QString X);

#endif // VIEW_H
