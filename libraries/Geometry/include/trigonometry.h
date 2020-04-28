#ifndef TRG_H
#define TRG_H

const double PI = 4.0 * atan(1.0);
const double d2rk = PI / 180.0;
const double r2dk = 180.0 / PI;

inline static double d2r(double d)
{
    return d * d2rk;
}

inline static double r2d(double r)
{
    return r * r2dk;
}

double sind(double x);

double cosd(double x);

#endif