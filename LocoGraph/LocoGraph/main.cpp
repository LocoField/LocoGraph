#include "MainWindow.h"

#include <QtWidgets/QtWidgets>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	app.setStyle("fusion");

	MainWindow meditMainWindow;
	meditMainWindow.showMaximized();

	return app.exec();
}
