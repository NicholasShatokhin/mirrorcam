#include <QtGui>

#include "MainWindow.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	
    //UnityLauncherEntry* unity_launcher_entry_get_for_desktop_id ("extras-mirrorcam.desktop");

	MainWindow *mainWindow = new MainWindow();

	mainWindow->show();
	mainWindow->setMouseTracking(true);

	return app.exec();
}
