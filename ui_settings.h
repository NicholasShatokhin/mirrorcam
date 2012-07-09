/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created: Mon Jul 9 20:55:37 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFormLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Settings
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QWidget *widget;
    QFormLayout *formLayout;
    QLabel *label_2;
    QSpinBox *widthBox;
    QLabel *label_3;
    QSpinBox *heightBox;

    void setupUi(QDialog *Settings)
    {
        if (Settings->objectName().isEmpty())
            Settings->setObjectName(QString::fromUtf8("Settings"));
        Settings->resize(247, 233);
        buttonBox = new QDialogButtonBox(Settings);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(40, 190, 191, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(Settings);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 211, 21));
        widget = new QWidget(Settings);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 40, 221, 141));
        formLayout = new QFormLayout(widget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        widthBox = new QSpinBox(widget);
        widthBox->setObjectName(QString::fromUtf8("widthBox"));
        widthBox->setMinimum(100);
        widthBox->setMaximum(3000);
        widthBox->setValue(640);

        formLayout->setWidget(0, QFormLayout::FieldRole, widthBox);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        heightBox = new QSpinBox(widget);
        heightBox->setObjectName(QString::fromUtf8("heightBox"));
        heightBox->setMinimum(100);
        heightBox->setMaximum(2000);
        heightBox->setValue(480);

        formLayout->setWidget(1, QFormLayout::FieldRole, heightBox);


        retranslateUi(Settings);
        QObject::connect(buttonBox, SIGNAL(accepted()), Settings, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Settings, SLOT(reject()));

        QMetaObject::connectSlotsByName(Settings);
    } // setupUi

    void retranslateUi(QDialog *Settings)
    {
        Settings->setWindowTitle(QApplication::translate("Settings", "Settings", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Settings", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">Default window size:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Settings", "Width:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Settings", "Height:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Settings: public Ui_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
