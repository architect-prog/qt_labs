#include "qtexteditor.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextEditor w;
    w.show();
    return a.exec();
}
