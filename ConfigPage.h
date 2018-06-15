#pragma once

#include "ui_ConfigPage.h"
#include <QWizardPage>

class ConfigPage : public QWizardPage
{
  Q_OBJECT

public:
  explicit ConfigPage(QWidget* parent = nullptr);

  bool isComplete() const override;

private slots:
  void onLogDurationChanged();

private:
  Ui::ConfigPage ui;
};

