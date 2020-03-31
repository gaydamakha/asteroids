#ifndef VEC2_IMPL_H
#define VEC2_IMP_H

#include <math.h>
#include "vec2.h"
#include "trigonometry.h"

template<typename T>
Vec2<T> Vec2<T>::rotate(const Vec2<T>& center, double rotangle)
{
    long double s = sind(rotangle);
    long double c = cosd(rotangle);

    //translate to origin
	*this -= center;

    //rotate
    x = (x * c) - (y * s);
    y = (x * s) + (y * c);

    //translate to origin
	*this += center;

    return *this;
}

#endif