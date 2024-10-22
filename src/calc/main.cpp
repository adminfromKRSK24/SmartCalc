#include "View.h"
#include "Controller.h"
#include "ExampleModel.h"

int main(int argc, char *argv[]) {
  s21::Model m;
  s21::Controller controller(&m);

  QApplication a(argc, argv);
  MainWindow w(&controller);
  w.show();
  return a.exec();
}
