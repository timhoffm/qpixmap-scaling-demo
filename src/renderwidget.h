#ifndef RENDERWIDGET_H
#define RENDERWIDGET_H

#include <QWidget>
#include <QPaintDevice>

class RenderWidget : public QWidget
{
	Q_OBJECT
public:
	explicit RenderWidget(bool usePixmap = false, QWidget *parent = 0);

protected:
	void paintEvent(QPaintEvent *event);
	void paint(QPaintDevice *pd);

signals:

public slots:

private:
	bool m_usePixmap;
};

#endif // RENDERWIDGET_H
