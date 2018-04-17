#pragma once

#include "ui_ResultPage.h"
#include <QWizardPage>

class ResultPage : public QWizardPage
{
  Q_OBJECT

public:
  explicit ResultPage(QWidget* parent = nullptr);

  void initializePage() override;

private slots:
  void generateCommand(bool dryRun);

private:
  Ui::ResultPage ui;
};
