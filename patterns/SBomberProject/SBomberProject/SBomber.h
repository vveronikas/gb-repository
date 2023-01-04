#pragma once

#include <vector>

#include "LevelGUI.h"
#include "Plane.h"
#include "Bomb.h"
#include "Ground.h"
#include "Tank.h"
#include "MyTools.h"
#include "Command.h"
#include "BombIterator.h"
#include "SBomberImpl.h"

class SBomber
{
public:

    SBomber() : bImpl(new SBomberImpl()) {};
    ~SBomber() { delete bImpl; }
    
    inline bool GetExitFlag() const { return bImpl->exitFlag; }

    void ProcessKBHit();
    void TimeStart();
    void TimeFinish();

    void DrawFrame();
    void MoveObjects();
    void CheckObjects();

private:
    SBomberImpl* bImpl;
};