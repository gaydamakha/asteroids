#ifndef BUTTON_H
#define BUTTON_H

#include <string>
#include <Geometry.h>
#include <Utils.h>

class Button : public RectangleCollider
{
    const Color color;
    std::string text;

public:
    Button(const Vec2d &, const Color &, double x, double y);
    Button(const Vec2d &, const Color &, double x, double y, std::string);

    virtual bool isPressed(double x, double y);
    inline const Color& getColor() const { return color; }
    inline const std::string getText() const { return text; }
    double getWidth() const;
    double getHeight() const;
};

#endif