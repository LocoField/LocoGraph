#pragma once

#include "DisplayWidget.h"

#include <QtWidgets/QGridLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>


class StageWidget : public QWidget
{
	Q_OBJECT

public:
	StageWidget(DisplayWidget* pDisplayWidget, QWidget* pParent = NULL);
	~StageWidget();

private:
	DisplayWidget* m_pDisplayWidget;

protected:
	QGridLayout m_mainLayout;

	QListWidget m_listLog;
	QPushButton m_btnGraphClear;
	QPushButton m_btnThreadStart;
	QPushButton m_btnThreadStop;

private:
	void initialize();

protected:
	void slots_thread_start();
	void slots_thread_stop();

	void slots_graph_clear();
};
