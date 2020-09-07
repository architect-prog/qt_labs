#include "task2.h"

Task2::Task2(QWidget *parent) : QWidget(parent)
{
    topTriangle << QPointF(10,10) << QPointF(20,0) << QPointF(30,10);
    botTriangle << QPointF(10,20) << QPointF(20,10) << QPointF(30,20);
    CreateTimer();
}

void Task2::CreateTimer()
{
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(UpdateGraphic()));
    timer->start(10);
}

void Task2::UpdateFirPosition(qreal firScale)
{
   auto points = GetGraphPoints(width(), height());
   if(current + 1 == points.size())
   {
       dir = Direction::left;
   }
   else if(current - 1 == 0)
   {
       dir = Direction::right;
   }

   topTriangle[0] = QPointF(points[current].x()-width()*firScale, points[current].y());
   topTriangle[1] = QPointF(points[current].x(), points[current].y()-width()*firScale);
   topTriangle[2] = QPointF(points[current].x()+width()*firScale, points[current].y());

   botTriangle[0] = QPointF(points[current].x()-width()*firScale, points[current].y()+width()*firScale);
   botTriangle[1] = QPointF(points[current].x(), points[current].y());
   botTriangle[2] = QPointF(points[current].x()+width()*firScale, points[current].y()+width()*firScale);

   dir == Direction::right? current++: current--;
}

void Task2::DrawFir(QPainter &painter)
{
    painter.setPen(Qt::blue);
    painter.drawPolygon(topTriangle);
    painter.drawPolygon(botTriangle);
}

void Task2::DrawWitchOfAgnesi(QPainter &painter)
{
    painter.setPen(Qt::red);
    auto points = GetGraphPoints(width(), height());
    for (int i = 0; i < points.size()-1; i++)
    {
        painter.drawLine(points[i], points[i+1]);
    }
}

QVector<QPointF> Task2::GetGraphPoints(int graphWidth, int graphHeight)
{
    QVector<QPointF> result;
    qreal startX = -20;
    qreal GraphXRange = 40;
    qreal step = 0.1;

    for (qreal i = 0; i < GraphXRange; i+=step)
    {
        result.push_back(QPointF(i * graphWidth / GraphXRange, graphHeight/2 - WitchOfAgnesi(i + startX)*graphHeight / GraphXRange));
    }
    return result;
}

void Task2::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    DrawWitchOfAgnesi(painter);
    DrawFir(painter);
    UpdateFirPosition(0.03);
}
