#pragma once

#include <stdint.h>

#include "DestroyableGroundObject.h"
#include "MyTools.h"

using namespace MyTools;
using namespace std;

class House : public DestroyableGroundObject
{
public:

	bool __fastcall isInside(double x1, double x2) const override;

	inline uint16_t GetScore() const override { return score; }

	void Draw() const override;

private:

	const uint16_t score = 40;
};

class HouseBuilder
{
public:
	virtual ~HouseBuilder() { delete h; };
	virtual void CreateFirstFloor() {};
	virtual void CreateFirstFloorWithWindow() {};
	virtual void CreatePipe() {};
	virtual void CreateHouse();

	House* GetHouse() const { return h; };

protected:
	House* h = nullptr;
};

class HouseBuilderA : public HouseBuilder
{
public:
	void CreateFirstFloorWithWindow() override;
	void CreatePipe() override;
};

class HouseBuilderB : public HouseBuilder
{
public:
	void CreateFirstFloor() override;
	void CreatePipe() override;
};

class HouseDirector
{
public:
	void DrawHouse(HouseBuilder& builder)
	{
		builder.CreateHouse();
		builder.CreateFirstFloor();
		builder.CreateFirstFloorWithWindow();
		builder.CreatePipe();
	}
};