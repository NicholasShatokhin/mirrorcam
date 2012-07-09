#include "settings.h"
#include "ui_settings.h"

Settings::Settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);

    const int width = QApplication::desktop()->width();
    const int height = QApplication::desktop()->height();

    ui->widthBox->setMaximum(width);
    ui->heightBox->setMaximum(height);

    settings = new QSettings("robotex", "mirrorcam");
}

Settings::~Settings()
{
    delete ui;
    delete settings;
}

void Settings::saveSettings()
{
    settings->beginGroup("WindowSize");
    settings->setValue("width", ui->widthBox->value());
    settings->setValue("height", ui->heightBox->value());
    settings->endGroup();
    settings->sync();
}

void Settings::loadSettings()
{
    settings->beginGroup("WindowSize");
    ui->widthBox->setValue(settings->value("width", 640).toInt());
    ui->heightBox->setValue(settings->value("height", 480).toInt());
    settings->endGroup();
    settings->sync();
}

int Settings::getWidth()
{
    return ui->widthBox->value();
}

int Settings::getHeight()
{
    return ui->heightBox->value();
}

void Settings::setWidth(int value)
{
    ui->widthBox->setValue(value);
}

void Settings::setHeight(int value)
{
    ui->heightBox->setValue(value);
}
