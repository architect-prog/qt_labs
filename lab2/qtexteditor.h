#ifndef QTEXTEDITOR_H
#define QTEXTEDITOR_H

#include <QMainWindow>
#include <QMessageBox>
#include <QCloseEvent>
#include <QFontDialog>
#include <QSettings>
#include <QString>
#include <QFileInfo>
#include <QFileDialog>
#define VIEW_FONT "viewFont"

QT_BEGIN_NAMESPACE
namespace Ui { class QTextEditor; }
QT_END_NAMESPACE

class QTextEditor : public QMainWindow
{
    Q_OBJECT

public:
    QTextEditor(QWidget *parent = nullptr, const QString &fileName=QString());
    ~QTextEditor();

private slots:
    void on_actionNew_triggered();
    void on_actionClose_triggered();
    void on_actionExit_triggered();
    void on_actionSelect_Font_triggered();
    void on_actionAbout_triggered();
    void on_actionAbout_Qt_triggered();
    void on_actionCut_triggered();
    void on_actionCopy_triggered();
    void on_actionPaste_triggered();
    void on_actionUndo_triggered();
    void on_actionRedo_triggered();
    void on_actionOpen_triggered();
    bool saveFile();
    bool saveFileAs();
    void onDocumentModified();


private:
    void loadFile(const QString &fileName);
    void setFileName(const QString &fileName);

    Ui::QTextEditor *ui;
    QString fileName;
protected:
    void closeEvent(QCloseEvent *e);
};
#endif // QTEXTEDITOR_H
