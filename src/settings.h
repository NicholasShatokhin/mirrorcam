#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include <QSettings>
#include <QDesktopWidget>

namespace Ui {
class Settings;
}

class Settings : public QDialog
{
    Q_OBJECT
    
public:
    explicit Settings(QWidget *parent = 0);
    ~Settings();

    void saveSettings();
    void loadSettings();

    int getWidth();
    int getHeight();
    void setWidth(int value);
    void setHeight(int value);
    
private:
    Ui::Settings *ui;

    QSettings * settings;
};

#endif // SETTINGS_H
