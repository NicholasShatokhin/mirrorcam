/********************************************************************************
** Form generated from reading UI file 'MainForm.ui'
**
** Created: Mon Jul 9 20:55:37 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINFORM_H
#define UI_MAINFORM_H

#include <QtCore/QVariant>
#include <QtDeclarative/QDeclarativeView>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QWidget>
#include "CameraGLWidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    CameraGLWidget *glWidget;
    QDeclarativeView *menu;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(640, 540);
        MainWindow->setMouseTracking(true);
        MainWindow->setAutoFillBackground(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setMinimumSize(QSize(100, 100));
        centralWidget->setMaximumSize(QSize(16777215, 16777215));
        centralWidget->setMouseTracking(true);
        glWidget = new CameraGLWidget(centralWidget);
        glWidget->setObjectName(QString::fromUtf8("glWidget"));
        glWidget->setGeometry(QRect(0, 60, 640, 480));
        menu = new QDeclarativeView(centralWidget);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu->setGeometry(QRect(0, 0, 0, 60));
        menu->setMinimumSize(QSize(0, 60));
        menu->setResizeMode(QDeclarativeView::SizeViewToRootObject);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MirrorCam", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINFORM_H
