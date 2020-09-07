#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    task1 = new Task1(this);
    task2 = new Task2(this);
    task1->hide();
    task2->hide();
}

MainWindow::~MainWindow()
{
    delete task1;
    delete task2;
    delete ui;
}

void MainWindow::on_task1_clicked()
{
    task2->hide();
    task1->show();
    ui->mainWidget->addWidget(task1);
}

void MainWindow::on_task2_clicked()
{
    task1->hide();
    task2->show();
    ui->mainWidget->addWidget(task2);
}

