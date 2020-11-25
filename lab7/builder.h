#ifndef BUILDER_H
#define BUILDER_H
#include "robot.h"

class RobotBuilder
{
public:
    virtual void BuildHead() = 0;
    virtual void BuildBody() = 0;
    virtual void BuildEngine() = 0;
    virtual Robot* GetResult() = 0;

    virtual ~RobotBuilder() { }
};


class ArmoredRobotBuilder : public RobotBuilder
{
    Robot* robot;
public:
    ArmoredRobotBuilder()
    {
        robot = new Robot();
    }

    void BuildBody() override
    {
        Body* body = new Body();
        body->name = "Mk 65";
        body->armour = 1034;
        robot->AddModule(body);
    }

    void BuildHead() override
    {
        Head* body = new Head();
        body->name = "Simple nn";
        body->inteligense = 10;
        robot->AddModule(body);
    }

    void BuildEngine() override
    {
        Engine* body = new Engine();
        body->name = "W engine";
        body->power = 105;
        robot->AddModule(body);
    }

    Robot* GetResult() override
    {
        return robot;
    }

    ~ArmoredRobotBuilder() override
    {
        delete robot;
    }
};



class StaticRobotBuilder : public RobotBuilder
{
    Robot* robot;
public:
    StaticRobotBuilder()
    {
        robot = new Robot();
    }

    void BuildBody() override
    {
        Body* body = new Body();
        body->name = "Mk 181";
        body->armour = 10000;
        robot->AddModule(body);
    }

    void BuildHead() override
    {
        Head* body = new Head();
        body->name = "Conv nn";
        body->inteligense = 10;
        robot->AddModule(body);
    }

    void BuildEngine() override { }

    Robot* GetResult() override
    {
        return robot;
    }

    ~StaticRobotBuilder() override
    {
        delete robot;
    }
};

class Engineer
{
    RobotBuilder* builder;
public:
    Engineer(RobotBuilder* builder)
    {
        this->builder = builder;
    }

    void Construct()
    {
        builder->BuildBody();
        builder->BuildHead();
        builder->BuildEngine();
    }
};

#endif // BUILDER_H
