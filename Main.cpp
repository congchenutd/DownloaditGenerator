#include "Wizard.h"
#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);

  Wizard wizard;
  wizard.show();
  wizard.resize(1000, 400);

  return app.exec();
}
