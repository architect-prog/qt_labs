#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <task1.h>
#include <task2.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_task2_clicked();
    void on_task1_clicked();
private:
    Ui::MainWindow *ui;
    Task1 *task1;
    Task2 *task2;
};
#endif // MAINWINDOW_H
