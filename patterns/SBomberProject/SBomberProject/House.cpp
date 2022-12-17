
#include <iostream>

#include "House.h"
#include "MyTools.h"

using namespace std;
using namespace MyTools;

bool House::isInside(double x1, double x2) const
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

void House::Draw() const
{
	MyTools::SetColor(CC_Yellow);

	HouseDirector hd;
	HouseBuilderA houseA;
	HouseBuilderB houseB;
	hd.DrawHouse(houseB);
}

void HouseBuilder::CreateHouse()
{
	h = new House;
	h->SetWidth(13);
	h->SetPos(80, GetMaxY() - 6);
};

void HouseBuilderA::CreateFirstFloorWithWindow()
{
	GotoXY(h->GetX(), h->GetY() - 3);
	cout << "############";
	GotoXY(h->GetX(), h->GetY() - 2);
	cout << "#          #";
	GotoXY(h->GetX(), h->GetY() - 1);
	cout << "#          #";
	GotoXY(h->GetX(), h->GetY());
	cout << "############";
};

void HouseBuilderA::CreatePipe()
{
	GotoXY(h->GetX(), h->GetY() - 5);
	cout << "  ########  ";
	GotoXY(h->GetX(), h->GetY() - 4);
	cout << "##        ##";
};

void HouseBuilderB::CreateFirstFloor()
{
	GotoXY(h->GetX(), h->GetY() - 3);
	cout << "############";
	GotoXY(h->GetX(), h->GetY() - 2);
	cout << "############";
	GotoXY(h->GetX(), h->GetY() - 1);
	cout << "############";
	GotoXY(h->GetX(), h->GetY());
	cout << "############";
};

void HouseBuilderB::CreatePipe()
{
	GotoXY(h->GetX(), h->GetY() - 5);
	cout << "  ########  ";
	GotoXY(h->GetX(), h->GetY() - 4);
	cout << "############";
};