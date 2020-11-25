#ifndef ROBOT_H
#define ROBOT_H
#include <QString>
#include <QVector>

struct Module
{
    QString name;
    virtual QString ToString()
    {
        return "Module name: " + name;
    }
};

struct Engine : public Module
{
    double power;
    QString ToString() override
    {
        QString result = Module::ToString();
        return result + " Engine power: " + QString::number(power);
    }
};

struct Head : public Module
{
    double inteligense;
    QString ToString() override
    {
        QString result = Module::ToString();
        return result + " Head inteligense: " + QString::number(inteligense);
    }
};

struct Body : public Module
{
    double armour;
    QString ToString() override
    {
        QString result = Module::ToString();
        return result + " Body armour: " + QString::number(armour);
    }
};

class Robot
{
    QVector<Module*>* modules;
public:
    Robot()
    {
        modules = new QVector<Module*>();
    }

    void AddModule(Module *module)
    {
        modules->push_back(module);
    }

    QString GetInfo()
    {
        QString result;
        for (Module* module: *modules)
        {
            result += module->ToString() + "\n";
        }
        return result;
    }

    ~Robot()
    {
        delete modules;
    }
};


#endif // ROBOT_H
