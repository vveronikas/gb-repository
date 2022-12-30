#pragma once

#include <stdint.h>
#include "GameObject.h"
#include "Visitor.h"

class DynamicObject : public GameObject 
{
public:

    DynamicObject() : speed(0.0), xDirction(0.0), yDirection(0) { }

    inline void SetSpeed(double sp) { speed = sp; }
    inline void SetDirection(double dx, double dy) { xDirction = dx; yDirection = dy; }
	inline double GetSpeed() { return speed; };
	inline std::pair<double, double> GetDirection() { return { xDirction, yDirection }; };

	virtual void Accept(class Visitor& v) = 0;
    
    virtual void Move(uint16_t time) { x += xDirction * speed * time * 0.001; y += yDirection * speed * time * 0.001; };

protected:

    double speed;
    double xDirction, yDirection;
};