#ifndef TASK2_H
#define TASK2_H

#include <QWidget>
#include <QPainter>
#include <QTimer>
class Task2 : public QWidget
{
    Q_OBJECT
    void CreateTimer();
    void DrawFir(QPainter &painter);
    void DrawWitchOfAgnesi(QPainter &painter);
    void UpdateFirPosition(qreal firScale);
    qreal WitchOfAgnesi(qreal x, qreal a = 4) { return (8*pow(a,3))/(pow(x,2) + 4*pow(a,2)); }
    QVector<QPointF> GetGraphPoints(int graphWidth, int graphHeight);
    void paintEvent(QPaintEvent *);

    enum Direction { left, right };
    Direction dir = Direction::right;
    int current = 0;
    QPolygonF topTriangle;
    QPolygonF botTriangle;
    QTimer *timer;
public:
    explicit Task2(QWidget *parent = nullptr);
private slots:
    void UpdateGraphic() { update(); }

};

#endif // TASK2_H
