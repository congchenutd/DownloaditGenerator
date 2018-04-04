#include "Wizard.h"
#include "ConfigPage.h"
#include "ResultPage.h"

Wizard::Wizard(QWidget* parent)
  : QWizard(parent)
{
  addPage(new ConfigPage(this));
  addPage(new ResultPage(this));
  setWindowTitle("Downloadit Generator");
}
