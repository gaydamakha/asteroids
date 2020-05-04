#include <cmath>
#include "trigonometry.h"

double sind(double x)
{
    if (!std::isfinite(x))
    {
        return sin(x);
    }
    if (x < 0.0)
    {
        return -sind(-x);
    }
    int quo;
    double res;
    double x90 = remquo(x, 90.0, &quo);
    switch (quo % 4)
    {
    case 0:
        res = sin(d2r(x90));
        break;
    case 1:
        res = cos(d2r(x90));
        break;
    case 2:
        res = -sin(d2r(x90));
        break;
    case 3:
        res = -cos(d2r(x90));
        break;
    default:
        return 0.0;
    }
    if (res == -0.0)
    {
        res = 0.0;
    }

    return res;
}

double cosd(double x)
{
    if (!std::isfinite(x))
    {
        return cos(x);
    }
    if (x < 0.0)
    {
        return cosd(-x);
    }
    int quo;
    double res;
    double x90 = remquo(x, 90.0, &quo);
    switch (quo % 4)
    {
    case 0:
        res = cos(d2r(x90));
        break;
    case 1:
        res = -sin(d2r(x90));
        break;
    case 2:
        res = -cos(d2r(x90));
        break;
    case 3:
        res = sin(d2r(x90));
        break;
    default:
        return 0.0;
    }
    if (res == -0.0)
    {
        res = 0.0;
    }

    return res;
}


bool isPointOnLeft(const Vec2d &p, const Vec2d &v1, const Vec2d &v2)
{
    return ((v2.getX() - v1.getX()) * (p.getY() - v1.getY()) - (p.getX() - v1.getX()) * (v2.getY() - v1.getY())) >= 0;
}