
#include <iostream>

#include "Tank.h"
#include "MyTools.h"

using namespace std;
using namespace MyTools;

bool TankAdaptee::isInRange(double x1, double x2) const
{
	const double XBeg = x + 2;
	const double XEnd = x + width - 1;

	if (x1 < XBeg && x2 > XEnd)
	{
		return true;
	}

	if (x1 > XBeg && x1 < XEnd)
	{
		return true;
	}

	if (x2 > XBeg && x2 < XEnd)
	{
		return true;
	}

	return false;
}

void TankAdaptee::Paint() const
{
	MyTools::SetColor(CC_Brown);
	GotoXY(x, y - 3);
	cout << "    #####";
	GotoXY(x - 2, y - 2);
	cout << "#######   #";
	GotoXY(x, y - 1);
	cout << "    #####";
	GotoXY(x, y);
	cout << " ###########";
}

void TankAdapter::SetPos(double nx, double ny)
{
    tank.SetPos(nx, ny);
}

uint16_t TankAdapter::GetWidth() const
{
    return tank.GetWidth();
}

void TankAdapter::Draw() const
{
    tank.Paint();
}

bool __fastcall TankAdapter::isInside(double x1, double x2) const
{
    return tank.isInRange(x1, x2);
}

double TankAdapter::GetY() const
{
    return tank.GetY();
}

double TankAdapter::GetX() const
{
    return tank.GetX();
}

void TankAdapter::SetWidth(uint16_t widthN)
{
    tank.GetWidth();
}

uint16_t TankAdapter::GetScore() const
{
    return tank.GetScore();
}