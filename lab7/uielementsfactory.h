#ifndef UIELEMENTSFACTORY_H
#define UIELEMENTSFACTORY_H
#include <QListView>
#include <QPushButton>
#include <QTextEdit>
#include <QTextCodec>

#include "abstractfactory.h"
#include "uielements.h"

class UiElementsFactory : public AbstractFactory
{
    UiElementsFactory() { }
public:

    static UiElementsFactory* GetInstance()
    {
       static UiElementsFactory* instance = new UiElementsFactory();
       return instance;
    }

    AbstractList * CreateMyList() const override
    {
        return new UiList();
    }

    AbstractInput * CreateMyInput() const override
    {
        return new UiInput();
    }

    AbstractLanguage * CreateMyLanguage() const override
    {
        return new UiLanguage();
    }

    AbstractPushButton * CreateMyButton() const override
    {
        return  new UiPushButton();
    }
};

#endif // UIELEMENTSFACTORY_H
