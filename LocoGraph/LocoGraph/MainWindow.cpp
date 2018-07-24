#include "MainWindow.h"

MainWindow::MainWindow()
{
	const int minw = 1280;
	const int minh = 720;

	// Setup Widgets
	m_pDisplayWidget = new DisplayWidget(this);
	m_pStageWidget = new StageWidget(m_pDisplayWidget);
	m_pDockWidget = new DockWidget(this, m_pStageWidget);

	// Display
	m_pDisplayWidget->setMinimumWidth(minw);
	m_pDisplayWidget->setMinimumHeight(minh);
	setCentralWidget(m_pDisplayWidget);

	// Docking
	m_pDockWidget->setWindowTitle("Setting");
	m_pDockWidget->setMinimumWidth(300);
	m_pDockWidget->setMaximumWidth(400);
	m_pDockWidget->setMinimumHeight(600);
	m_pDockWidget->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetFloatable);
	m_pDockWidget->setAllowedAreas(Qt::DockWidgetArea::LeftDockWidgetArea | Qt::DockWidgetArea::RightDockWidgetArea);
	addDockWidget(Qt::DockWidgetArea::LeftDockWidgetArea, m_pDockWidget);

	// StyleSheet
	QString dockStyleSheet = QString(
		"QDockWidget { border: 1px solid lightgray; titlebar-normal-icon: url(./img/undock.png); }"
		"QDockWidget { color: white; font-weight: bold; }"
		"QDockWidget::title { text-align: center; background-color: rgba( 210 , 71 , 38, 100% ); padding-left: 10px; }"
	);

	m_pDockWidget->setStyleSheet(dockStyleSheet);
	setStyleSheet("QMainWindow::separator { background-color: rgba(180, 180, 180, 100%); width: 1px; height: 1px; }");

	connect(this, SIGNAL(sendShowEvent()), this, SLOT(receiveShowEvent()), Qt::ConnectionType(Qt::QueuedConnection | Qt::UniqueConnection));
}

MainWindow::~MainWindow()
{
}

void MainWindow::showEvent(QShowEvent* event)
{
	QMainWindow::showEvent(event);
	emit sendShowEvent();
}

void MainWindow::closeEvent(QCloseEvent* event)
{
	m_pDisplayWidget->stopThread();
}

void MainWindow::receiveShowEvent()
{
	if( m_pStageWidget )
	{
		if( !m_bInitialized )
		{
			m_bInitialized = true;
		}
	}
}
