#ifndef QTEXTEDITOR_H
#define QTEXTEDITOR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class QTextEditor; }
QT_END_NAMESPACE

class QTextEditor : public QMainWindow
{
    Q_OBJECT

public:
    QTextEditor(QWidget *parent = nullptr);
    ~QTextEditor();

private:
    Ui::QTextEditor *ui;
};
#endif // QTEXTEDITOR_H
