#ifndef UIELEMENTS_H
#define UIELEMENTS_H
#include <QListView>
#include <QPushButton>
#include <QTextEdit>
#include <QTextCodec>

#include "abstractuielements.h"


class UiList : public AbstractList
{
public:
    UiList()
    {
        list = Construct();
    }
protected:
    QListView* Construct() override
    {
        return new QListView();
    }
};

class UiInput : public AbstractInput
{
public:
    UiInput()
    {
        input = Construct();
    }
protected:
    QTextEdit* Construct() override
    {
        return new QTextEdit();
    }
};

class UiPushButton : public AbstractPushButton
{
public:
    UiPushButton()
    {
        button = Construct();
    }
protected:
    QPushButton* Construct() override
    {
        return new QPushButton();
    }
};

class UiLanguage : public AbstractLanguage
{
public:
    UiLanguage()
    {
        language = Construct();
    }
protected:
    QTextCodec* Construct() override
    {
        return QTextCodec::codecForName("cp866");
    }
};


#endif // UIELEMENTS_H
