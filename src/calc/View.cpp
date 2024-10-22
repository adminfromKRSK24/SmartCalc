#include "View.h"
#include "ExampleModel.h"

#define S21_INF 1.0 / 0.0
#define S21_NAN 0.0 / 0.0

MainWindow::MainWindow(s21::Controller *c, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), controller(c) {
  ui->setupUi(this);

  // Устанавливаем валидатор для ввода целых чисел любой длины
  QRegularExpression regExp("[0-9.()\\-+%^/*]*"); // Регулярное выражение, разрешающее вводить только цифры
  ui->result_show->setValidator(new QRegularExpressionValidator(regExp, ui->result_show));

  connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_sum, SIGNAL(clicked()), this, SLOT(sum_clicked()));
  connect(ui->pushButton_cos, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_sin, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_tan, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_acos, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_asin, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_atan, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_sqrt, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_ln, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_log, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_X, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_left_bracket, SIGNAL(clicked()), this,
          SLOT(digits_numbers()));
  connect(ui->pushButton_right_bracket, SIGNAL(clicked()), this,
          SLOT(digits_numbers()));
  connect(ui->pushButton_zoom_left, SIGNAL(clicked()), this,
          SLOT(zoom_clicked()));
  connect(ui->pushButton_zoom_right, SIGNAL(clicked()), this,
          SLOT(zoom_clicked()));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::digits_numbers() {
  QPushButton *button = (QPushButton *)sender();
  QString std_string;
  std_string = (ui->result_show->text() + button->text());
  ui->result_show->setText(std_string);
}

std::string getValueXandInputStr(QString inputQ, QString Xq) {
    std::string input = inputQ.toStdString();

    std::string X = Xq.toStdString();

    std::string old_str{"X"};  // какую подстроку заменить
    std::string new_str{X};  // на какую строку заменить
    size_t start {input.find(old_str)};            // находим позицию подстроки
    while (start != std::string::npos) // находим и заменяем все вхождения строки old_str
    {
        input.replace(start, old_str.length(), new_str); // Замена old_str на new_str
        start = input.find(old_str, start + new_str.length());
    }

    return input;
}

void MainWindow::sum_clicked() {

    std::string str = getValueXandInputStr(ui->result_show->text(), ui->result_x->text());


    controller->setinputDataTypeStringFromView(str);
    controller->setresultTypeStringFromCalculate();
    std::string res = controller->getresultTypeStringFromCalculate();

    QString sum = QString::fromStdString(res);

    ui->result_show->setText(sum);

}

void MainWindow::zoom_clicked() {
  QPushButton *button = (QPushButton *)sender();
  QString std_string;
  std_string = button->text();
  if (std_string == "-") {
    ui->widget->xAxis->setRange(xBegin--, xEnd++);
    ui->widget->yAxis->setRange(yBegin--, yEnd++);
  } else if (std_string == "+") {
    ui->widget->xAxis->setRange(xBegin++, xEnd--);
    ui->widget->yAxis->setRange(yBegin++, yEnd--);
  } else {
    zoom_left = 0;
    zoom_right = 0;
  }
  ui->widget->addGraph();
  ui->widget->graph()->addData(x, y);
  ui->widget->replot();
}

void MainWindow::on_pushButton_AC_clicked() {
  ui->result_show->setText(""); // рабочая схема для
  y.clear();
  x.clear();
  ui->widget->clearGraphs();
  ui->widget->replot();
}

void MainWindow::on_pushButton_plus_clicked() {
  QPushButton *button = (QPushButton *)sender();
  ui->result_show->setText(ui->result_show->text() + button->text());
}

void MainWindow::on_pushButton_minus_clicked() {
  QPushButton *button = (QPushButton *)sender();
  ui->result_show->setText(ui->result_show->text() + button->text());
}

void MainWindow::on_pushButton_ymnog_clicked() {
  QPushButton *button = (QPushButton *)sender();
  ui->result_show->setText(ui->result_show->text() + button->text());
}

void MainWindow::on_pushButton_del_clicked() {
  ui->result_show->setText(ui->result_show->text() + "/");
}

void MainWindow::on_pushButton_tochka_clicked() {
  QPushButton *button = (QPushButton *)sender();
  ui->result_show->setText(ui->result_show->text() + button->text());
}

void MainWindow::on_pushButton_backspace_clicked() {
  ui->result_show->setText(
      ui->result_show->text().remove(ui->result_show->text().size() - 1, 1));
}

void MainWindow::on_pushButton_mod_clicked() {
  ui->result_show->setText(ui->result_show->text() + "%");
}

void MainWindow::on_pushButton_exp_clicked() {
    ui->result_show->setText(ui->result_show->text() + "^");
}

void MainWindow::on_pushHistory_clicked() {




}

void MainWindow::on_pushButton_grafic_2_clicked() {
  ui->widget->clearGraphs();
  y.clear();
  x.clear();
  h = 0.1; // шаг

  qDebug() << "hello";
  if (ui->result_x1->text() == "" || ui->result_x2->text() == "" ||
      ui->result_y1->text() == "" || ui->result_y2->text() == "") {
    xBegin = -4; // область значения
    xEnd = 4;    // область значения
    yBegin = -4;
    yEnd = 4;
  }
  else {
    xBegin = ui->result_x1->text().toDouble(); // область значения
    xEnd = ui->result_x2->text().toDouble() + h; // область значения
    yBegin = ui->result_y1->text().toDouble();
    yEnd = ui->result_y2->text().toDouble();
  }

  ui->widget->xAxis->setRange(xBegin, xEnd);
  ui->widget->yAxis->setRange(yBegin, yEnd);

    for (X = xBegin; X <= xEnd; X += h) {

      double sumD = 0;
      QString Xstr = QString::number(X);
      std::string str = getValueXandInputStr(ui->result_show->text(), Xstr);


      controller->setinputDataTypeStringFromView(str);
      controller->setresultTypeStringFromCalculate();
      std::string res = controller->getresultTypeStringFromCalculate();

      QString sum = QString::fromStdString(res);

      sumD = sum.toDouble();

////      if (error == 0) {
////        if (err == 0) {
          x.push_back(X);
          y.push_back(sumD);
//        } else {
//          y.clear();
//          x.clear();
//        }
        ui->widget->addGraph();
        ui->widget->graph()->addData(x, y);
        ui->widget->replot();
  }
}

