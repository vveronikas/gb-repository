#pragma once
#include "SBomber.h"
#include "MyTools.h"

class ICommand
{
public:
    virtual ~ICommand() {};
    virtual void Execute() = 0;
};

class DeleteDynamicObjCommand : public ICommand
{
public:
    DeleteDynamicObjCommand(DynamicObject* object, std::vector<DynamicObject*>& vector) :
        obj(object), vecDynamicObj(vector) {};
    void Execute() override;

private:
    DynamicObject* obj;
    std::vector<DynamicObject*> vecDynamicObj;
};

class DeleteStaticObjCommand : public ICommand
{
public:
    DeleteStaticObjCommand(GameObject* object, std::vector<GameObject*>& vector) :
        obj(object), vecStaticObj(vector) {};
    void Execute() override;
private:
    GameObject* obj;
    std::vector<GameObject*> vecStaticObj;
};

class DropBombCommand : public ICommand
{
public:
    DropBombCommand(std::vector<DynamicObject*>& vector, const uint16_t& number, const int16_t& sc, Plane* p) :
        bombsNumber(number), vecDynamicObj(vector), score(sc), plane(p) {};
    void Execute() override;
protected:
    uint16_t bombsNumber;
    std::vector<DynamicObject*> vecDynamicObj;
    int16_t score;
    Plane* plane;
};

class DropBombAndCloneCommand : public DropBombCommand
{
public:
        DropBombAndCloneCommand(std::vector<DynamicObject*>& vector, const uint16_t& number, const int16_t& sc, Plane* p) :
        DropBombCommand(vector, number, sc, p) {};
    void Execute() override;
};

class DoCommand
{
public:
    DoCommand() : command(nullptr) {};
    ~DoCommand()
    {
        for (ICommand* ptr : doneCommands)
        {
            delete ptr;
        }
    };
    void DeleteStaticObj(GameObject* object, std::vector<GameObject*>& vector);
    void DeleteDynamicObj(DynamicObject* object, std::vector<DynamicObject*>& vector);
    void DropBomb(std::vector<DynamicObject*>& vector, const uint16_t& number, const int16_t& sc, Plane* plane);
    void DropBombAndClone(std::vector<DynamicObject*>& vector, const uint16_t& number, const int16_t& sc, Plane* plane);

private:
    std::vector<ICommand*> doneCommands;
    ICommand* command;
};