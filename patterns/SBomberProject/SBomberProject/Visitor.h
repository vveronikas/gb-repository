#pragma once

class Bomb;
class Plane;

class Visitor
{
public:
	virtual void Visit(Plane* p) = 0;
	virtual void Visit(Bomb* b) = 0;
};