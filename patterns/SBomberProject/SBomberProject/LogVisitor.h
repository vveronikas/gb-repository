#pragma once

#include "DynamicObject.h"
#include "Plane.h"
#include "Bomb.h"
#include "MyTools.h"
#include "Visitor.h"

class LogVisitor : public Visitor
{
public:
	void Visit(Plane* p) override
	{
		MyTools::FileLoggerSingletone* logger = MyTools::FileLoggerSingletone::GetInstance();
		logger->WriteToLog("Plane speed: ", p->GetSpeed());
		std::pair<double, double> xy = p->GetDirection();
		logger->WriteToLog("Plane x: ", xy.first);
		logger->WriteToLog("Plane y: ", xy.second);
	};

	void Visit(Bomb* b) override
	{
		MyTools::FileLoggerSingletone* logger = MyTools::FileLoggerSingletone::GetInstance();
		logger->WriteToLog("Bomb speed: ", b->GetSpeed());
		std::pair<double, double> xy = b->GetDirection();
		logger->WriteToLog("Bomb x: ", xy.first);
		logger->WriteToLog("Bomb y: ", xy.second);
	};
};