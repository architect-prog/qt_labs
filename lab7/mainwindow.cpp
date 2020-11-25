#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "abstractfactory.h"
#include "uielementsfactory.h"
#include "uielements.h"
#include "abstractuielements.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    AbstractList *list = UiElementsFactory::GetInstance()->CreateMyList();
    AbstractPushButton *button = UiElementsFactory::GetInstance()->CreateMyButton();
    AbstractInput *input = UiElementsFactory::GetInstance()->CreateMyInput();
    AbstractLanguage *language = UiElementsFactory::GetInstance()->CreateMyLanguage();

    button->Element()->setText("button");

    ui->gridLayout->addWidget(button->Element());
    ui->gridLayout->addWidget(list->Element());
    ui->gridLayout->addWidget(input->Element());
    QTextCodec::setCodecForLocale(language->Element());
}

MainWindow::~MainWindow()
{
    delete ui;
}

