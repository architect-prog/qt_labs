#ifndef ABSTRACTUIELEMENTS_H
#define ABSTRACTUIELEMENTS_H
#include <QListView>
#include <QPushButton>
#include <QTextEdit>
#include <QTextCodec>

class AbstractList
{
public:
    QListView* Element()
    {
        return list;
    }
protected:
    QListView* list;
    virtual QListView* Construct() = 0;
};

class AbstractInput
{
public:
    QTextEdit* Element()
    {
        return input;
    }
protected:
    QTextEdit* input;
    virtual QTextEdit* Construct() = 0;
};


class AbstractPushButton
{
public:
    QPushButton* Element()
    {
        return button;
    }
protected:
    QPushButton* button;
    virtual QPushButton* Construct() = 0;
};


class AbstractLanguage
{
public:
    QTextCodec* Element()
    {
        return language;
    }
protected:
    QTextCodec* language;
    virtual QTextCodec* Construct() = 0;
};


#endif // ABSTRACTUIELEMENTS_H
