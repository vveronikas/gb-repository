#pragma once

#include "DynamicObject.h"
#include "Visitor.h"

class Bomb : public DynamicObject
{
public:
	Bomb() = default;
	Bomb(Bomb* b);

	static const uint16_t BombCost = 10; // стоимость бомбы в очках

	void Draw() const override;
	void Accept(Visitor& v) override { v.Visit(this); };
	Bomb* Clone() const { return new Bomb(*this); }

private:

};

