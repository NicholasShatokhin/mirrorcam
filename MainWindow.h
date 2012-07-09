#ifndef __MainWindow_h
#define __MainWindow_h

#include "ui_MainForm.h"

#include <QDeclarativeContext>
#include <QDeclarativeItem>

#include "details.h"
#include "settings.h"

class MainWindow: public QMainWindow
{
    Q_OBJECT
	
  private:
    Ui::MainWindow gui;

    bool fullscreen;

    Details * info;
    Settings * settings;

    void resizeVideoFrame(int dx, int dy, int width, int height);
	
  public:
	MainWindow();
    ~MainWindow();
    void resizeEvent(QResizeEvent *);
    void keyPressEvent(QKeyEvent *ke);
    void mouseMoveEvent(QMouseEvent *me);
    void mouseDoubleClickEvent(QMouseEvent *);

public slots:
    void toggleFullscreen();
    void disableFullscreen();
    void showSettings();
    void showInfo();
    void closeApp();
};

	

#endif
