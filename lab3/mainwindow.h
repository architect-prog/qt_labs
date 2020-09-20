#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QTime>
#include <QLabel>
#include "sorts.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

#define NUM_OF_ROWS 3
#define NUM_OF_COLS 10

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    typedef int(*sortPtr)(int*,int);
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_generateTable_clicked();

    void on_selectSort_currentIndexChanged(const QString &arg1);

    void on_tableWidget_cellClicked(int row, int column);

private:
    void fillWithRandomNums(int** arr, int rows, int cols);
    void fillTable(QTableWidget *table, int** arr, bool transposeArr = true);
    void initUi();

    sortPtr currentSort;
    QLabel** labels;
    QMap<QString, sortPtr> sortList;
    Ui::MainWindow *ui;
    int **array;
};
#endif // MAINWINDOW_H
