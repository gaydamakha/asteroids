#include <math.h>
#include "trigonometry.h"

double sind(double x) {
  if (!isfinite(x)) {
    return sin(x);
  }
  if (x < 0.0) {
    return -sind(-x);
  }
  int quo;
  double x90 = remquo(fabs(x), 90.0, &quo);
  switch (quo % 4) {
    case 0:
      // Use * 1.0 to avoid -0.0
      return sin(d2r(x90)* 1.0);
    case 1:
      return cos(d2r(x90));
    case 2:
      return sin(d2r(-x90) * 1.0);
    case 3:
      return -cos(d2r(x90));
  }
  return 0.0;
}

double cosd(double x) {
    return sqrtf64(1 - powf64(sind(x), 2));
}
