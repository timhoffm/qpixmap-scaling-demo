#include "renderwidget.h"
#include <QPainter>
#include <QPixmap>
#include <QColor>
#include <QFont>
#include <QDebug>

RenderWidget::RenderWidget(bool usePixmap, QWidget *parent) : QWidget(parent), m_usePixmap(usePixmap)
{

}

void RenderWidget::paintEvent(QPaintEvent *event)
{
	if (m_usePixmap) {
		QPixmap pm(width(), height());
		paint(&pm);
		QPainter(this).drawPixmap(0, 0, pm);
	} else {
		paint(this);
	}
}

void RenderWidget::paint(QPaintDevice *pd)
{
	QPainter p(pd);

	if (m_usePixmap) {
		QWidget *w = this;  // widget on which the pixmap should be drawn later on

		if (pd->logicalDpiY() != w->logicalDpiY()) {
			// workaround the scaling by adapting the font
			QFont f(p.font());
			f.setPointSizeF((f.pointSizeF() * w->logicalDpiY()) / pd->logicalDpiY());
			p.setFont(f);
		}
	}

	p.fillRect(0, 0, pd->width(), pd->height(), QColor(192, 192, 192));

	QFontMetrics fm = p.fontMetrics();
	int h = fm.height();
	for (int i=1; i<6; i++) {
		p.drawLine(0, i*h, width(), i*h);
	}
	p.drawText(4, fm.ascent(), m_usePixmap ? "using QPixmap draw" : "using direct draw");
	p.drawText(8, h+ fm.ascent(), QString("font pointsize: %1").arg(p.font().pointSize()));
	p.drawText(8, 2*h + fm.ascent(), QString("font height: %1").arg(h));
	p.drawText(8, 3*h + fm.ascent(), QString("physicalDpiY: %1").arg(pd->physicalDpiY()));
	p.drawText(8, 4*h + fm.ascent(), QString("logicalDpiY: %1").arg(pd->logicalDpiY()));
}
