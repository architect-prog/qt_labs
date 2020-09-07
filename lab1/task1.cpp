#include "task1.h"

Task1::Task1(QWidget *parent) : QWidget(parent)
{

}

void Task1::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setFont(QFont("Yu Gothic", 10, QFont::Bold));
    painter.rotate(- 90);
    painter.drawText(QRectF(-height()/1.5 - 100, width()/2, 400, 400),
                     Qt::AlignHCenter,
                     "Лабораторная работа № 8 \n"
                     "Графические примитивы\n"
                     " в библиотеке QT");
}
