#include "mainwindow.h"

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

    RobotBuilder* builder = new StaticRobotBuilder();
    Engineer director(builder);
    director.Construct();

    robot = builder->GetResult();

    ui->roboInfo->setText(robot->GetInfo());
}

MainWindow::~MainWindow()
{
    delete robot;
    delete ui;
}

