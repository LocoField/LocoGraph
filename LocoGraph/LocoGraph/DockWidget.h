#pragma once

#include <QtWidgets/QDockWidget>


class DockWidget : public QDockWidget
{
public:
	DockWidget(QWidget* pParent, QWidget* pChild);
	~DockWidget();
};
