#include "renderarea.h"
#include <QPainter>

RenderArea::RenderArea(QWidget *parent) : QWidget(parent)
{

}

void RenderArea::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    QColor color1(255, 250, 250);

    painter.setBrush(color1);
    painter.drawRect(0, 0, width()-1, height()-1);

    QColor color2(224, 255, 255);

    painter.setBrush(color2);
    painter.drawRoundRect(15, 10, width()-30, height()-20);

    static const QPointF points[6] = {
            QPointF(30, 40),
            QPointF(50, 40),
            QPointF(70, 90),
            QPointF(100, 25),
            QPointF(120, 25),
            QPointF(70, 120),
            };

    QColor color3(178, 34, 34);
    painter.setBrush(color3);
    painter.drawPolygon(points, 6);
}
