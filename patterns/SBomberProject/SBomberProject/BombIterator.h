#pragma once
#include "DynamicObject.h"
#include "Bomb.h"


class IIterator
{
public:
    virtual bool hasNext() const = 0;
    virtual DynamicObject* next() = 0;
    virtual ~IIterator() {};
};

class BombIterator : public IIterator
{
public:
    BombIterator(const std::vector<DynamicObject*>& vecBombs) : bombs(vecBombs) {}
    bool hasNext() const override
    {
        return position < bombs.size();
    }

    DynamicObject* next() override
    {
        Bomb* bomb = new Bomb;
        bomb = dynamic_cast<Bomb*>(bombs[position++]);
        return bomb;
    }
private:
    std::vector<DynamicObject*> bombs;
    size_t position = 0;
};