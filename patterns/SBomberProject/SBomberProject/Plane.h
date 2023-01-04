#pragma once

#include "DynamicObject.h"
#include "Visitor.h"

class Plane : public DynamicObject {
public:

    void Draw() const override final;
    virtual void DrawBody() const = 0;
    virtual void DrawWings() const = 0;
    virtual void DrawTail() const = 0;

    inline void ChangePlaneY(double dy) { yDirection += dy; };
    void Accept(Visitor& v) override { v.Visit(this); };

private:

};

class ColorPlane : public Plane
{
    void DrawBody() const override;
    void DrawWings() const override;
    void DrawTail() const override;
};

class BigPlane : public Plane
{
    void DrawBody() const override;
    void DrawWings() const override;
    void DrawTail() const override;
};

