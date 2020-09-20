#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QTime midnight(0,0,0);
    qsrand(midnight.secsTo(QTime::currentTime()));

    initUi();

    array = new int*[NUM_OF_ROWS];
    for (int i = 0; i < NUM_OF_ROWS; i++)
    {
        array[i] = new int[NUM_OF_COLS]{0};
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::fillTable(QTableWidget *table, int** arr, bool transposeArr)
{
    for (int i = 0; i < table->rowCount(); i++)
    {
        for (int j = 0; j < table->columnCount(); j++)
        {
            if(transposeArr)
                table->setItem(i, j, new QTableWidgetItem(QString::number(arr[j][i])));
            else
                table->setItem(i, j, new QTableWidgetItem(QString::number(arr[i][j])));
        }
    }
}

void MainWindow::fillWithRandomNums(int** arr, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr[i][j] = qrand() % 100;
        }
    }
}

void MainWindow::initUi()
{
    ui->tableWidget->setRowCount(NUM_OF_COLS);
    ui->tableWidget->setColumnCount(NUM_OF_ROWS);

    sortList.insert("Сортировка\nпузырьковая", Sorts::bubbleSort);
    sortList.insert("Сортировка\nвставками",  Sorts::insertionSort);

    for (auto key : sortList.keys())
    {
        ui->selectSort->addItem(key);
    }

    labels = new QLabel*[NUM_OF_COLS];
    labels[0] = ui->numOfComparisons1;
    labels[1] = ui->numOfComparisons2;
    labels[2] = ui->numOfComparisons3;
}

void MainWindow::on_generateTable_clicked()
{
    fillWithRandomNums(array, NUM_OF_ROWS, NUM_OF_COLS);
    fillTable(ui->tableWidget, array);

    for (int i = 0; i < NUM_OF_ROWS; ++i)
    {
        labels[i]->setText("0");
    }
}

void MainWindow::on_selectSort_currentIndexChanged(const QString &arg1)
{
    currentSort = sortList[arg1];
}

void MainWindow::on_tableWidget_cellClicked(int row, int column)
{
    if(ui->tableWidget->item(row, column) != nullptr)
    {
        labels[column]->setText(QString::number(currentSort(array[column], NUM_OF_COLS)));
        fillTable(ui->tableWidget, array);
    }
}
