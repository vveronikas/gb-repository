
#include <conio.h>
#include <windows.h>

#include "MyTools.h"
#include "SBomber.h"
#include "Bomb.h"
#include "Ground.h"
#include "Tank.h"
#include "House.h"
#include "LogVisitor.h"
#include "Command.cpp"
#include "Mediator.h"
#include "SBomberImpl.cpp"

using namespace std;
using namespace MyTools;

void SBomber::MoveObjects()
{
    MyTools::FileLoggerSingletone* logger = MyTools::FileLoggerSingletone::GetInstance();
    logger->WriteToLog(string(__FUNCTION__) + " was invoked");

    for (size_t i = 0; i < bImpl->vecDynamicObj.size(); i++)
    {
        if (bImpl->vecDynamicObj[i] != nullptr)
        {
            LogVisitor v;
            bImpl->vecDynamicObj[i]->Move(bImpl->deltaTime);
            bImpl->vecDynamicObj[i]->Accept(v);
        }
    }
};

void SBomber::CheckObjects()
{
    MyTools::FileLoggerSingletone* logger = MyTools::FileLoggerSingletone::GetInstance();
    logger->WriteToLog(string(__FUNCTION__) + " was invoked");

    bImpl->CheckPlaneAndLevelGUI();
    bImpl->CheckBombsAndGround();
};


void SBomber::ProcessKBHit()
{
    DoCommand command;
    int c = _getch();

    if (c == 224)
    {
        c = _getch();
    }

    MyTools::FileLoggerSingletone* logger = MyTools::FileLoggerSingletone::GetInstance();
    logger->WriteToLog(string(__FUNCTION__) + " was invoked. key = ", c);

    switch (c) {

    case 27: // esc
        bImpl->exitFlag = true;
        break;

    case 72: // up
        bImpl->FindPlane()->ChangePlaneY(-0.25);
        break;

    case 80: // down
        bImpl->FindPlane()->ChangePlaneY(0.25);
        break;

    case 'b':
        command.DropBomb(bImpl->vecDynamicObj, bImpl->bombsNumber, bImpl->score, bImpl->FindPlane());
        break;

    case 'B':
        command.DropBomb(bImpl->vecDynamicObj, bImpl->bombsNumber, bImpl->score, bImpl->FindPlane());
        break;

    default:
        break;
    }
}

void SBomber::DrawFrame()
{
    MyTools::FileLoggerSingletone* logger = MyTools::FileLoggerSingletone::GetInstance();
    logger->WriteToLog(string(__FUNCTION__) + " was invoked");
    for (size_t i = 0; i < bImpl->vecDynamicObj.size(); i++)
    {
        if (bImpl->vecDynamicObj[i] != nullptr)
        {
            bImpl->vecDynamicObj[i]->Draw();
        }
    }

    for (size_t i = 0; i < bImpl->vecStaticObj.size(); i++)
    {
        if (bImpl->vecStaticObj[i] != nullptr)
        {
            bImpl->vecStaticObj[i]->Draw();
        }
    }

    GotoXY(0, 0);
    bImpl->fps++;

    bImpl->FindLevelGUI()->SetParam(bImpl->passedTime, bImpl->fps, bImpl->bombsNumber, bImpl->score);
}

void SBomber::TimeStart()
{
    MyTools::FileLoggerSingletone* logger = MyTools::FileLoggerSingletone::GetInstance();
    logger->WriteToLog(string(__FUNCTION__) + " was invoked");
    bImpl->startTime = GetTickCount64();
}

void SBomber::TimeFinish()
{
    bImpl->finishTime = GetTickCount64();
    bImpl->deltaTime = uint16_t(bImpl->finishTime - bImpl->startTime);
    bImpl->passedTime += bImpl->deltaTime;

    MyTools::FileLoggerSingletone* logger = MyTools::FileLoggerSingletone::GetInstance();
    logger->WriteToLog(string(__FUNCTION__) + " deltaTime = ", (int)bImpl->deltaTime);
}