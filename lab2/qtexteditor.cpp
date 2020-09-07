#include "qtexteditor.h"
#include "ui_qtexteditor.h"

QTextEditor::QTextEditor(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::QTextEditor)
{
    ui->setupUi(this);
}

QTextEditor::~QTextEditor()
{
    delete ui;
}

