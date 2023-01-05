
#include <iostream>

#include "Bomb.h"
#include "MyTools.h"

using namespace std;
using namespace MyTools;

void Bomb::Draw() const
{
    MyTools::SetColor(CC_LightMagenta);
    GotoXY(x, y);
    cout << "*";
}

Bomb::Bomb(Bomb* b)
{
	this->SetDirection(b->GetDirection().first, b->GetDirection().second);
	this->SetSpeed(b->GetSpeed());
	this->SetPos(b->GetPos().first + 2, b->GetPos().second);
	this->SetWidth(b->GetWidth());
}