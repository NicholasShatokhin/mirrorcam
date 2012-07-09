/********************************************************************************
** Form generated from reading UI file 'details.ui'
**
** Created: Mon Jul 9 20:55:37 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DETAILS_H
#define UI_DETAILS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Details
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;

    void setupUi(QDialog *Details)
    {
        if (Details->objectName().isEmpty())
            Details->setObjectName(QString::fromUtf8("Details"));
        Details->resize(531, 405);
        buttonBox = new QDialogButtonBox(Details);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(170, 360, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);
        label = new QLabel(Details);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 256, 256));
        label->setPixmap(QPixmap(QString::fromUtf8(":/images/icon256.png")));
        label_2 = new QLabel(Details);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(220, 0, 261, 71));
        label_3 = new QLabel(Details);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(250, 100, 221, 17));
        label_4 = new QLabel(Details);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(250, 130, 211, 17));
        label_5 = new QLabel(Details);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(250, 160, 221, 17));
        label_6 = new QLabel(Details);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(250, 200, 221, 17));
        label_7 = new QLabel(Details);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(250, 230, 221, 17));
        label_8 = new QLabel(Details);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(220, 70, 101, 17));
        label_9 = new QLabel(Details);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 270, 501, 91));
        label_9->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_9->setWordWrap(true);

        retranslateUi(Details);
        QObject::connect(buttonBox, SIGNAL(accepted()), Details, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Details, SLOT(reject()));

        QMetaObject::connectSlotsByName(Details);
    } // setupUi

    void retranslateUi(QDialog *Details)
    {
        Details->setWindowTitle(QApplication::translate("Details", "About", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        label_2->setText(QApplication::translate("Details", "<html><head/><body><p><span style=\" font-size:36pt; font-weight:600;\">Mirror Cam</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Details", "<html><head/><body><p>Created by <span style=\" font-weight:600;\">Nicholas Shatokhin</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Details", "<html><head/><body><p><a href=\"mailto:n.shatokhin@gmail.com\"><span style=\" text-decoration: underline; color:#0000ff;\">n.shatokhin@gmail.com</span></a></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Details", "<html><head/><body><p><a href=\"https://launchpad.net/~robotex\"><span style=\" text-decoration: underline; color:#0000ff;\">https://launchpad.net/~robotex</span></a></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Details", "<html><head/><body><p>Design by <span style=\" font-weight:600;\">Anna Pulina</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("Details", "<html><head/><body><p><a href=\"mailto:suzygoodmorning@gmail.com\"><span style=\" text-decoration: underline; color:#0000ff;\">suzygoodmorning@gmail.com</span></a></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("Details", "<html><head/><body><p>Version: <span style=\" font-weight:600;\">1.0</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("Details", "<html><head/><body><p>To get fullscreen mode use <span style=\" font-weight:600;\">mouse double-click</span> on window or button from menu.</p><p>To get windowed mode use <span style=\" font-weight:600;\">mouse double-click</span> on window again or press <span style=\" font-weight:600;\">Escape</span> button.</p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Details: public Ui_Details {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DETAILS_H
