#include "interface/components/button.h"

Button::Button(const Vec2d &pos, const Color &c, double x, double y) : RectangleCollider(pos, x, y), color(c) {}

Button::Button(const Vec2d &pos, const Color &c, double x, double y, std::string text) : Button(pos, c, x, y)
{
    this->text = text;
}

bool Button::isPressed(double x, double y)
{
    return this->isInside(Vec2d(x, y));
}

double Button::getWidth() const
{
    auto rec = std::static_pointer_cast<Rectangle>(this->shape);
    return rec->getWidth();
}

double Button::getHeight() const
{
    auto rec = std::static_pointer_cast<Rectangle>(this->shape);
    return rec->getHeight();
}
