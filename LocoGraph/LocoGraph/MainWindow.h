#pragma once

#include "StageWidget.h"
#include "DockWidget.h"
#include "DisplayWidget.h"

#include <QtWidgets/QMainWindow>


class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow();
	~MainWindow();

private:
	StageWidget* m_pStageWidget;
	DockWidget* m_pDockWidget;
	DisplayWidget* m_pDisplayWidget;

	bool m_bInitialized = false;

protected:
	void showEvent(QShowEvent* event);
	void closeEvent(QCloseEvent* event);

signals:
	void sendShowEvent();

private slots:
	void receiveShowEvent();

};
