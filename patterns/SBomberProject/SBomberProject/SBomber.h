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

    void AnimateScrolling();

private:
    SBomberImpl* bImpl;
};

static const size_t ScrollHeight = 30;
static const size_t ScrollWidth = 30;
static const char* ppScroll[ScrollHeight] =
{ "                    ",
  "                    ",
  "                    ",
  "                    ",
  "                    ",
  "                    ",
  "                    ",
  "                    ",
  "                    ",
  "                       Project manager:   ",
  "                       Ivan Vasilevich    ",
  "                    ",
  "                          Developers:        ",
  "                       Nikolay Gavrilov   ",
  "                       Dmitriy Sidelnikov ",
  "                       Eva Brown          ",
  "                    ",
  "                          Designers:         ",
  "                       Anna Pachenkova    ",
  "                       Elena Shvaiber     ",
  "                    ",
  "                    ",
  "                    ",
  "                    ",
  "                    ",
  "                    ",
  "                    ",
  "                    ",
  "                    ",
 "                     "};