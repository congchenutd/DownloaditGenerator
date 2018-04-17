#include "ResultPage.h"
#include <QClipboard>

ResultPage::ResultPage(QWidget* parent) :
  QWizardPage(parent)
{
  ui.setupUi(this);

  setTitle("Result");

  ui.txCommand->setFocus();

  connect(ui.cbDryRun, SIGNAL(clicked(bool)), SLOT(generateCommand(bool)));
}

void ResultPage::initializePage()
{
  generateCommand(ui.cbDryRun->isChecked());
}

void ResultPage::generateCommand(bool dryRun)
{
  const QString url         = field("AWS_URL")        .toString();
  const qulonglong logStart = field("LOG_START")      .toULongLong();
  const int downloadStart   = field("DOWNLOAD_START") .toInt();
  const int downloadEnd     = field("DOWNLOAD_END")   .toInt();
  const int numJobs         = field("NUM_JOBS")       .toInt();

  const qulonglong startTime  = logStart + downloadStart * 1e9;
  const qulonglong endTime    = logStart + downloadEnd * 1e9;

  QString text = tr("downloadit.py --prefix %1 --start %2 --end %3").arg(url).arg(startTime).arg(endTime);
  text += dryRun ? " --dry-run" : " --job " + QString::number(numJobs);
  ui.txCommand->setPlainText(text);

  qApp->clipboard()->setText(ui.txCommand->toPlainText());
}
