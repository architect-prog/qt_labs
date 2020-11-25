#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H

#include "abstractuielements.h"

class AbstractFactory
{
public:
    AbstractFactory() {};
    virtual AbstractList* CreateMyList() const = 0;
    virtual AbstractInput* CreateMyInput() const = 0;
    virtual AbstractPushButton* CreateMyButton() const = 0;
    virtual AbstractLanguage* CreateMyLanguage() const = 0;
};

#endif // ABSTRACTFACTORY_H
