#pragma once

#include "qcustomplot.h"

#include <QtWidgets/QWidget>
#include <QtWidgets/QGridLayout>

#include <vector>
#include <mutex>

class DisplayWidget : public QWidget
{
	Q_OBJECT

public:
	DisplayWidget(QWidget* pParent = NULL);
	~DisplayWidget();

protected:
	QGridLayout m_mainLayout;
	QCustomPlot m_plot;

	QScrollBar* m_pScrollHorizontal;

private:
	// thread
	bool m_isThreadRunning = false;

	static void onThread(void* arg)
	{
		DisplayWidget* pClass = reinterpret_cast<DisplayWidget*>(arg);
		pClass->onThreadFunction();
	}

	void onThreadFunction();

private:
	signals :
	void signalThreadFinished();
	void signalDrawGraph();

private slots:
	bool onThreadStarted();
	void onThreadFinished();
	void onDrawGraph();

	void onHorizontalScrollBarChanged(int value);
	void onXRangeChanged(QCPRange range);
	void onMousePressed();
	void onMouseWheeled();

public:
	bool isThreadRunning();
	void startThread();
	void stopThread();
	void initialize();

	void clearGraphData();

protected:
	std::mutex m_mutexGraphDrawing;
	int m_nGraphSteps = 1000;

	std::vector<double> m_dataSequence;
	std::vector<double> m_dataMain;
	std::vector<double> m_dataDataSub[4];
};
