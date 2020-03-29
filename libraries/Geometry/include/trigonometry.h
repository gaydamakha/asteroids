#ifndef TRG_H
#define TRG_H

inline static double d2r(double d) {
  return (d / 180.0) * ((double) M_PI);
}

double sind(double x);

double cosd(double x);

double round2(double x);

#endif