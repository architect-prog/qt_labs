#include "qtexteditor.h"
#include "ui_qtexteditor.h"
#include <QtDebug>

QTextEditor::QTextEditor(QWidget *parent, const QString &fileName)
    : QMainWindow(parent)
    , ui(new Ui::QTextEditor)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);

    ui->actionCopy->setEnabled(false);
    ui->actionCut->setEnabled(false);
    ui->actionRedo->setEnabled(false);
    ui->actionUndo->setEnabled(false);

    connect(ui->textEdit, SIGNAL(textChanged()), this, SLOT(onDocumentModified()));

    connect(ui->textEdit, SIGNAL(copyAvailable(bool)), ui->actionCopy, SLOT(setEnabled(bool)));
    connect(ui->textEdit, SIGNAL(copyAvailable(bool)), ui->actionCut, SLOT(setEnabled(bool)));
    connect(ui->textEdit, SIGNAL(undoAvailable(bool)), ui->actionUndo, SLOT(setEnabled(bool)));
    connect(ui->textEdit, SIGNAL(redoAvailable(bool)), ui->actionRedo, SLOT(setEnabled(bool)));

    connect(ui->actionSave, SIGNAL(triggered()), this, SLOT(saveFile()));
    connect(ui->actionSave_As, SIGNAL(triggered()), this, SLOT(saveFileAs()));

    QFont font = QSettings(this).value(VIEW_FONT).value<QFont>();
    ui->textEdit->setFont(font);

    loadFile(fileName);
}

QTextEditor::~QTextEditor()
{
    delete ui;
}

void QTextEditor::on_actionNew_triggered()
{
    QTextEditor *newEditor = new QTextEditor();
    newEditor->show();
}

void QTextEditor::on_actionClose_triggered()
{
    this->close();
}

void QTextEditor::on_actionExit_triggered()
{
    qApp->closeAllWindows();
}

void QTextEditor::onDocumentModified()
{
    setWindowModified(true);
}

void QTextEditor::closeEvent(QCloseEvent *e)
{   
    if (isWindowModified())
    {
        switch (QMessageBox::warning(this,
                                     "Document was modified",
                                     "The document was modified. Do you want save your changes",
                                     QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel))
        {
        case QMessageBox::Yes:
            saveFile();
            e->ignore();
            break;
        case QMessageBox::No:
            e->accept();
            break;
        case QMessageBox::Cancel:
            e->ignore();
            break;       
        }
    }
    else    
        e->accept();    
}

void QTextEditor::on_actionSelect_Font_triggered()
{
    bool isChange;
    QFont newFont = QFontDialog::getFont(&isChange);
    if(isChange)
    {
        ui->textEdit->setFont(newFont);
        QSettings settings(this);
        settings.setValue(VIEW_FONT, newFont);
    }
}

void QTextEditor::on_actionAbout_triggered()
{
    QMessageBox::about(this, "About", "Qt text editor example");
}

void QTextEditor::on_actionAbout_Qt_triggered()
{
    qApp->aboutQt();
}

void QTextEditor::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

void QTextEditor::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void QTextEditor::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void QTextEditor::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void QTextEditor::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

void QTextEditor::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,
     "Open document", QDir::currentPath(), "Text documents (*.txt *.cpp *.h *.xml)");

    if(fileName.isNull())
        return;

    if((this->fileName.isEmpty() || this->fileName.isNull()) && !isWindowModified())    
        loadFile(fileName);    
    else
    {
        QTextEditor *newEditor = new QTextEditor(this, fileName);
        newEditor->show();
    }
}

bool QTextEditor::saveFile()
{
    if(this->fileName.isNull())
        return saveFileAs();
    else
    {
        QFile file(this->fileName);
        if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QMessageBox::warning(this,
                                 "Can't save file",
                                 "This file can't be saved");
            setFileName(QString());
            return false;
        }

        QTextStream stream(&file);
        stream << ui->textEdit->toPlainText();
        file.close();
        setWindowModified(false);
        return true;
    }
}

bool QTextEditor::saveFileAs()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save document",
                                                    this->fileName.isNull()?QDir::currentPath():this->fileName,
                                                    "Text documents (*.txt)");
    if(fileName.isNull())
        return false;
    else
    {
        setFileName(fileName);
        return saveFile();
    }
}

void QTextEditor::loadFile(const QString &fileName)
{
    if(fileName.isNull() || fileName.isEmpty())    
        setFileName(QString());    
    else
    {
        QFile file(fileName);
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QMessageBox::warning(this,
                                 "Can't open file",
                                 "This file can't be opened for reading");
            setFileName(QString());
            return;
        }
        QTextStream stream(&file);
        ui->textEdit->setText(stream.readAll());
        file.close();
        setFileName(fileName);
        setWindowModified(false);
    }

}

void QTextEditor::setFileName(const QString &fileName)
{
    this->fileName = fileName;
    setWindowTitle(QString("%1[*] - %2")
                   .arg(fileName.isNull()?"untitled":QFileInfo(fileName).fileName())
                   .arg(QApplication::applicationName()));
}
