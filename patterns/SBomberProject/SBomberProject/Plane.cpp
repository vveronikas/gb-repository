
#include <iostream>

#include "Plane.h"
#include "MyTools.h"

using namespace std;
using namespace MyTools;

void Plane::Draw() const
{
    DrawBody();
    DrawTail();
    DrawWings();  
}

void ColorPlane::DrawBody() const
{
    MyTools::SetColor(CC_LightBlue);
    GotoXY(x, y);
    cout << "=========>";
}
void ColorPlane::DrawWings() const
{
    MyTools::SetColor(CC_LightGreen);
    GotoXY(x + 3, y - 1);
    cout << "\\\\\\\\";
    GotoXY(x + 3, y + 1);
    cout << "////";
}
void ColorPlane::DrawTail() const
{
    MyTools::SetColor(CC_LightRed);
    GotoXY(x - 2, y - 1);
    cout << "===";
}

void BigPlane::DrawBody() const
{
    MyTools::SetColor(CC_LightBlue);
    GotoXY(x, y);
    cout << "==================>";
}
void BigPlane::DrawWings() const
{
    MyTools::SetColor(CC_LightBlue);
    GotoXY(x + 3, y - 1);
    cout << "\\\\\\\\\\\\\\";
    GotoXY(x + 3, y + 1);
    cout << "////////";
}
void BigPlane::DrawTail() const
{
    MyTools::SetColor(CC_LightBlue);
    GotoXY(x - 2, y - 1);
    cout << "=======";
}
