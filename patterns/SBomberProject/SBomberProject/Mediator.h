#pragma once
#include <vector>
#include "Tank.h"
#include <string>

class Mediator
{
public:
    void AddTank(TankAdapter* tank) { tanks.push_back(tank); }
    void Notify(std::string m)
    {
        for (auto tank : tanks)
        {
            tank->DrawMessage(m);
        }
    }
private:
    std::vector<TankAdapter*> tanks;
};