#include "Command.h"


void DeleteDynamicObjCommand::Execute()
{
    auto it = vecDynamicObj.begin();
    for (; it != vecDynamicObj.end(); it++)
    {
        if (*it == obj)
        {
            vecDynamicObj.erase(it);
            break;
        }
    }
}

void DeleteStaticObjCommand::Execute()
{
    auto it = vecStaticObj.begin();
    for (; it != vecStaticObj.end(); it++)
    {
        if (*it == obj)
        {
            vecStaticObj.erase(it);
            break;
        }
    }
}

void DropBombCommand::Execute()
{
    if (bombsNumber > 0)
    {
        MyTools::FileLoggerSingletone* logger = MyTools::FileLoggerSingletone::GetInstance();
        logger->WriteToLog(std::string(__FUNCTION__) + " was invoked");

        double x = plane->GetX() + 4;
        double y = plane->GetY() + 2;

        Bomb* pBomb = new Bomb;
        pBomb->SetDirection(0.3, 1);
        pBomb->SetSpeed(2);
        pBomb->SetPos(x, y);
        pBomb->SetWidth(SMALL_CRATER_SIZE);

        vecDynamicObj.push_back(pBomb);
        bombsNumber--;
        score -= Bomb::BombCost;
    }
}

void DoCommand::DeleteStaticObj(GameObject* object, std::vector<GameObject*>& vector)
{
    command = new DeleteStaticObjCommand(object, vector);
    command->Execute();
    doneCommands.push_back(command);
}

void DoCommand::DeleteDynamicObj(DynamicObject* object, std::vector<DynamicObject*>& vector)
{
    command = new DeleteDynamicObjCommand(object, vector);
    command->Execute();
    doneCommands.push_back(command);
}

void DoCommand::DropBomb(std::vector<DynamicObject*>& vector, const uint16_t& number, const int16_t& sc, Plane* plane)
{
    command = new DropBombCommand(vector, number, sc, plane);
    command->Execute();
    doneCommands.push_back(command);
}