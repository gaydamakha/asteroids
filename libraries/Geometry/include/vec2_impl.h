#ifndef VEC2_IMPL_H
#define VEC2_IMP_H

#include <math.h>
#include "vec2.h"
#include "trigonometry.h"

template<typename T>
Vec2<T> Vec2<T>::rotate(const Vec2<T>& center, double rotangle)
{
    double s = sind(rotangle);
    double c = cosd(rotangle);

    //translate to origin
	*this -= center;
    
    double init_length = this->getLength();
    
    //rotate
    x = (x * c) - (y * s);
    y = (x * s) + (y * c);
    
    // Rescale to get rid of the calc error
    // What is going on:
    // q = init_length / new_length;
    // *this *= q;
    *this *= init_length / this->getLength();

    //translate to origin
	*this += center;

    return *this;
}

template<typename T>
double angle_b_2vec(Vec2<T> v1, Vec2<T> v2)
{
  Vec2<T> product = (v1*v2);
	double dot_product = product.getX() + product.getY();

	return r2d(acosf64(dot_product/(v1.getLength()* v2.getLength())));
}

template<typename T>
Vec2<T> Vec2<T>::normalize()
{
    *this /= this->getLength();
    return *this;
}


template<typename T>
Vec2<T> normalize(Vec2<T> v)
{
    return v / v.getLength();
}

#endif