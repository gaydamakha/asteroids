#include "vec2.h"
#include "trigonometry.h"

template<typename T>
Vec2<T> Vec2<T>::turn(const Vec2<T>& center, double rotangle)
{
    double s = sind(d2r(rotangle));
    double c = cosd(d2r(rotangle));

	// Vec2<T> copy = *this;
    //translate to origin
	*this -= center;

    //rotate
    x = (x * c) - (y * s);
    y = (x * s) + (y * c);

    //translate to origin
	*this += center;

    return *this;
}