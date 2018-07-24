#include "DisplayWidget.h"

#include <iostream>
#include <thread>
#include <random>

using namespace std;

#ifndef SAFE_DELETE
#define SAFE_DELETE(p) if(p != nullptr) { delete p; p = nullptr; }
#endif


DisplayWidget::DisplayWidget(QWidget* pParent)
{
	setLayout(&m_mainLayout);

	m_pScrollHorizontal = new QScrollBar(Qt::Horizontal, this);

	connect(m_pScrollHorizontal, &QScrollBar::valueChanged, [this](int value) { onHorizontalScrollBarChanged(value); });
	connect(m_plot.xAxis, SIGNAL(rangeChanged(QCPRange)), this, SLOT(onXRangeChanged(QCPRange)));

	connect(&m_plot, SIGNAL(mousePress(QMouseEvent*)), this, SLOT(onMousePressed()));
	connect(&m_plot, SIGNAL(mouseWheel(QWheelEvent*)), this, SLOT(onMouseWheeled()));

	m_mainLayout.addWidget(&m_plot);
	m_mainLayout.addWidget(m_pScrollHorizontal);

	initialize();

	connect(this, SIGNAL(signalThreadFinished()), this, SLOT(onThreadFinished()), Qt::ConnectionType(Qt::QueuedConnection | Qt::UniqueConnection));
	connect(this, SIGNAL(signalDrawGraph()), this, SLOT(onDrawGraph()), Qt::ConnectionType(Qt::QueuedConnection | Qt::UniqueConnection));
}

DisplayWidget::~DisplayWidget()
{

}

void DisplayWidget::onHorizontalScrollBarChanged(int value)
{
	// if user is dragging plot, we don't want to replot twice
	if( m_plot.xAxis->range().upper - value > 0 )
	{
		m_plot.xAxis->setRange(value, m_nGraphSteps, Qt::AlignCenter);
		m_plot.replot();
	}
}

void DisplayWidget::onThreadFunction()
{
	cout << "thread running." << endl;

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist_int(0, 250);
	std::uniform_real_distribution<> dist_real(0.0, 0.1);

	while( m_isThreadRunning )
	{
		m_dataSequence.push_back(m_dataSequence.size());
		m_dataMain.push_back(dist_int(gen));
		m_dataDataSub[0].push_back(dist_real(gen));
		m_dataDataSub[1].push_back(dist_real(gen));
		m_dataDataSub[2].push_back(dist_real(gen));
		m_dataDataSub[3].push_back(dist_real(gen));

		emit signalDrawGraph();

		Sleep(50);
	}

	m_isThreadRunning = true;
	emit signalThreadFinished();
}

bool DisplayWidget::onThreadStarted()
{
	cout << "thread started." << endl;

	return true;
}

void DisplayWidget::onThreadFinished()
{
	cout << "thread finished." << endl;
}

void DisplayWidget::onDrawGraph()
{
	m_plot.graph(0)->setData(QVector<qreal>::fromStdVector(m_dataSequence), QVector<qreal>::fromStdVector(m_dataMain), true);
	m_plot.graph(1)->setData(QVector<qreal>::fromStdVector(m_dataSequence), QVector<qreal>::fromStdVector(m_dataDataSub[0]), true);
	m_plot.graph(2)->setData(QVector<qreal>::fromStdVector(m_dataSequence), QVector<qreal>::fromStdVector(m_dataDataSub[1]), true);
	m_plot.graph(3)->setData(QVector<qreal>::fromStdVector(m_dataSequence), QVector<qreal>::fromStdVector(m_dataDataSub[2]), true);
	m_plot.graph(4)->setData(QVector<qreal>::fromStdVector(m_dataSequence), QVector<qreal>::fromStdVector(m_dataDataSub[3]), true);

	m_plot.xAxis->setRange(m_dataSequence.size(), m_nGraphSteps, Qt::AlignCenter);
	m_plot.replot();
}

void DisplayWidget::onXRangeChanged(QCPRange range)
{
	m_pScrollHorizontal->setValue(range.center());
	m_pScrollHorizontal->setPageStep(m_nGraphSteps);
}

void DisplayWidget::onMousePressed()
{
}

void DisplayWidget::onMouseWheeled()
{
}

bool DisplayWidget::isThreadRunning()
{
	return m_isThreadRunning;
}

void DisplayWidget::startThread()
{
	if( !m_isThreadRunning )
	{
		if( onThreadStarted() )
		{
			m_isThreadRunning = true;

			std::thread t(onThread, this);
			t.detach();
		}
	}
}

void DisplayWidget::stopThread()
{
	if( m_isThreadRunning )
	{
		m_isThreadRunning = false; // break while loop

		while( !m_isThreadRunning ) { Sleep(1000); }

		m_isThreadRunning = false;
	}
}

void DisplayWidget::initialize()
{
	m_plot.setInteractions(QCP::iRangeDrag);
	m_plot.setAutoAddPlottableToLegend(false);

	QCPAxisRect* pAxis2;
	QCPAxisRect* pAxis3;
	QCPAxisRect* pAxis4;
	QCPAxisRect* pAxis5;

	pAxis2 = new QCPAxisRect(&m_plot);
	pAxis3 = new QCPAxisRect(&m_plot);
	pAxis4 = new QCPAxisRect(&m_plot);
	pAxis5 = new QCPAxisRect(&m_plot);

	m_plot.plotLayout()->addElement(1, 0, pAxis2);
	m_plot.plotLayout()->addElement(2, 0, pAxis3);
	m_plot.plotLayout()->addElement(3, 0, pAxis4);
	m_plot.plotLayout()->addElement(4, 0, pAxis5);

	pAxis2->setMaximumSize(QWIDGETSIZE_MAX, 100);
	pAxis3->setMaximumSize(QWIDGETSIZE_MAX, 100);
	pAxis4->setMaximumSize(QWIDGETSIZE_MAX, 100);
	pAxis5->setMaximumSize(QWIDGETSIZE_MAX, 100);
	m_plot.plotLayout()->setRowSpacing(0);


	m_plot.xAxis->setTicks(false);
	pAxis2->axis(QCPAxis::atBottom)->setTicks(false);
	pAxis3->axis(QCPAxis::atBottom)->setTicks(true);
	pAxis4->axis(QCPAxis::atBottom)->setTicks(false);
	pAxis5->axis(QCPAxis::atBottom)->setTicks(false);

	connect(m_plot.xAxis, SIGNAL(rangeChanged(QCPRange)), pAxis2->axis(QCPAxis::atBottom), SLOT(setRange(QCPRange)));
	connect(m_plot.xAxis, SIGNAL(rangeChanged(QCPRange)), pAxis3->axis(QCPAxis::atBottom), SLOT(setRange(QCPRange)));
	connect(m_plot.xAxis, SIGNAL(rangeChanged(QCPRange)), pAxis4->axis(QCPAxis::atBottom), SLOT(setRange(QCPRange)));
	connect(m_plot.xAxis, SIGNAL(rangeChanged(QCPRange)), pAxis5->axis(QCPAxis::atBottom), SLOT(setRange(QCPRange)));
	connect(pAxis2->axis(QCPAxis::atBottom), SIGNAL(rangeChanged(QCPRange)), m_plot.xAxis, SLOT(setRange(QCPRange)));
	connect(pAxis3->axis(QCPAxis::atBottom), SIGNAL(rangeChanged(QCPRange)), m_plot.xAxis, SLOT(setRange(QCPRange)));
	connect(pAxis4->axis(QCPAxis::atBottom), SIGNAL(rangeChanged(QCPRange)), m_plot.xAxis, SLOT(setRange(QCPRange)));
	connect(pAxis5->axis(QCPAxis::atBottom), SIGNAL(rangeChanged(QCPRange)), m_plot.xAxis, SLOT(setRange(QCPRange)));

	m_plot.axisRect(0)->setRangeDrag(Qt::Horizontal);
	m_plot.axisRect(1)->setRangeDrag(Qt::Horizontal);
	m_plot.axisRect(2)->setRangeDrag(Qt::Horizontal);
	m_plot.axisRect(3)->setRangeDrag(Qt::Horizontal);
	m_plot.axisRect(4)->setRangeDrag(Qt::Horizontal);

	m_plot.xAxis->setRange(0, m_nGraphSteps);
	m_plot.yAxis->setRange(0, 250);
	pAxis2->axis(QCPAxis::atLeft)->setRange(0.0, 0.1);
	pAxis3->axis(QCPAxis::atLeft)->setRange(0.0, 0.1);
	pAxis4->axis(QCPAxis::atLeft)->setRange(0.0, 0.1);
	pAxis5->axis(QCPAxis::atLeft)->setRange(0.0, 0.1);


	m_plot.addGraph(m_plot.axisRect(0)->axis(QCPAxis::atBottom), m_plot.axisRect(0)->axis(QCPAxis::atLeft));
	m_plot.addGraph(m_plot.axisRect(1)->axis(QCPAxis::atBottom), m_plot.axisRect(1)->axis(QCPAxis::atLeft));
	m_plot.addGraph(m_plot.axisRect(2)->axis(QCPAxis::atBottom), m_plot.axisRect(2)->axis(QCPAxis::atLeft));
	m_plot.addGraph(m_plot.axisRect(3)->axis(QCPAxis::atBottom), m_plot.axisRect(3)->axis(QCPAxis::atLeft));
	m_plot.addGraph(m_plot.axisRect(4)->axis(QCPAxis::atBottom), m_plot.axisRect(4)->axis(QCPAxis::atLeft));
}

void DisplayWidget::clearGraphData()
{
	m_dataSequence.clear();
	m_dataMain.clear();
	m_dataDataSub[0].clear();
	m_dataDataSub[1].clear();
	m_dataDataSub[2].clear();
	m_dataDataSub[3].clear();

	emit signalDrawGraph();
}
