#pragma once

#include "ui_ConfigPage.h"
#include <QWizardPage>

class ConfigPage : public QWizardPage
{
public:
  explicit ConfigPage(QWidget* parent = nullptr);

  bool isComplete() const override;

private:
  Ui::ConfigPage ui;
};

