#include "ConfigPage.h"

ConfigPage::ConfigPage(QWidget* parent) :
  QWizardPage(parent)
{
  ui.setupUi(this);

  setTitle("Configure the download");

  registerField("AWS_URL",        ui.leUrl);
  registerField("LOG_START",      ui.leLogStart);
  registerField("DOWNLOAD_START", ui.sbDownloadStart);
  registerField("DOWNLOAD_END",   ui.sbDownloadEnd);
  registerField("NUM_JOBS",       ui.sbNumJobs);

  ui.leUrl->setFocus();

  connect(ui.leUrl,           SIGNAL(textEdited(QString)),  SIGNAL(completeChanged()));
  connect(ui.leLogStart,      SIGNAL(textEdited(QString)),  SIGNAL(completeChanged()));
  connect(ui.sbDownloadStart, SIGNAL(valueChanged(int)),    SIGNAL(completeChanged()));
  connect(ui.sbDownloadEnd,   SIGNAL(valueChanged(int)),    SIGNAL(completeChanged()));
  connect(ui.sbNumJobs,       SIGNAL(valueChanged(int)),    SIGNAL(completeChanged()));

  connect(ui.leLogStart, SIGNAL(textEdited(QString)), SLOT(onLogDurationChanged()));
  connect(ui.leLogEnd,   SIGNAL(textEdited(QString)), SLOT(onLogDurationChanged()));
}

bool ConfigPage::isComplete() const
{
  return !ui.leUrl->text().isEmpty() &&
         !ui.leLogStart->text().isEmpty() &&
      ui.sbDownloadStart->value() < ui.sbDownloadEnd->value();
}

void ConfigPage::onLogDurationChanged()
{
  QString startText = ui.leLogStart->text();
  QString endText   = ui.leLogEnd  ->text();
  if (startText.isEmpty() || endText.isEmpty())
    return;
  qlonglong seconds = qRound64((endText.toLongLong() - startText.toLongLong()) / 1e9);
  ui.leDuration->setText(tr("%1 s (%2 min)").arg(seconds).arg(seconds / 60));
}
