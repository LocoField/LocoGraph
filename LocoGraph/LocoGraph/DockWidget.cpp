#include "DockWidget.h"


DockWidget::DockWidget(QWidget* pParent, QWidget* pChild)
	: QDockWidget(pParent)
{
	setWindowTitle(pChild->windowTitle());
	pChild->setParent(this);
	setWidget(pChild);
}

DockWidget::~DockWidget()
{
}
