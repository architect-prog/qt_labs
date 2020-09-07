#ifndef TASK1_H
#define TASK1_H

#include <QWidget>
#include <QPainter>

class Task1 : public QWidget
{
    Q_OBJECT
    void paintEvent(QPaintEvent *);
public:
    explicit Task1(QWidget *parent = nullptr);
};

#endif // TASK1_H
