#ifndef TRG_H
#define TRG_H

const double PI = 4.0 * atan(1.0);

inline static double d2r(double d) {
  return (d / 180.0) * M_PI;
}

double sind(double x);

double cosd(double x);

#endif