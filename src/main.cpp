#include <QtGui>

#include "MainWindow.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	
	MainWindow *mainWindow = new MainWindow();

	mainWindow->show();
    mainWindow->setMouseTracking(true);

	return app.exec();
}
