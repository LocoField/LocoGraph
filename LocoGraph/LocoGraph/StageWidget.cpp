#include "StageWidget.h"
#include "MainWindow.h"


StageWidget::StageWidget(DisplayWidget* pDisplayWidget, QWidget* pParent)
	: m_pDisplayWidget(pDisplayWidget)
{
	initialize();
}

StageWidget::~StageWidget()
{

}

void StageWidget::initialize()
{
	setLayout(&m_mainLayout);

	m_listLog.setAutoScroll(true);
	m_listLog.setSortingEnabled(false);

	m_btnGraphClear.setText("Clear");
	m_btnGraphClear.setFixedHeight(50);
	connect(&m_btnGraphClear, &QPushButton::clicked, [this]() { slots_graph_clear(); });

	m_btnThreadStart.setText("Start");
	m_btnThreadStart.setFixedHeight(50);
	connect(&m_btnThreadStart, &QPushButton::clicked, [this]() { slots_thread_start(); });

	m_btnThreadStop.setText("Stop");
	m_btnThreadStop.setFixedHeight(50);
	connect(&m_btnThreadStop, &QPushButton::clicked, [this]() { slots_thread_stop(); });

	int row = 0;
	m_mainLayout.addWidget(&m_listLog, row, 0, 1, 1); row++;
	m_mainLayout.addWidget(&m_btnGraphClear, row, 0, 1, 1); row++;
	m_mainLayout.addWidget(&m_btnThreadStart, row, 0, 1, 1); row++;
	m_mainLayout.addWidget(&m_btnThreadStop, row, 0, 1, 1); row++;
}

void StageWidget::slots_thread_start()
{
	m_pDisplayWidget->startThread();
}

void StageWidget::slots_thread_stop()
{
	m_pDisplayWidget->stopThread();
}

void StageWidget::slots_graph_clear()
{
	m_pDisplayWidget->clearGraphData();
}
